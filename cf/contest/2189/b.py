import sys

def solve_one(it):
    n = int(next(it))
    x = int(next(it))

    a = [0] * n
    b = [0] * n
    c = [0] * n
    for i in range(n):
        a[i] = int(next(it))
        b[i] = int(next(it))
        c[i] = int(next(it))

    tot = 0
    for i in range(n):
        tot += a[i] * (b[i] - 1)

    if tot >= x:
        return 0

    best = -10**30
    idx = -1
    for i in range(n):
        val = a[i] * b[i] - c[i]
        if val >= best:
            best = val
            idx = i

    if best <= 0:
        return -1

    x -= tot
    ai, bi, ci = a[idx], b[idx], c[idx]

    def check(k: int) -> bool:
        # f = a + (k-1)*a*b - c*k + a*(b-1)
        f = ai + (k - 1) * ai * bi - ci * k + ai * (bi - 1)
        return f >= x

    l, r = 0, 10**18
    while l <= r:
        mid = (l + r) // 2
        if check(mid):
            r = mid - 1
        else:
            l = mid + 1
    return l

def main():
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    it = iter(data)
    t = int(next(it))
    out = []
    for _ in range(t):
        out.append(str(solve_one(it)))
    sys.stdout.write("\n".join(out) + "\n")  # 末尾补换行，OJ更稳

if __name__ == "__main__":
    main()