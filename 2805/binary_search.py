import sys
input = sys.stdin.readline

N, M = map(int, input().split())
trees = list(map(int, input().split()))
trees.sort()

lower = 0
upper = trees[-1]
for _ in range(20):
    prev = (lower, upper)
    available_tree = 0
    temp_H = (lower + upper) // 2
    for tree in trees:
        if tree > temp_H:
            available_tree += tree - temp_H
    if available_tree <= M:
        upper = temp_H
    elif available_tree >= M:
        lower = temp_H
    cur = (lower, upper)
    if prev == cur:
        break

for H in range(upper, lower - 1, -1):
    available_tree = 0
    for tree in trees:
        if tree > H:
            available_tree += tree - H
    if available_tree >= M:
        print(H)
        break
