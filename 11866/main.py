N, K = map(int, input().split())
people = [n for n in range(1, N + 1)]
deleted_order = []

i = 1
while True:
    if i % K == 0:
        deleted_order.append(people.pop(0))
    else:
        people.append(people.pop(0))
    if len(people) == 0:
        break
    i += 1

print("<", end="")
for i, num in enumerate(deleted_order):
    if i == N - 1:
        print(f"{num}>")
    else:
        print(num, end=", ")
