from pathlib import Path
import shutil

def main():
    exclude_dirs = {
        ".git",
        ".idea",
        ".vscode",
        "build",
        "__pycache__",
    }
    exclude_files = [".gitignore", 'generate_nvim_snippets.py']
    src_root = Path.cwd()
    dst_root = Path.home() / ".config" / "nvim" / "templates"
    for src in src_root.rglob("*"):
        if any(part in exclude_dirs for part in src.parts):
            continue
        if not src.is_file():
            continue
        if src.name in exclude_files: 
            continue
        rel = src.relative_to(src_root)
        dst = dst_root / rel
        dst = dst.with_suffix(".tpl")
        dst.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(src, dst)
    print("Done")

if __name__ == "__main__":
    main()
