import heapq
import sys
input = sys.stdin.readline

T = int(input())

for TEST_CASE in range(T):
    exist = [False] * 1000001
    min_heap = []
    max_heap = []
    k = int(input())
    for op in range(k):
        c1, c2 = input().split()
        if c1 == "I":
            heapq.heappush(min_heap, (int(c2), op))
            heapq.heappush(max_heap, (-int(c2), op))
            exist[op] = 1
        elif c1 == "D":
            if c2 == "1":
                while max_heap and not exist[max_heap[0][1]]:
                    heapq.heappop(max_heap)
                if max_heap:
                    exist[max_heap[0][1]] = 0
                    heapq.heappop(max_heap)
            elif c2 == "-1":
                while min_heap and not exist[min_heap[0][1]]:
                    heapq.heappop(min_heap)
                if min_heap:
                    exist[min_heap[0][1]] = 0
                    heapq.heappop(min_heap)

    while min_heap and not exist[min_heap[0][1]]:
        heapq.heappop(min_heap)
    while max_heap and not exist[max_heap[0][1]]:
        heapq.heappop(max_heap)

    if len(min_heap) == 0 or len(max_heap) == 0:
        print("EMPTY")
    else:
        print(-max_heap[0][0], min_heap[0][0])
