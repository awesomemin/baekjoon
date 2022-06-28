import math


N = int(input())
N_factorial = str(math.factorial(N))

result = 0

for digit in N_factorial[::-1]:
    if digit == "0":
        result += 1
    else:
        break

print(result)
