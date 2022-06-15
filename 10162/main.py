T = int(input())
A = B = C = 0

while (T >= 300):
    T -= 300
    A += 1
while (T >= 60):
    T -= 60
    B += 1
while (T >= 10):
    T -= 10
    C += 1
if(T == 0):
    print(A, B, C)
else:
    print("-1")
