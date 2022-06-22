N = int(input())
cards = [n for n in range(1, N + 1)]

while len(cards) != 1:
    for i in range(len(cards)):
        try:
            del cards[i]
        except:
            pass

print(cards[0])
