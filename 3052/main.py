import sys
numbers = []
for i in range(10):
    numbers.append(int(sys.stdin.readline()))
remainders = []
for number in numbers:
    remainders.append(number % 42)
print(len(set(remainders)))
