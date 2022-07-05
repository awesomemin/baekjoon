import math

T = int(input())

for _ in range(T):

    N = int(input())

    result = 0

    for three in range(3, 0 - 1, -1):
        for two in range(5, 0 - 1, -1):
            for one in range(11, 0 - 1, -1):
                if 3 * three + 2 * two + one == N:
                    result += math.factorial(three + two + one) // (
                        math.factorial(three) * math.factorial(two) * math.factorial(one))

    print(result)
