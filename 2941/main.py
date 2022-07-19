word = input()

pointer = 0

res = 0

alpha_set = {"c=", "c-", "d-", "lj", "nj", "s=", "z="}
while True:
    if pointer > len(word):
        break

    if word[pointer:pointer + 3] == "dz=":
        res += 1
        pointer += 3
    elif word[pointer:pointer + 2] in alpha_set:
        res += 1
        pointer += 2
    else:
        res += 1
        pointer += 1

print(res - 1)
