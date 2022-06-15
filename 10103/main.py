n = int(input())
Ascore = Bscore = 100
for i in range(n):
    A, B = map(int, input().split())
    if(A == B):
        continue
    elif(A > B):
        Bscore -= A
    elif(B > A):
        Ascore -= B

print(Ascore)
print(Bscore)
