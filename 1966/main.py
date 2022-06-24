import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N, M = map(int, input().split())
    priorities = list(map(int, input().split()))
    order = 1
    while True:
        if priorities[0] == max(priorities):  # 인쇄가 될 때
            priorities.pop(0)
            if M == 0:
                print(order)
                break
            else:
                order += 1
                M -= 1
        else:  # 인쇄가 안 될 때
            priorities.append(priorities.pop(0))
            if M == 0:
                M = len(priorities) - 1
            else:
                M -= 1
