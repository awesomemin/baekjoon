T = int(input())


def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n - 1)


def combination(n, r):
    return (factorial(n) // (factorial(r) * factorial(n - r)))


for _ in range(T):
    N, M = map(int, input().split())
    print(combination(M, N))
