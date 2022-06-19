N = int(input())
nums = list(map(int, input().split()))

number_of_prime = N

for num in nums:
    if num == 1:
        number_of_prime -= 1
        continue
    elif num == 2:
        continue
    else:
        for i in range(2, num):
            if num % i == 0:
                number_of_prime -= 1
                break

print(number_of_prime)
