import sys
from collections import defaultdict

def build_spf(n):
    spf = list(range(n+1))
    for i in range(2, int(n**0.5) + 1):
        if spf[i] == i:
            for j in range(i*i, n+1, i):
                if spf[j] == j:
                    spf[j] = i
    return spf

def main():
    data = sys.stdin.read().split()
    if not data:
        return
    n = int(data[0])
    if n == 0:
        return
    if n == 1:
        print("1")
        return

    spf = build_spf(n)
    
    is_prime = [True] * (n+1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, int(n**0.5)+1):
        if is_prime[i]:
            for j in range(i*i, n+1, i):
                is_prime[j] = False

    p = list(range(n+1))
    
    for i in range(2, n//2 + 1):
        if not is_prime[i]:
            continue
        if 2*i > n:
            continue
        p[i], p[2*i] = p[2*i], p[i]
    
    F = []
    for j in range(2, n+1):
        if is_prime[j]:
            continue
        if j % 2 == 0:
            half = j // 2
            if half <= n // 2 and is_prime[half]:
                continue
        F.append(j)
    
    N_set = set()
    for i in range(2, n+1):
        if is_prime[i] and i <= n // 2:
            N_set.add(i)
    for i in range(2, n+1):
        if i % 2 == 0:
            half = i // 2
            if half >= 2 and half <= n // 2 and is_prime[half]:
                N_set.add(i)
                
    L = defaultdict(list)
    for i in N_set:
        temp = i
        factors_set = set()
        while temp > 1:
            q = spf[temp]
            factors_set.add(q)
            while temp % q == 0:
                temp //= q
        for q in factors_set:
            L[q].append(i)
    
    used = [False] * (n+1)
    for j in F:
        temp = j
        factors = set()
        while temp > 1:
            q_val = spf[temp]
            factors.add(q_val)
            while temp % q_val == 0:
                temp //= q_val
        factors_sorted = sorted(factors)
        found = False
        for q in factors_sorted:
            if q not in L:
                continue
            for i_candidate in L[q]:
                if used[i_candidate]:
                    continue
                if is_prime[i_candidate]:
                    used[i_candidate] = True
                    p[i_candidate], p[j] = p[j], p[i_candidate]
                    found = True
                    break
                else:
                    p_val = i_candidate // 2
                    if j % p_val == 0:
                        used[i_candidate] = True
                        p[i_candidate], p[j] = p[j], p[i_candidate]
                        found = True
                        break
            if found:
                break
                
    out = []
    for i in range(1, n+1):
        out.append(str(p[i]))
    print(" ".join(out))

if __name__ == "__main__":
    main()