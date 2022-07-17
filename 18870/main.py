N = int(input())
points = list(map(int, input().split()))
points_set = set(points)
points_sorted = list(points_set)
points_sorted.sort()
converted = {}

i = 0
for point in points_sorted:
    converted[point] = i
    i += 1

for point in points:
    print(converted[point], end=" ")
