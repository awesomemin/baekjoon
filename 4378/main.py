from operator import indexOf
import sys


first_row = ["`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "="]
second_row = ["Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]", "\\"]
third_row = ["A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "\'"]
fourth_row = ["Z", "X", "C", "V", "B", "N", "M", ",", ".", "/"]

for line in sys.stdin:
    user_input = line
    result = ""
    for char in user_input:
        if char == " ":
            result += char
        elif char in first_row:
            result += first_row[indexOf(first_row, char) - 1]
        elif char in second_row:
            result += second_row[indexOf(second_row, char) - 1]
        elif char in third_row:
            result += third_row[indexOf(third_row, char) - 1]
        elif char in fourth_row:
            result += fourth_row[indexOf(fourth_row, char) - 1]
    print(result)
