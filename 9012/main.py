T = int(input())
for _ in range(T):
    PS = input()
    while True:
        is_pair_found = False
        for i in range(len(PS)):
            if PS[i: i+2] == "()":
                is_pair_found = True
                PS = PS[0:i] + PS[i+2:]
                break
        if is_pair_found == False:
            print("NO")
            break
        if len(PS) == 0:
            print("YES")
            break
