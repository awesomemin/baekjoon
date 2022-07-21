N, r, c = map(int, input().split())

graph = [[0] * (2 ** N) for i in range(2 ** N)]
graph[r][c] = 1

order = 0


def find_location(graph):
    n = len(graph)
    for row in graph[:(n // 2)]:
        if 1 in row[:(n // 2)]:
            return 0
    for row in graph[:(n // 2)]:
        if 1 in row[(n // 2):]:
            return 1
    for row in graph[(n // 2):]:
        if 1 in row[:(n // 2)]:
            return 2
    for row in graph[(n // 2):]:
        if 1 in row[(n // 2):]:
            return 3


def find_order(graph):
    global order

    n = len(graph)

    location = find_location(graph)

    if n == 2:
        order += location

    else:
        order += ((n ** 2) * location) // 4
        if location == 0:
            find_order([row[:(n // 2)] for row in graph[:(n // 2)]])
        elif location == 1:
            find_order([row[(n // 2):] for row in graph[:(n // 2)]])
        elif location == 2:
            find_order([row[:(n // 2)] for row in graph[(n // 2):]])
        elif location == 3:
            find_order([row[(n // 2):] for row in graph[(n // 2):]])


find_order(graph)

print(order)
