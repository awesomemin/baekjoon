N, M = map(int, input().split())
A = []
B = []
for i in range(N * 2):
    row = list(map(int, input().split()))
    B.append(row) if i >= N else A.append(row)

for i in range(N):
    for j in range(M):
        print(A[i][j] + B[i][j], end=" ")
    print("")
