#include <bits/stdc++.h>

using i64 = long long;

int mod;

template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;

    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, const Info &v = Info()) { init(n_, v); }

    template<class T>
    LazySegmentTree(const std::vector<T> &init_) { init(init_); }

    void init(int n_, const Info &v = Info()) {
        assert(n_ >= 0);
        std::vector<Info> tmp(n_, v);
        init(tmp);
    }

    template<class T>
    void init(const std::vector<T> &init_) {
        n = (int)init_.size();
        if (n == 0) {
            info.clear();
            tag.clear();
            return;
        }
        info.assign(4 * n, Info());
        tag.assign(4 * n, Tag());

        std::function<void(int,int,int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) >> 1;
            build(p << 1, l, m);
            build(p << 1 | 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }

    void pull(int p) {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }

    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }

    void push(int p) {
        apply(p << 1, tag[p]);
        apply(p << 1 | 1, tag[p]);
        tag[p] = Tag();
    }

    void modify_point(int p, int l, int r, int pos, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) >> 1;
        push(p);
        if (pos < m) modify_point(p << 1, l, m, pos, v);
        else modify_point(p << 1 | 1, m, r, pos, v);
        pull(p);
    }

    void modify_point(int pos, const Info &v) {
        assert(0 <= pos && pos < n);
        modify_point(1, 0, n, pos, v);
    }

    Info rangeQuery(int p, int l, int r, int L, int R) {
        if (L >= r || R <= l) return Info();
        if (L <= l && r <= R) return info[p];
        int m = (l + r) >> 1;
        push(p);
        Info left = rangeQuery(p << 1, l, m, L, R);
        Info right = rangeQuery(p << 1 | 1, m, r, L, R);
        return left + right;
    }

    Info rangeQuery(int L, int R) {
        assert(0 <= L && L <= R && R <= n);
        if (L == R) return Info();
        return rangeQuery(1, 0, n, L, R);
    }

    void rangeApply(int p, int l, int r, int L, int R, const Tag &v) {
        if (L >= r || R <= l) return;
        if (L <= l && r <= R) {
            apply(p, v);
            return;
        }
        int m = (l + r) >> 1;
        push(p);
        rangeApply(p << 1, l, m, L, R, v);
        rangeApply(p << 1 | 1, m, r, L, R, v);
        pull(p);
    }

    void rangeApply(int L, int R, const Tag &v) {
        assert(0 <= L && L <= R && R <= n);
        if (L == R) return;
        rangeApply(1, 0, n, L, R, v);
    }

    template<class F>
    int findFirst(int p, int l, int r, int L, int R, F &&pred) {
        if (L >= r || R <= l) return -1;
        if (L <= l && r <= R && !pred(info[p])) return -1;
        if (r - l == 1) return l;
        int m = (l + r) >> 1;
        push(p);
        int res = findFirst(p << 1, l, m, L, R, std::forward<F>(pred));
        if (res != -1) return res;
        return findFirst(p << 1 | 1, m, r, L, R, std::forward<F>(pred));
    }

    template<class F>
    int findFirst(int L, int R, F &&pred) {
        assert(0 <= L && L <= R && R <= n);
        if (L == R) return -1;
        return findFirst(1, 0, n, L, R, std::forward<F>(pred));
    }

    template<class F>
    int findLast(int p, int l, int r, int L, int R, F &&pred) {
        if (L >= r || R <= l) return -1;
        if (L <= l && r <= R && !pred(info[p])) return -1;
        if (r - l == 1) return l;
        int m = (l + r) >> 1;
        push(p);
        int res = findLast(p << 1 | 1, m, r, L, R, std::forward<F>(pred));
        if (res != -1) return res;
        return findLast(p << 1, l, m, L, R, std::forward<F>(pred));
    }

    template<class F>
    int findLast(int L, int R, F &&pred) {
        assert(0 <= L && L <= R && R <= n);
        if (L == R) return -1;
        return findLast(1, 0, n, L, R, std::forward<F>(pred));
    }
};

struct Tag {
    i64 mul = 1, add = 0; 
    void apply(const Tag &t) & {
        mul = (mul * t.mul) % mod;
        add = (add * t.mul + t.add) % mod;
    }
};

struct Info {
    i64 sum = 0;
    int len = 1;
    void apply(const Tag &t) & {
        sum = (sum * t.mul + t.add * len) % mod;
    }
};

Info operator+(const Info &a, const Info &b) {
    Info res;
    res.sum = (a.sum + b.sum) % mod; 
    res.len = a.len + b.len;
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q, m;
    std::cin >> n >> q >> m;
    mod = m;
    
    std::vector<Info> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].sum;
        a[i].len = 1;
    }
    LazySegmentTree<Info, Tag> seg(a);

    for (int i = 0; i < q; i++) {
        int op;
        std::cin >> op;
        if (op == 1 || op == 2) {
            int x, y;
            i64 k;
            std::cin >> x >> y >> k;
            Tag t;
            if (op == 1) {
                t.mul = k % mod;
                t.add = 0;
            } else {
                t.mul = 1;
                t.add = k % mod;
            }
            seg.rangeApply(x - 1, y, t);
        } else {
            int x, y;
            std::cin >> x >> y;
            std::cout << seg.rangeQuery(x - 1, y).sum % mod << '\n';
        }
    }
    
    return 0;
}