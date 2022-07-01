found = list(map(int, input().split()))
target = [1, 1, 2, 2, 2, 8]

for i in range(6):
    print(target[i] - found[i], end=" ")
