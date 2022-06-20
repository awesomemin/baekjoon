import sys
input = sys.stdin.readline

N = int(input())
stack = []
for i in range(N):
    command = input().split()
    if (command[0]) == "push":
        stack.append(int(command[1]))
    elif (command[0]) == "pop":
        try:
            print(stack.pop())
        except IndexError:
            print("-1")
    elif (command[0]) == "size":
        print(len(stack))
    elif (command[0]) == "empty":
        if len(stack) == 0:
            print("1")
        else:
            print("0")
    elif (command[0]) == "top":
        try:
            print(stack[-1])
        except IndexError:
            print("-1")
