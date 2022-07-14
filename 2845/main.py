L, P = map(int, input().split())
nums = map(int, input().split())
for num in nums:
    print(num - L * P, end=" ")
