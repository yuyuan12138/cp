class dsu {
	public:
		vector<int> pa;
		int n;

		dsu(int _n) : n(_n) {
			pa.resize(n);
			iota(pa.begin(), pa.end(), 0);
		}

		inline int get(int x) {
			return (x == pa[x] ? x : (pa[x] = get(pa[x])));
		}

		inline bool unite(int x, int y) {
			x = get(x);
			y = get(y);
			if (x != y) {
				pa[x] = y;	
				return true;
			}
			return false;
		}
};
