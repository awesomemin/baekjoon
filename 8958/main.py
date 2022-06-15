n = int(input())
for i in range(n):
    result = input()
    score = 0
    currentProblemScore = 1
    for problem in result:
        if(problem == "O"):
            score += currentProblemScore
            currentProblemScore += 1
        else:
            currentProblemScore = 1
    print(score)
