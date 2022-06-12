T = int(input())
i = 1
while i <= T:
    a, b = input().split()
    print("Case #%d: %d + %d = %d" % (i, int(a), int(b), int(a) + int(b)))
    i += 1
