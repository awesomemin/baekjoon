while True:
    N = input()
    if N == "0":
        break

    length = 2

    length += (len(N) - 1)

    for char in N:
        if char == "1":
            length += 2
        elif char == "0":
            length += 4
        else:
            length += 3

    print(length)
