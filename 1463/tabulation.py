dp = [None, 0, 1, 1, 2]

N = int(input())

for i in range(5, N + 1):
    candidates = []
    if i % 3 == 0:
        candidates.append(dp[i // 3] + 1)
    if i % 2 == 0:
        candidates.append(dp[i // 2] + 1)
    candidates.append(dp[i - 1] + 1)
    dp.append(min(candidates))

print(dp[N])
