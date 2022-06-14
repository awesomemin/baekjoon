H, M = map(int, input().split())

for i in range(45):
    M -= 1
    if (M == -1):
        H -= 1
        M = 59
    if (H == -1):
        H = 23
        M = 59


print(H, M)
