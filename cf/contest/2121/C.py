import sys

def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    index = 1
    results = []
    for _ in rane(t):
        n = int(data[index])
        m = int(data[index+1])
        index += 2
        matrix = []
        for i in range(n):
            row = list(map(int, data[index:index+m]))
            index += m
            matrix.append(row)
        
        M = 0
        for row in matrix:
            for x in row:
                if x > M:
                    M = x
        
        rows_set = set()
        cols_set = set()
        row_to_cols = [set() for _ in range(n)]
        col_to_rows = [set() for _ in range(m)]
        
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == M:
                    rows_set.add(i)
                    cols_set.add(j)
                    row_to_cols[i].add(j)
                    col_to_rows[j].add(i)
        
        if len(rows_set) == 1 or len(cols_set) == 1:
            results.append(str(M-1))
            continue
        
        found = False
        for r in rows_set:
            countT = 0
            for c in cols_set:
                if r in col_to_rows[c]:
                    if len(col_to_rows[c]) >= 2:
                        countT += 1
                else:
                    countT += 1
                if countT > 1:
                    break
            if countT <= 1:
                found = True
                break
        
        if found:
            results.append(str(M-1))
            continue
        
        for c in cols_set:
            countT = 0
            for r in rows_set:
                if c in row_to_cols[r]:
                    if len(row_to_cols[r]) >= 2:
                        countT += 1
                else:
                    countT += 1
                if countT > 1:
                    break
            if countT <= 1:
                found = True
                break
        
        results.append(str(M-1) if found else str(M))
    
    print("\n".join(results))

if __name__ == '__main__':
    main()