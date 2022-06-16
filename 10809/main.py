S = input()
english_characters = "abcdefghijklmnopqrstuvwxyz"
for english_character in english_characters:
    if(english_character not in S):
        print("-1", end=" ")
        continue
    else:
        for i, character_in_word in enumerate(S):
            if(english_character == character_in_word):
                print(i, end=" ")
                break
