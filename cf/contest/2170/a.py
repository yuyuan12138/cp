def solve():
    n = int(input())
    s = [[j for j in range(n * i + 1, n * i + n + 1)] for i in range(0, n)]
    ans = 0
    for i in range(n):
        for j in range(n):
            cnt = s[i][j]
            if i > 0:
                cnt += s[i - 1][j]
            if i < n - 1:
                cnt += s[i + 1][j]
            if j > 0:
                cnt += s[i][j - 1]
            if j < n - 1:
                cnt += s[i][j + 1]
            ans = max(ans, cnt)
    print(ans)

t = int(input())
for _ in range(t):
    solve()