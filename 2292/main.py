N = int(input())
n = 1
while True:
    if N == 1:
        print(1)
        break
    if 3 * n ** 2 - 9 * n + 7 < N and N <= 3 * n ** 2 - 3 * n + 1:
        print(n)
        break
    n += 1
