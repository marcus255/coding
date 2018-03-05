

for num in range (10, 99):
	for den in range (10, 99):
		fract = num / den
		num_str = str(num)
		den_str = str(den)
		if num != den and num_str[1] == den_str[0]:
			ln = list(num_str)
			ld = list(den_str)
			del ln[-1]
			del ld[0]
			if int(''.join(ld)) and (int(''.join(ln)) / int(''.join(ld)) == fract):
				print('num: {} denom: {}'.format(num, den))
