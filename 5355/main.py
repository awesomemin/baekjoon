T = int(input())
i = 0
while i < T:
    list = input().split()
    listIndex = 0
    result = 0.0
    for item in list:
        if(listIndex == 0):
            result = float(item)
        else:
            if(item == "@"):
                result = result * 3
            elif(item == "%"):
                result = result + 5
            elif(item == "#"):
                result = result - 7
        listIndex = listIndex + 1
    print(f"{result:.2f}")
    i = i + 1
