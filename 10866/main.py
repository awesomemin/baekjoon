import sys
import collections
input = sys.stdin.readline

N = int(input())
deque = collections.deque()

for _ in range(N):
    command = input().split()
    if command[0] == "push_front":
        deque.appendleft(int(command[1]))
    elif command[0] == "push_back":
        deque.append(int(command[1]))
    elif command[0] == "pop_front":
        try:
            print(deque.popleft())
        except IndexError:
            print(-1)
    elif command[0] == "pop_back":
        try:
            print(deque.pop())
        except:
            print(-1)
    elif command[0] == "size":
        print(len(deque))
    elif command[0] == "empty":
        if len(deque):
            print(0)
        else:
            print(1)
    elif command[0] == "front":
        try:
            print(deque[0])
        except IndexError:
            print(-1)
    elif command[0] == "back":
        try:
            print(deque[-1])
        except IndexError:
            print(-1)
