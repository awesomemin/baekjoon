T = int(input())
i = 0
while i < T:
    P = ""
    R, S = input().split()
    for char in S:
        j = 0
        while j < int(R):
            P += char
            j += 1
    print(P)
    i += 1
