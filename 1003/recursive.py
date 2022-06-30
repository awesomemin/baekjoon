T = int(input())


def pibo(n):
    if n == 0:
        return (1, 0)
    elif n == 1:
        return (0, 1)
    else:
        return (pibo(n - 1)[0] + pibo(n-2)[0], pibo(n - 1)[1] + pibo(n-2)[1])


for _ in range(T):
    print(*pibo(int(input())))
