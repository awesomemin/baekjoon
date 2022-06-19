import sys
N = int(input())

num_to_freq = {}

for i in range(N):
    num = int(sys.stdin.readline())
    try:
        num_to_freq[num] += 1
    except KeyError:
        num_to_freq[num] = 1

for i in range(1, 10000 + 1):
    try:
        for j in range(num_to_freq[i]):
            print(i)
    except KeyError:
        pass
