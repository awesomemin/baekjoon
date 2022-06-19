A, B = map(int, input().split())
GCD = LCM = int()
for i in range(min(A, B), 0, -1):
    if(A % i == 0 and B % i == 0):
        GCD = i
        break
LCM = A * B // GCD
print(GCD)
print(LCM)
