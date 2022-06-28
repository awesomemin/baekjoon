import sys
input = sys.stdin.readline

N, M, B = map(int, input().split())

ground = []
time_dict = {}
min_level = 256
max_level = 0
for _ in range(N):
    row = list(map(int, input().split()))
    if min(row) < min_level:
        min_level = min(row)
    if max(row) > max_level:
        max_level = max(row)
    ground.append(row)

for level in range(min_level, max_level + 1):
    time = 0
    block = B
    for i in range(N):
        for j in range(M):
            cur_level = ground[i][j]
            if cur_level > level:
                time += 2 * (cur_level - level)
                block += cur_level - level
            else:
                time += level - cur_level
                block -= level - cur_level
    if block < 0:
        continue
    else:
        time_dict[level] = time

min_time = min(time_dict.values())
time_min_levels = []
for i in time_dict:
    if time_dict[i] == min_time:
        time_min_levels.append(i)
time_min_levels.sort()

print(min_time, time_min_levels[-1])
