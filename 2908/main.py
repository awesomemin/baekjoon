A, B = input().split()
A = list(A)
A.reverse()
A = int("".join(A))
B = list(B)
B.reverse()
B = int("".join(B))

print(A if A > B else B)
