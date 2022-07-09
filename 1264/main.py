while True:
    user_input = input()
    num = 0
    if user_input == "#":
        break
    for char in user_input:
        if char.lower() in {'a', 'e', 'i', 'o', 'u'}:
            num += 1
    print(num)
