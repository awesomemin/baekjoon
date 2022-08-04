import math

L = int(input())
A = int(input())
B = int(input())
C = int(input())
D = int(input())

math_required = math.ceil(B / D)
korean_required = math.ceil(A / C)

print(L - max(math_required, korean_required))
