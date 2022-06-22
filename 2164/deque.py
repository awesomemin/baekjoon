import collections

cards = collections.deque()
cards.extend(range(1, int(input()) + 1))

while len(cards) != 1:
    cards.popleft()
    cards.append(cards.popleft())

print(cards.pop())
