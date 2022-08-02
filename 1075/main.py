N = int(input())
F = int(input())

N = (N // 100) * 100

num = 0

while num < N:
    num += F

if num % 100 < 10:
    print("0" + str(num % 100))
else:
    print(num % 100)
