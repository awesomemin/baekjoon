import sys
K, N = map(int, sys.stdin.readline().split())
max_length = int()

cables = []
for i in range(K):
    cables.append(int(sys.stdin.readline()))

lower = 1
upper = min(cables)

while True:
    max_length = (lower + upper) // 2
    cable_number = 0
    for cable in cables:
        cable_number += cable // max_length
    if(cable_number > N):
        lower = max_length
    elif(cable_number < N):
        upper = max_length
    elif(cable_number == N):
        break
for candidate in range(upper, lower - 1, -1):
    cable_number = 0
    for cable in cables:
        cable_number += cable // candidate
    if(cable_number == N):
        print(candidate)
        break
