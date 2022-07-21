import heapq
import sys
input = sys.stdin.readline

max_heap = []

N = int(input())

for _ in range(N):
    command = int(input())
    if command == 0:
        if len(max_heap) == 0:
            print(0)
        else:
            print(heapq.heappop(max_heap)[1])
    else:
        heapq.heappush(max_heap, (-command, command))
