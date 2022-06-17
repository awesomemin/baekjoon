identity_number = list(map(int, input().split()))
verify_number = sum(map(lambda x: x ** 2, identity_number)) % 10
print(verify_number)
