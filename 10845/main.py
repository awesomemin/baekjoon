import sys
import collections
input = sys.stdin.readline

N = int(input())
queue = collections.deque()

for _ in range(N):
    command = input().split()
    if command[0] == "push":
        queue.append(int(command[1]))
    elif command[0] == "pop":
        try:
            print(queue.popleft())
        except IndexError:
            print("-1")
    elif command[0] == "size":
        print(len(queue))
    elif command[0] == "empty":
        if len(queue):
            print(0)
        else:
            print(1)
    elif command[0] == "front":
        try:
            print(queue[0])
        except IndexError:
            print("-1")
    elif command[0] == "back":
        try:
            print(queue[-1])
        except IndexError:
            print("-1")
