import sys
input = sys.stdin.readline

N = int(input())
meetings = []
for _ in range(N):
    meetings.append(list(map(int, input().split())))

meetings.sort(key=lambda x: (x[1], x[0]))

available_time = 0

meeting_num = 0

for meeting in meetings:
    if meeting[0] >= available_time:
        available_time = meeting[1]
        meeting_num += 1

print(meeting_num)
