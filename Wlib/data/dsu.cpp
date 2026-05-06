class DSU {
  public:
    vector<int> pa;
    int n;

    DSU(int _n) : n(_n) {
        pa.resize(n);
        iota(pa.begin(), pa.end(), 0);
    }

    int get(int x) {
        return (x == pa[x] ? x : (pa[x] = get(pa[x])));
    }

    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            pa[x] = y;
            return true;
        }
        return false;
    }

    bool isSame(int x, int y) {
        return get(x) == get(y);
    }
};
