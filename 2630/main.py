N = int(input())
graph = []
white = blue = 0
for _ in range(N):
    graph.append(list(map(int, input().split())))


def is_mono(paper):
    n = len(paper)
    color = paper[0][0]
    for row in paper:
        for space in row:
            if space != color:
                return False
    return True


def make_paper(paper):
    global blue
    global white
    n = len(paper)
    if is_mono(paper):
        if paper[0][0] == 1:
            blue += 1
            return
        elif paper[0][0] == 0:
            white += 1
    else:
        make_paper([row[:(n // 2)] for row in paper[:(n // 2)]])
        make_paper([row[:(n // 2)] for row in paper[(n // 2):]])
        make_paper([row[(n // 2):] for row in paper[:(n // 2)]])
        make_paper([row[(n // 2):] for row in paper[(n // 2):]])


make_paper(graph)
print(white, blue, sep="\n")
