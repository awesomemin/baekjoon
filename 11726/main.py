n = int(input())

ls = [0, 1, 2]

for i in range(3, n + 1):
    ls.append(ls[i - 1] + ls[i - 2])

print(ls[n] % 10007)
