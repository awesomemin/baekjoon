xFirst = 0
anotherX = 0
yFirst = 0
anotherY = 0
isXFirstAnswer = True
isYFirstAnswer = True
for i in range(3):
    x, y = input().split()
    if(i == 0):
        xFirst = int(x)
        yFirst = int(y)
    else:
        if(xFirst == int(x)):
            isXFirstAnswer = False
        else:
            anotherX = int(x)
        if(yFirst == int(y)):
            isYFirstAnswer = False
        else:
            anotherY = int(y)

xResult = 0
yResult = 0
if(isXFirstAnswer):
    xResult = xFirst
else:
    xResult = anotherX

if(isYFirstAnswer):
    yResult = yFirst
else:
    yResult = anotherY

print(xResult, yResult)
