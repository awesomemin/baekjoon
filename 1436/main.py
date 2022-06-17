N = int(input())
result = ""
cur_number = 1
cur_doom_number = 0
number_found_doom_number = 0
while True:
    if "666" in str(cur_number):
        number_found_doom_number += 1
        cur_doom_number = cur_number
    if number_found_doom_number == N:
        break
    cur_number += 1
print(cur_doom_number)
