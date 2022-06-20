import sys
input = sys.stdin.readline

N = int(input())
users = []
for i in range(N):
    age, name = input().split()
    users.append([int(age), name])

users.sort(key=lambda x: x[0])

for user in users:
    print(user[0], user[1])
