while True:
    a, b = input().split()
    if(int(a) == 0 and int(b) == 0):
        break
    elif(int(a) > int(b)):
        print("Yes")
    else:
        print("No")
