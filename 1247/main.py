for TEST_CASE in range(3):
    N = int(input())
    sum = 0
    for _ in range(N):
        sum += int(input())
    if sum > 0:
        print("+")
    elif sum == 0:
        print("0")
    elif sum < 0:
        print("-")
