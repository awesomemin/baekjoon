T = int(input())
for i in range(T):
    Yscore = 0
    Kscore = 0
    for j in range(9):
        Y, K = map(int, input().split())
        Yscore += Y
        Kscore += K
    if(Yscore > Kscore):
        print("Yonsei")
    elif(Yscore < Kscore):
        print("Korea")
    else:
        print("Draw")
