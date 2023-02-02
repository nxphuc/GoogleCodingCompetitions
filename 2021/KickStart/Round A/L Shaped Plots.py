def calc(a, x, y):
    min_ax = min(a, x // 2)
    min_ay = min(a, y // 2)
    return max(0, min_ax - 1) + max(0, min_ay - 1)


t = int(input())
for cs in range(t):
    r, c = map(int, input().split())
    mat = []
    for _ in range(r):
        mat.append(list(map(int, input().split())))

    count_left = [[0] * c for _ in range(r)]
    count_right = [[0] * c for _ in range(r)]
    count_up = [[0] * c for _ in range(r)]
    count_down = [[0] * c for _ in range(r)]

    for i in range(r):
        for j in range(c):
            if mat[i][j] == 1:
                count_left[i][j] = 1
                if j > 0:
                    count_left[i][j] += count_left[i][j-1]
        for j in range(c-1, -1, -1):
            if mat[i][j] == 1:
                count_right[i][j] = 1
                if j < c-1:
                    count_right[i][j] += count_right[i][j+1]

    for j in range(c):
        for i in range(r):
            if mat[i][j] == 1:
                count_up[i][j] = 1
                if i > 0:
                    count_up[i][j] += count_up[i-1][j]
        for i in range(r-1, -1, -1):
            if mat[i][j] == 1:
                count_down[i][j] = 1
                if i < r-1:
                    count_down[i][j] += count_down[i+1][j]

    res = 0
    for i in range(r):
        for j in range(c):
            res += calc(count_left[i][j], count_up[i][j], count_down[i][j])
            res += calc(count_right[i][j], count_up[i][j], count_down[i][j])
            res += calc(count_up[i][j], count_left[i][j], count_right[i][j])
            res += calc(count_down[i][j], count_left[i][j], count_right[i][j])

    print(f'Case #{cs+1}: {res}')
