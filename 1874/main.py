import sys
import collections
input = sys.stdin.readline

n = int(input())

is_possible = True

next_pushed_number = 2
stack = collections.deque()
stack.append(1)
commands = [1]


def push():
    global next_pushed_number
    stack.append(next_pushed_number)
    next_pushed_number += 1
    commands.append(1)


def pop():
    commands.append(0)
    return stack.pop()


for _ in range(n):
    number = int(input())
    if not len(stack):
        push()
    if number == stack[-1] or number >= next_pushed_number:
        while stack[-1] != number:
            push()
        pop()
    else:
        is_possible = False
        break

if is_possible:
    for command in commands:
        if command:
            print("+")
        else:
            print("-")
else:
    print("NO")
