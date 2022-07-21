import collections


M, N = map(int, input().split())

box = []
day = 0

for _ in range(N):
    box.append(list(map(int, input().split())))

queue = collections.deque()

for y, row in enumerate(box):
    for x, tomato in enumerate(row):
        if tomato == 1:
            queue.append((x, y))

while queue:
    day += 1
    for _ in range(len(queue)):
        tmt = queue.popleft()
        if tmt[0] > 0:
            if box[tmt[1]][tmt[0] - 1] == 0:
                box[tmt[1]][tmt[0] - 1] = 1
                queue.append((tmt[0] - 1, tmt[1]))
        if tmt[0] < M - 1:
            if box[tmt[1]][tmt[0] + 1] == 0:
                box[tmt[1]][tmt[0] + 1] = 1
                queue.append((tmt[0] + 1, tmt[1]))
        if tmt[1] > 0:
            if box[tmt[1] - 1][tmt[0]] == 0:
                box[tmt[1] - 1][tmt[0]] = 1
                queue.append((tmt[0], tmt[1] - 1))
        if tmt[1] < N - 1:
            if box[tmt[1] + 1][tmt[0]] == 0:
                box[tmt[1] + 1][tmt[0]] = 1
                queue.append((tmt[0], tmt[1] + 1))

is_impossible = False

for row in box:
    for tomato in row:
        if tomato == 0:
            is_impossible = True

if is_impossible:
    print(-1)
else:
    print(day - 1)
