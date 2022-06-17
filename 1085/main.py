x, y, w, h = map(int, input().split())
distances = [x, w - x, y, h - y]
print(min(distances))
