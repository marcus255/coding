irrational = ['.']
counter = 1

while len(irrational) < 1000002:
	irrational += str(counter)
	counter += 1

product = 1
indexes = [1, 10, 100, 1000, 10000, 100000, 1000000]
for i in indexes:
	product *= int(irrational[i])
	print(irrational[i] + ' ')

print('Product is: ' + str(product))