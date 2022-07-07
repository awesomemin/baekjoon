N, M = map(int, input().split())
nums = list(map(int, input().split()))

for _ in range(M):
    start, end = map(int, input().split())
    sum = 0
    for num in range(start - 1, end):
        sum += nums[num]
    print(sum)
