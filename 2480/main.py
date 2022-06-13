strA, strB, strC = input().split()
a = int(strA)
b = int(strB)
c = int(strC)
if(a == b == c):
    print(10000 + a * 1000)
elif(a == b or b == c or a == c):
    nums = [a, b, c]
    nums.sort()
    print(1000 + nums[1] * 100)
else:
    print(max(a, b, c) * 100)
