import enum
import sys
input = sys.stdin.readline

N = int(input())

times = [*map(int, input().split())]
times.sort()

total_time = 0

for i in range(len(times)):
    total_time += sum(times[:i + 1])

print(total_time)
