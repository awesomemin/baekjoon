L = int(input())
r, M = 31, 1234567891
target_str = input()
sum = hash = 0
for index, char in enumerate(target_str):
    sum += (ord(char) - 96) * r ** index
hash = sum % M
print(hash)
