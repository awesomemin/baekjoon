squares = []

i = 1
while i ** 2 <= 50000:
    squares.append(i ** 2)
    i += 1

n = int(input())

# 1개로 되는지 검사
if n in squares:
    print(1)
    quit()

# 2개로 되는지 검사
for i in squares:
    for j in squares:
        if i > j:
            continue
        if j > n:
            break
        if i + j == n:
            print(2)
            quit()
    if i > n:
        break

# 3개로 되는지 검사
for i in squares:
    for j in squares:
        for k in squares:
            if j > k:
                continue
            if k > n:
                break
            if i + j + k == n:
                print(3)
                quit()
        if i > j:
            continue
        if j > n:
            break
    if i > n:
        break

# else : 4개
print(4)
