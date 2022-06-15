while True:
    n = int(input())
    if(n == -1):
        break
    else:
        divisors = []
        for i in range(1, n):
            if(n % i == 0):
                divisors.append(i)
        if(n != sum(divisors)):
            print("%d is NOT perfect." % n)
        else:
            print("%d =" % n, end="")
            for i in divisors:
                if(i == 1):
                    print(" 1 ", end="")
                else:
                    print("+ %d " % i, end="")
