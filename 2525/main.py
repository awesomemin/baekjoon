strHour, strMin = input().split()
hour = int(strHour)
min = int(strMin)
duration = int(input())

i = 0
while i < duration:
    min += 1
    if (min == 60):
        min = 0
        hour += 1
        if (hour == 24):
            hour = 0
    i += 1

print("%d %d" % (hour, min))
