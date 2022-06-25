from itertools import count
import sys
import collections
input = sys.stdin.readline

N = int(input())
numbers = []
for _ in range(N):
    numbers.append(int(input()))
numbers.sort()

counter = collections.Counter(numbers)

print(round(sum(numbers) / N))
print(numbers[(N - 1) // 2])
try:
    if counter.most_common(2)[0][1] > counter.most_common(2)[1][1]:
        print(counter.most_common(2)[0][0])
    else:
        print(counter.most_common(2)[1][0])
except IndexError:
    print(numbers[0])
print(numbers[-1] - numbers[0])
