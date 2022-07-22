N = int(input())

paper = []

num_paper_neg = 0
num_paper_zero = 0
num_paper_pos = 0

for _ in range(N):
    paper.append(list(map(int, input().split())))


def check_mono(paper):
    is_mono = True
    color = paper[0][0]
    for row in paper:
        for space in row:
            if space != color:
                is_mono = False
                break
    return is_mono


def count_paper(paper):
    global num_paper_neg
    global num_paper_zero
    global num_paper_pos
    if check_mono(paper) == True:
        if paper[0][0] == -1:
            num_paper_neg += 1
        if paper[0][0] == 0:
            num_paper_zero += 1
        if paper[0][0] == 1:
            num_paper_pos += 1
    else:
        n = len(paper)
        count_paper([row[:(n // 3)] for row in paper[:(n // 3)]])  # left-upper
        count_paper([row[(n // 3):(n // 3) * 2]
                    for row in paper[:(n // 3)]])  # center-upper
        count_paper([row[(n // 3) * 2:(n // 3) * 3]
                    for row in paper[:(n // 3)]])  # right-upper
        count_paper([row[:(n // 3)]
                    for row in paper[(n // 3):(n // 3) * 2]])  # left-middle
        count_paper([row[(n // 3):(n // 3) * 2]
                    for row in paper[(n // 3):(n // 3) * 2]])  # center-middle
        count_paper([row[(n // 3) * 2:(n // 3) * 3]
                    for row in paper[(n // 3):(n // 3) * 2]])  # right-middle
        count_paper([row[:(n // 3)]
                    for row in paper[(n // 3) * 2:(n // 3) * 3]])  # left-lower
        count_paper([row[(n // 3):(n // 3) * 2]
                    for row in paper[(n // 3) * 2:(n // 3) * 3]])  # center-lower
        count_paper([row[(n // 3) * 2:(n // 3) * 3]
                    for row in paper[(n // 3) * 2:(n // 3) * 3]])  # right-lower


count_paper(paper)

print(num_paper_neg)
print(num_paper_zero)
print(num_paper_pos)
