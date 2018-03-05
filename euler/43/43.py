primes = [2, 3, 5, 7, 11, 13, 17]
pandigital_nums = []

digits = '987654321'

pdg = 0
print(str(pdg))

sum_of_pandigital = 0
for number in range(1023456789, 9876543210):
	if ''.join(sorted(str(number))) == '0123456789':
		#print(str(number))
		for i in range(1, 8):
			subnum = int(str(number)[i:i+3])
			if (subnum % primes[i - 1]):
				break
			elif i == 7:
				sum_of_pandigital += number
				print(str(number))

print('Sum of pandigal numbers: ' + str(sum_of_pandigital))