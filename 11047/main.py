N, K = map(int, input().split())
coins = []

for _ in range(N):
    coins.append(int(input()))

coins.reverse()

coin_numbers = 0
value = 0
for coin in coins:
    while K - value >= coin:
        value += coin
        coin_numbers += 1
    if K == value:
        print(coin_numbers)
        break
