import collections
import sys
input = sys.stdin.readline
N = int(input())
numbers = list(map(int, input().split()))
M = int(input())
targets = list(map(int, input().split()))

check_number = collections.Counter(numbers)

for target in targets:
    if(check_number[target] == 0):
        print("0")
    else:
        print("1")
