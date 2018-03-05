triangle_nums = []
for i in range(1, 27):
	triangle_nums.append((i * (i + 1)) // 2)

text = []
with open('p042_words.txt', 'r') as file:
	text = file.read()
words = text.replace('"', '').split(",")

triangle_words = 0
for word in words:
	val = 0
	for char in word:
		val += (ord(char) - ord('@'))
	if val in triangle_nums:
		triangle_words += 1

print('Number of triangle words in file: ' + str(triangle_words))