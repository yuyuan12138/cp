tot = 4
for i in range(5, 2000):
    tot ^= i
    if tot == 0:
        print(i)
        exit(0)

