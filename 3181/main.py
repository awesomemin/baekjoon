sentence = input().split()

words = {'i', 'pa', 'te', 'ni', 'niti', 'a', 'ali', 'nego', 'no', 'ili'}

for i, word in enumerate(sentence):
    if i == 0:
        print(word[0].upper(), end="")
    else:
        if word not in words:
            print(word[0].upper(), end="")
