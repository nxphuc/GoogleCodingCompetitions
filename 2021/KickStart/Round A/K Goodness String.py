t = int(input())
for cs in range(t):
    n, k = map(int, input().split())
    s = input()
    cnt = 0
    for i in range(n // 2):
        cnt += 1 if s[i] != s[n - i - 1] else 0
    print(f'Case #{cs+1}: {abs(k-cnt)}')
