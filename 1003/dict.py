T = int(input())

pibo_dict = {
    0: (1, 0),
    1: (0, 1),
    2: (1, 1),
    3: (1, 2),
    4: (2, 3),
    5: (3, 5),
    6: (5, 8),
    7: (8, 13),
    8: (13, 21),
    9: (21, 34),
    10: (34, 55),
    11: (55, 89),
    12: (89, 144),
    13: (144, 233),
    14: (233, 377),
    15: (377, 610),
    16: (610, 987),
    17: (987, 1597),
    18: (1597, 2584),
    19: (2584, 4181),
    20: (4181, 6765),
    21: (6765, 10946),
    22: (10946, 17711),
    23: (17711, 28657),
    24: (28657, 46368),
    25: (46368, 75025),
    26: (75025, 121393),
    27: (121393, 196418),
    28: (196418, 317811),
    29: (317811, 514229),
    30: (514229, 832040),
    31: (832040, 1346269),
    32: (1346269, 2178309),
    33: (2178309, 3524578),
    34: (3524578, 5702887),
    35: (5702887, 9227465),
    36: (9227465, 14930352),
    37: (14930352, 24157817),
    38: (24157817, 39088169),
    39: (39088169, 63245986),
    40: (63245986, 102334155)
}

for _ in range(T):
    print(*pibo_dict[int(input())])
