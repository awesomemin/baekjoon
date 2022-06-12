strHour, strMin, strSec = input().split()
hour = int(strHour)
min = int(strMin)
sec = int(strSec)
duration = int(input())

i = 0

while(i < duration):
    sec += 1
    if(sec == 60):
        sec = 0
        min += 1
        if(min == 60):
            min = 0
            hour += 1
            if(hour == 24):
                hour = 0
    i += 1

print("%d %d %d" % (hour, min, sec))
