import collections


N = int(input())
numbers = list(map(int, input().split()))
M = int(input())
targets = list(map(int, input().split()))

counter = collections.Counter(numbers)
for target in targets:
    print(counter[target], end=" ")
