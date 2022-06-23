N = int(input())

bag_5kg = N // 5
bag_3kg = 0

is_available = False

while bag_5kg >= 0:
    if (N - (5 * bag_5kg)) % 3 == 0:
        bag_3kg = (N - (5 * bag_5kg)) // 3
        print(bag_5kg + bag_3kg)
        is_available = True
        break
    else:
        bag_5kg -= 1

if is_available == False:
    print(-1)
