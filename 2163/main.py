strN, strM = input().split()
n = int(strN)
m = int(strM)
if (n == m):
    print(n * n - 1)
elif (n > m):
    print((m - 1) + m * (n - 1))
elif (n < m):
    print((n - 1) + n * (m - 1))
