for n in range(1, 2):
    cnt = 0
    while n != 4 and n != 1 and n != 0:
        tmp = n
        add = 0
        while tmp != 0:
            add += (tmp % 10) * (tmp % 10)
            tmp = tmp // 10

        n = add
        cnt += 1
    print(f"{n}, cost = {cnt}")
