import sys
input = sys.stdin.readline


def is_balanced(string):
    target_str = string
    left = 0
    right = 2
    while True:
        if len(target_str) == 0:
            return True
        if target_str[left:right] == "()" or target_str[left:right] == "[]":
            target_str = target_str[:left] + target_str[right:]
            left = 0
            right = 2
            continue
        else:
            left += 1
            right += 1
            if right >= len(target_str) + 2:
                return False


while True:
    string = input()
    adjusted_string = ""
    temp_chars = []
    if(string.rstrip() == "."):  # terminate iterate when input == "."
        break
    else:
        for char in string:  # preprocessing the string
            if(char == "(" or char == ")" or char == "[" or char == "]"):
                temp_chars.append(char)
        adjusted_string = "".join(temp_chars)
        if (is_balanced(adjusted_string)):
            print("yes")
        else:
            print("no")
