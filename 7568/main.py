import sys
input = sys.stdin.readline

N = int(input())
weight_tall = []

for _ in range(N):
    weight_tall.append(list(map(int, input().split())))

for me in range(N):
    rank = 1
    for other in weight_tall:
        if weight_tall[me][0] < other[0] and weight_tall[me][1] < other[1]:
            rank += 1
    print(rank, end=" ")
