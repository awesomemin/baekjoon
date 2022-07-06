import collections

T = int(input())

for _ in range(T):
    n = int(input())
    clothes = []
    for __ in range(n):
        clothes.append(input().split()[1])

    types = list(map(lambda x: x + 1, collections.Counter(clothes).values()))

    result = 1
    for i in types:
        result *= i
    print(result - 1)
