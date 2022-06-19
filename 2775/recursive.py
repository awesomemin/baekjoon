T = int(input())


def calc_population(k, n):
    if(k == 0):
        return n
    else:
        result = 0
        for i in range(n + 1):
            result += calc_population(k - 1, i)
        return result


for i in range(T):
    k = int(input())
    # k : floor
    n = int(input())
    # n : room number
    print(calc_population(k, n))
