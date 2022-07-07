n = int(input())

ls = [0, 1, 3]

for i in range(3, n + 1):
    ls.append(ls[i - 1] + 2 * ls[i - 2])

print(ls[n] % 10007)
