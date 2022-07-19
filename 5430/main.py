import collections


T = int(input())

for _ in range(T):
    is_error = False
    is_left_head = True
    commands = input()
    n = int(input())
    if n == 0:
        input()
        deque = collections.deque()
    else:
        deque = collections.deque(list(map(int, input()[1:-1].split(sep=","))))
    for command in commands:
        if command == "R":
            is_left_head = not is_left_head
        elif command == "D":
            if len(deque) == 0:
                is_error = True
                break
            else:
                if is_left_head:
                    deque.popleft()
                else:
                    deque.pop()
    if is_error:
        print("error")
    else:
        print("[", end="")
        if is_left_head == False:
            deque.reverse()
        print(*deque, sep=",", end="")
        print("]")
