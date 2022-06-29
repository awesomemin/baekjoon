import sys
input = sys.stdin.readline
N, M = map(int, input().split())

poketmon_book = ["null"]

for _ in range(N):
    poketmon_book.append(input().rstrip())

for _ in range(M):
    command = input().rstrip()
    if command.isalpha():
        sys.stdout.write(str(poketmon_book.index(command)) + "\n")
    else:
        sys.stdout.write(poketmon_book[int(command)] + "\n")
