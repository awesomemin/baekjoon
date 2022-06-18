N = int(input())
have_answer = False
for i in range(1, N):
    digits = [int(d) for d in list(str(i))]
    if(N == i + sum(digits)):
        print(i)
        have_answer = True
        break
if(not have_answer):
    print("0")
