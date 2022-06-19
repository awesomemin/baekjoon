N, M = map(int, input().split())
cards = list(map(int, input().split()))
cur_most = 0
for i in range(N):
    for j in range(i + 1, N):
        for k in range(j + 1, N):
            sum = cards[i] + cards[j] + cards[k]
            if(sum > cur_most and sum <= M):
                cur_most = sum
print(cur_most)
