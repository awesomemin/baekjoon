string_as_list = list(input())
result_string = ""
for character in string_as_list:
    if(character.isupper()):
        result_string += character.lower()
    else:
        result_string += character.upper()
print(result_string)
