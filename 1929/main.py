import math

M, N = map(int, input().split())

for num in range(M, N + 1):
    is_prime = True
    if num == 1:
        is_prime = False
    elif num == 2:
        pass
    else:
        for deno in range(2, math.ceil(num ** (1/2)) + 1):
            if num % deno == 0:
                is_prime = False
                break
    if is_prime:
        print(num)
