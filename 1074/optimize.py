N, r, c = map(int, input().split())

order = 0


def find_location(N, r, c):
    if r < 2 ** (N - 1) and c < 2 ** (N - 1):
        return 0
    elif r < 2 ** (N - 1) and c >= 2 ** (N - 1):
        return 1
    elif r >= 2 ** (N - 1) and c < 2 ** (N - 1):
        return 2
    elif r >= 2 ** (N - 1) and c >= 2 ** (N - 1):
        return 3


def find_order(N, r, c):
    global order
    location = find_location(N, r, c)
    if N == 1:
        order += location
    else:
        order += (2 ** (2 * N - 2)) * location
        if location == 0:
            find_order(N - 1, r, c)
        elif location == 1:
            find_order(N - 1, r, c - (2 ** (N - 1)))
        elif location == 2:
            find_order(N - 1, r - (2 ** (N - 1)), c)
        elif location == 3:
            find_order(N - 1, r - (2 ** (N - 1)), c - (2 ** (N - 1)))


find_order(N, r, c)

print(order)
