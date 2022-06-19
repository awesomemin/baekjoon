N, K = map(int, input().split())

numerator = 1
denominator = 1

for _ in range(N, N - K, -1):
    numerator *= _

for _ in range(K, 0, -1):
    denominator *= _

print(numerator // denominator)
