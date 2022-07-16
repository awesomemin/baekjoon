import collections

N, K = map(int, input().split())


def BFS(start_location):
    visited = set()
    queue = collections.deque()
    queue.append(start_location)
    time = 0
    while True:
        for _ in range(len(queue)):
            v = queue.popleft()
            visited.add(v)
            if v == K:
                return time
            if v < 0 or v > 100500:
                continue
            if v - 1 not in visited:
                queue.append(v - 1)
            if v + 1 not in visited:
                queue.append(v + 1)
            if v * 2 not in visited:
                queue.append(v * 2)
        time += 1


print(BFS(N))
