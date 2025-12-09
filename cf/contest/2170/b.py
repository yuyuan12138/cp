def solve():
    n = int(input())
    b = list(map(int, input().split()))
    b = sorted(b)
    print(b)

t = int(input())
for _ in range(t):
    solve()