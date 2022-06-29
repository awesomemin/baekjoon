import sys
input = sys.stdin.readline
N, M = map(int, input().split())

poketmon_book = ["null"]

for _ in range(N):
    poketmon_book.append(input().rstrip())

for _ in range(M):
    command = input().rstrip()
    if command.isalpha():
        print(poketmon_book.index(command))
    else:
        print(poketmon_book[int(command)])
