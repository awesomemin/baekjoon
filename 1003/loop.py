def pibo(n):
    ls_1 = [1, 0]
    ls_2 = [0, 1]
    temp = list()
    if n == 0:
        return ls_1
    elif n == 1:
        return ls_2
    else:
        for _ in range(n - 1):
            temp = [ls_1[0] + ls_2[0], ls_1[1] + ls_2[1]]
            ls_1 = ls_2
            ls_2 = temp
        return temp


T = int(input())

for _ in range(T):
    print(*pibo(int(input())))
