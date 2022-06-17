N = int(input())
words = []
for i in range(N):
    words.append(input())
words = set(words)
words = list(words)
words.sort(key=len)

cur_word_length = len(words[0])
temp_words = []
words_sorted = []
for word in words:
    if(len(word) == cur_word_length):
        temp_words.append(word)
    else:
        words_sorted.append(temp_words)
        temp_words = []
        temp_words.append(word)
        cur_word_length = len(word)
    if (words[-1] == word):
        words_sorted.append(temp_words)

for same_digit_words in words_sorted:
    same_digit_words.sort()
    for word in same_digit_words:
        print(word)
