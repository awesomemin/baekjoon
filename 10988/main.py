str_input = input()
str_ls = list(str_input)
str_ls.reverse()
str_rv = "".join(str_ls)
if(str_input == str_rv):
    print("1")
else:
    print("0")
