plates = input()
tall = 10
for i in range(1, len(plates)):
    if(plates[i - 1] == plates[i]):
        tall += 5
    else:
        tall += 10
print(tall)
