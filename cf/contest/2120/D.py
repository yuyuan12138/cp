MOD = 10**9 + 7

def main():
    import sys
    data = sys.stdin.read().split()
    a = int(data[0])
    b = int(data[1])
    k = int(data[2])
    
    if a == 1 and b == 1:
        n = 1
        m = 1
    elif a == 1:
        n = 1
        m = (k * (b - 1) + 1) % MOD
    elif b == 1:
        n = (k * (a - 1) + 1) % MOD
        m = 1
    else:
        n_val = (pow(k, a - 1, MOD) * (b - 1)) % MOD
        n_val = (n_val + 1) % MOD
        n = n_val
        
        m_val = (pow(k, b - 1, MOD) * (a - 1)) % MOD
        m_val = (m_val + 1) % MOD
        m = m_val
    
    print(f"{n} {m}")

if __name__ == "__main__":
    main()