N = int(input())

files = []

for _ in range(N):
    files.append(input())

pattern = ""

for i in range(len(files[0])):
    are_all_same = True
    char = files[0][i]
    for file in files:
        if char != file[i]:
            are_all_same = False
    if are_all_same:
        pattern += char
    else:
        pattern += "?"

print(pattern)
