T = int(input())
i = 0


def userInput():
    nums = input().split()
    nums = map(int, nums)
    nums = list(nums)
    nums.sort()
    return nums


def LCM(a, b):
    lcm = a * b
    i = 2
    commons = []
    while(i <= a):
        if(a % i == 0 and b % i == 0):
            a = int(a / i)
            b = int(b / i)
            commons.append(i)
            i = 2
        else:
            i += 1
    for common in commons:
        lcm = int(lcm / common)
    return lcm


while(i < T):
    a, b = userInput()
    print(LCM(a, b))
    i += 1
