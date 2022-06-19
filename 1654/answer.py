import sys
# K : number of cables I have
# N : number of cables I need to make
K, N = map(int, sys.stdin.readline().split())
cables = []
for i in range(K):
    cables.append(int(sys.stdin.readline()))
lower = 1
upper = max(cables)

for i in range(20):
    target_length = (lower + upper) // 2
    cable_number = 0
    for cable in cables:
        cable_number += cable // target_length
    if(cable_number > N):
        lower = target_length
    elif(cable_number < N):
        upper = target_length
    else:
        break

for i in range(upper, lower - 1, -1):
    cable_number = 0
    for cable in cables:
        cable_number += cable // i
    if (cable_number >= N):
        print(i)
        break
