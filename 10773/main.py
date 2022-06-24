import sys
input = sys.stdin.readline

K = int(input())

numbers = []
for _ in range(K):
    num = int(input())
    if(num == 0):
        numbers.pop()
    else:
        numbers.append(num)

print(sum(numbers))
