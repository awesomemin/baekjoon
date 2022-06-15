T = int(input())
for i in range(T):
    N = int(input())
    mostUniv = ""
    mostSoju = 0
    for j in range(N):
        univ, soju = input().split()
        if(int(soju) > mostSoju):
            mostUniv = univ
            mostSoju = int(soju)
    print(mostUniv)
