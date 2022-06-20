import sys
input = sys.stdin.readline

N = int(input())
numbers = [0] * 2000001

for _ in range(N):
    numbers[int(input()) + 1000000] = 1

for num, isExist in enumerate(numbers):
    if(isExist):
        print(num - 1000000)
