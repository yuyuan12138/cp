
for i in range(1, int(1e8)):
    flag = 0
    tmp = 0
    n = i
    while n != 1:
        if flag == 0:
            flag = 1
            x = n
            cnt = 0
            while x != 0:
                if x & 1 == 1:
                    cnt += 1
                x >>= 1
            n = cnt
        else:
            flag = 0
            x = n
            cnt = 0
            while x != 0:
                if x & 1 != 1:
                    cnt += 1
                x >>= 1
            cnt += 1
            x = cnt
        tmp += 1
        if tmp >= 500:
            print(i)
            exit(0)
            
            