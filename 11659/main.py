import sys
input = sys.stdin.readline

N, M = map(int, input().split())
nums = list(map(int, input().split()))

sums = []
sum = 0

for num in nums:
    sum += num
    sums.append(sum)

for _ in range(M):
    start, end = map(int, input().split())
    if start == 1:
        print(sums[end - 1])
    else:
        print(sums[end - 1] - sums[start - 2])
