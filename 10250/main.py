T = int(input())
for i in range(T):
    H, W, N = map(int, input().split())
    ver = 0
    hor = 1
    for order in range(N):
        ver += 1
        if(ver > H):
            ver = 1
            hor += 1
    print(str(ver), str(hor).zfill(2), sep="")
