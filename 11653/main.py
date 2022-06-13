N = int(input())
while (N != 1):
    i = 2
    while(i <= N):
        if(N % i == 0):
            N = int(N / i)
            print(i)
            break
        else:
            i += 1
