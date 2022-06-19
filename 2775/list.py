T = int(input())


residents = []
for floor in range(14 + 1):
    residents_floor = []
    for room in range(1, 14 + 1):
        # when it is 0 floor
        if floor == 0:
            residents_floor.append(room)
        # when it is 1 ~ 14 floor
        else:
            people = 0
            for i in range(room):
                people += residents[floor - 1][i]
            residents_floor.append(people)
    residents.append(residents_floor)

for i in range(T):
    k = int(input())
    # k : floor
    n = int(input())
    # n : room number
    print(residents[k][n - 1])
