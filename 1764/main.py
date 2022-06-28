import sys
input = sys.stdin.readline

N, M = map(int, input().split())

no_hear = set()
no_see = set()

for _ in range(N):
    no_hear.add(input().rstrip())

for _ in range(M):
    no_see.add(input().rstrip())


no_hear_no_see = list(no_hear & no_see)
no_hear_no_see.sort()
print(len(no_hear_no_see))
for person in no_hear_no_see:
    print(person)
