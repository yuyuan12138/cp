def solve():
    n = int(input())
    q = int(input())
    size = 2 ** (2 * n)
    for _ in range(q):
        ipt = input().split()
        if ipt[0] == '->':
            x, y = int(ipt[1]), int(ipt[2])
            
        else:
            num = int(ipt[1])
            

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()