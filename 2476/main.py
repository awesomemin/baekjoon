participants = int(input())

reward = []


def getNumbers():
    numbers = input().split()
    numbers = list(map(int, numbers))
    numbers.sort()
    return numbers


def calcReward(numbers):
    if(numbers[0] == numbers[1] == numbers[2]):
        return 10000 + numbers[0] * 1000
    elif(numbers[0] == numbers[1] or numbers[0] == numbers[2]):
        return 1000 + numbers[0] * 100
    elif(numbers[1] == numbers[2]):
        return 1000 + numbers[1] * 100
    else:
        return numbers[2] * 100


for i in range(participants):
    numbers = getNumbers()
    reward.append(calcReward(numbers))

print(max(reward))
