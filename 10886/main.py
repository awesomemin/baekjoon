N = int(input())
votes = []
for i in range(N):
    vote = int(input())
    votes.append(vote)
if(votes.count(0) > votes.count(1)):
    print("Junhee is not cute!")
else:
    print("Junhee is cute!")
