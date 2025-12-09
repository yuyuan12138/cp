struct DSU {
  int n;
  std::vector<int> f, siz;
  int cnt;

  DSU() {}
  DSU(int n) {
    init(n);
  }

  void init(int n) {
    cnt = n;
    f.resize(n);
    std::iota(f.begin(), f.end(), 0);
    siz.assign(n, 1);
  }

  int find(int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  bool merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) {
      return false;
    }
    if (siz[x] < siz[y]) {
      std::swap(x, y);
    }
    f[y] = x;
    siz[x] += siz[y];
    cnt--;
    return true;
  }

  int size(int x) { return siz[find(x)]; }

  int count() { return cnt; }
} 