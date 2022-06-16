studnets_complete_assignment = []
current_student = 0
for i in range(28):
    studnets_complete_assignment.append(int(input()))
studnets_complete_assignment.sort()

for i in range(1, 30 + 1):
    if(i not in studnets_complete_assignment):
        print(i)
