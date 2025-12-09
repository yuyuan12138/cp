#include <bits/stdc++.h>
using namespace std;

// ------ Tag / Info （按你的 LazySegmentTree 模板语义实现） ------
struct Tag {
  int assign = -1; // -1: none, 0: assign empty (cut), 2: assign all seed
  bool plant = false; // convert empty -> seed

  // compose: 'this' is older tag, t is new tag (apply old then new)
  void apply(const Tag &t) & {
    if (t.assign != -1) {
      // new assign overrides previous tags
      assign = t.assign;
      plant = t.plant;
      return;
    }
    if (t.plant) {
      if (assign == -1) {
        // no prior assign, just remember to plant empties later
        plant = true;
      } else if (assign == 0) {
        // prior assign to empty then plant => becomes assign all seed
        assign = 2;
        plant = false;
      } else if (assign == 2) {
        // already all seed, nothing to add
      }
    }
  }
};

struct Info {
  int seed = 0; // number of seedlings (planted)
  int orig = 0; // number of original trees
  int len = 0;  // interval length

  void apply(const Tag &t) & {
    if (t.assign != -1) {
      if (t.assign == 0) { // cut -> empty
        seed = 0;
        orig = 0;
      } else if (t.assign == 2) { // assign all seed
        seed = len;
        orig = 0;
      }
    }
    if (t.plant) {
      int empty = len - seed - orig;
      seed += empty;
    }
  }
};

Info operator+(const Info &a, const Info &b) {
  return {a.seed + b.seed, a.orig + b.orig, a.len + b.len};
}

// ------ 你的 LazySegmentTree 模板（保持原样，只使用上面的 Info/Tag） ------
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

// ------ main ------------
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int L, N;
  if (!(cin >> L >> N)) return 0;

  // 初始化每个叶子：len=1, orig=1（初始每个位置有原始成树）
  vector<Info> init(L + 1);
  for (int i = 0; i <= L; ++i) {
    init[i].seed = 0;
    init[i].orig = 1;
    init[i].len = 1;
  }

  LazySegmentTree<Info, Tag> seg(init);

  long long planted_then_cut = 0;

  for (int i = 0; i < N; ++i) {
    int op, a, b;
    cin >> op >> a >> b;
    int l = a, r = b + 1; // 模板用半开区间
    if (op == 0) {
      // 砍：先查询当前区间被种的苗数（它们会被砍掉，计入第二行答案）
      Info tmp = seg.rangeQuery(l, r);
      planted_then_cut += tmp.seed;
      Tag t;
      t.assign = 0; // assign empty
      t.plant = false;
      seg.rangeApply(l, r, t);
    } else {
      // 种：把空位变成 seed
      Tag t;
      t.assign = -1;
      t.plant = true;
      seg.rangeApply(l, r, t);
    }
  }

  Info res = seg.rangeQuery(0, L + 1);
  cout << res.seed << "\n" << planted_then_cut << "\n";
  return 0;
}
