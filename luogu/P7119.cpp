#include <bits/stdc++.h>

template<class Info, class Tag>
struct LazySegmentTree {
  int n;
  std::vector<Info> info;
  std::vector<Tag> tag;
  LazySegmentTree() : n(0) {}
  LazySegmentTree(int n_, Info v_ = Info()) {
    init(n_, v_);
  }
  template<class T>
  LazySegmentTree(std::vector<T> init_) {
    init(init_);
  }
  void init(int n_, Info v_ = Info()) {
    init(std::vector(n_, v_));
  }
  template<class T>
  void init(std::vector<T> init_) {
    n = init_.size();
    info.assign(4 << std::__lg(n), Info());
    tag.assign(4 << std::__lg(n), Tag());
    std::function<void(int, int, int)> build = [&](int p, int l, int r) {
      if (r - l == 1) {
        info[p] = init_[l];
        return;
      }
      int m = (l + r) / 2;
      build(2 * p, l, m);
      build(2 * p + 1, m, r);
      pull(p);
    };
    build(1, 0, n);
  }
  void pull(int p) {
    info[p] = info[2 * p] + info[2 * p + 1];
  }
  void apply(int p, const Tag &v) {
    info[p].apply(v);
    tag[p].apply(v);
  }
  void push(int p) {
    apply(2 * p, tag[p]);
    apply(2 * p + 1, tag[p]);
    tag[p] = Tag();
  }
  void modify(int p, int l, int r, int x, const Info &v) {
    if (r - l == 1) {
      info[p] = v;
      return;
    }
    int m = (l + r) / 2;
    push(p);
    if (x < m) {
      modify(2 * p, l, m, x, v);
    } else {
      modify(2 * p + 1, m, r, x, v);
    }
    pull(p);
  }
  void modify(int p, const Info &v) {
    modify(1, 0, n, p, v);
  }
  Info rangeQuery(int p, int l, int r, int x, int y) {
    if (l >= y || r <= x) {
      return Info();
    }
    if (l >= x && r <= y) {
      return info[p];
    }
    int m = (l + r) / 2;
    push(p);
    return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
  }
  Info rangeQuery(int l, int r) {
    return rangeQuery(1, 0, n, l, r);
  }
  void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
    if (l >= y || r <= x) {
      return;
    }
    if (l >= x && r <= y) {
      apply(p, v);
      return;
    }
    int m = (l + r) / 2;
    push(p);
    rangeApply(2 * p, l, m, x, y, v);
    rangeApply(2 * p + 1, m, r, x, y, v);
    pull(p);
  }
  void rangeApply(int l, int r, const Tag &v) {
    return rangeApply(1, 0, n, l, r, v);
  }
  template<class F>
  int findFirst(int p, int l, int r, int x, int y, F &&pred) {
    if (l >= y || r <= x) {
      return -1;
    }
    if (l >= x && r <= y && !pred(info[p])) {
      return -1;
    }
    if (r - l == 1) {
      return l;
    }
    int m = (l + r) / 2;
    push(p);
    int res = findFirst(2 * p, l, m, x, y, pred);
    if (res == -1) {
      res = findFirst(2 * p + 1, m, r, x, y, pred);
    }
    return res;
  }
  template<class F>
  int findFirst(int l, int r, F &&pred) {
    return findFirst(1, 0, n, l, r, pred);
  }
  template<class F>
  int findLast(int p, int l, int r, int x, int y, F &&pred) {
    if (l >= y || r <= x) {
      return -1;
    }
    if (l >= x && r <= y && !pred(info[p])) {
      return -1;
    }
    if (r - l == 1) {
      return l;
    }
    int m = (l + r) / 2;
    push(p);
    int res = findLast(2 * p + 1, m, r, x, y, pred);
    if (res == -1) {
      res = findLast(2 * p, l, m, x, y, pred);
    }
    return res;
  }
  template<class F>
  int findLast(int l, int r, F &&pred) {
    return findLast(1, 0, n, l, r, pred);
  }
};

struct Tag {
  bool flip = false;
  void apply(const Tag &t) & {
  	flip ^= t.flip;
  }
};

struct Info {
  int l = 0, r = 0;
  int64_t sum_p = 0;
  int64_t sum_k = 0;
  void apply(const Tag &t) & {
  	if (t.flip) {
  		sum_p = int64_t(l + r) * (r - l + 1) / 2 - sum_p;
  		sum_k = r - l + 1 - sum_k;
  	}
  }
};

Info operator+(const Info &a, const Info &b) {
	Info c;
	c.l = a.l;
  c.r = b.r;
	c.sum_p = a.sum_p + b.sum_p;
	c.sum_k = a.sum_k + b.sum_k;
  return c;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::string s;
  std::cin >> s;
  std::vector<int> a(s.size());
  for (int i = 0; i < n; i++) {
  	a[i] = (s[i] == 'T' ? 1 : 0);
  }

  LazySegmentTree<Info, Tag> seg(n);
  for (int i = 0; i < n; i++) {
  	Info c;
  	c.l = i + 1, c.r = i + 1;
  	if (a[i] == 1) {
  		c.sum_p = i + 1;
  	}
  	c.sum_k = a[i];
  	seg.modify(i, c);
  }
	auto work = [&](const int l, const int r) {
		int64_t ans = 0;
		if (l <= r) {
			seg.rangeApply(l, r + 1, {true});
		} 
		Info res = seg.rangeQuery(0, n);
		ans += res.sum_p * 2 - res.sum_k * res.sum_k;
		std::cout << ans << '\n';
	};
	work(0, -1);
	while (m--) {
		int l, r;
		std::cin >> l >> r;
		l--, r--;
		work(l, r);
	} 
  return 0;
}