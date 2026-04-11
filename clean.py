from pathlib import Path
import shutil
from functools import partial

def delete_matching_items(root_dir: str, pattern: str, dry_run: bool = True):
    """
    Recursively delete files AND directories whose names match a glob pattern.

    Args:
        root_dir: Top-level directory to search.
        pattern: Glob pattern (e.g., "*.log", "__pycache__", "temp_*").
        dry_run: If True, only preview actions without deleting.
    """
    root = Path(root_dir).expanduser().resolve()

    if not root.exists():
        print(f"❌ Path '{root}' does not exist.")
        return
    if not root.is_dir():
        print(f"❌ '{root}' is not a directory.")
        return

    # Find all items (files + directories) that match the pattern
    # Note: rglob(pattern) matches the pattern against the name, not full path
    matched_items = list(root.rglob(pattern))

    if not matched_items:
        print(f"ℹ️ No items matching '{pattern}' found under '{root}'.")
        return

    # Process directories first (bottom‑up) to avoid deleting parents before children
    # (Though rmtree handles entire trees, sorting ensures we don't try to delete a child after parent is gone)
    dirs = [p for p in matched_items if p.is_dir()]
    files = [p for p in matched_items if p.is_file()]

    # Remove directories (entire subtree)
    for dir_path in sorted(dirs, key=lambda p: len(p.parts), reverse=True):
        if dry_run:
            print(f"[DRY RUN] Would delete directory: {dir_path}")
        else:
            try:
                shutil.rmtree(dir_path)
                print(f"🗂️ Deleted directory: {dir_path}")
            except Exception as e:
                print(f"⚠️ Error deleting directory {dir_path}: {e}")

    # Remove files
    for file_path in files:
        if dry_run:
            print(f"[DRY RUN] Would delete file: {file_path}")
        else:
            try:
                file_path.unlink()
                print(f"🗑️ Deleted file: {file_path}")
            except Exception as e:
                print(f"⚠️ Error deleting file {file_path}: {e}")

# ==================== EXAMPLES ====================
if __name__ == "__main__":
    target = "./"
    files = ['.DS_Store', '*.in', '*.out', '*tests', '*.bin', 'sol', 'in', 'main', 'output*']
    folders = ['.cph', '.cph-ng']
    delete = partial(delete_matching_items, target, dry_run=False)
    list(map(delete, files))
    list(map(delete, folders))