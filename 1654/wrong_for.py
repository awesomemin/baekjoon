import sys
K, N = map(int, input().split())
cables = []
for i in range(K):
    cables.append(int(sys.stdin.readline()))

max_length = 1
while True:
    cables_number = 0
    for cable in cables:
        cables_number += (cable // max_length)
    if (cables_number >= N):
        max_length += 1
    else:
        break

print(max_length - 1)
