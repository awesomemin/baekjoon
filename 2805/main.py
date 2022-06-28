import sys
input = sys.stdin.readline

N, M = map(int, input().split())
trees = list(map(int, input().split()))
trees.sort()

H = trees[-1] - 1
while True:
    available_tree = 0
    for tree in trees:
        if tree > H:
            available_tree += tree - H
    if available_tree >= M:
        break
    else:
        H -= 1

print(H)
