word = input()
word = word.lower()
char_to_frequency = {}
for char in word:
    if char in char_to_frequency:
        char_to_frequency[char] += 1
    else:
        char_to_frequency[char] = 1
most_frequency = 0
most_character = ""
two_same_most = False
for char in char_to_frequency:
    if char_to_frequency[char] > most_frequency:
        most_frequency = char_to_frequency[char]
        most_character = char
        two_same_most = False
    elif char_to_frequency[char] == most_frequency:
        two_same_most = True
if(two_same_most):
    print("?")
else:
    print(most_character.upper())
