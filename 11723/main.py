import sys
input = sys.stdin.readline

S = set()

N = int(input())
for _ in range(N):
    command = input().split()
    if command[0] == "add":
        if int(command[1]) not in S:
            S.add(int(command[1]))
    elif command[0] == "remove":
        if int(command[1]) in S:
            S.remove(int(command[1]))
    elif command[0] == "check":
        if int(command[1]) in S:
            print(1)
        else:
            print(0)
    elif command[0] == "toggle":
        if int(command[1]) in S:
            S.remove(int(command[1]))
        else:
            S.add(int(command[1]))
    elif command[0] == "all":
        S = set()
        S.update([i for i in range(1, 21)])
    elif command[0] == "empty":
        S = set()
