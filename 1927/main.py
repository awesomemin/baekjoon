import heapq
import sys
input = sys.stdin.readline

N = int(input())
min_heap = []
for _ in range(N):
    command = int(input())
    if command == 0:
        if len(min_heap) == 0:
            print("0")
        else:
            print(heapq.heappop(min_heap))
    else:
        heapq.heappush(min_heap, command)
