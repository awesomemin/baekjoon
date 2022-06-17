A = int(input())
B = int(input())
C = int(input())
result = A * B * C
result = str(result)
for number in range(10):
    print(result.count(str(number)))
