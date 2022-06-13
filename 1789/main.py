S = int(input())
i = 1
N = 0
while (S > 0):
    S = S - i
    N += 1
    i += 1
if(S == 0):
    print(N)
else:
    print(N-1)
