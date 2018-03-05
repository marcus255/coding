def isPrime2(Number):
    return 2 in [Number,2**Number%Number]

def isPrime(n):
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            return False
    return True

num = 11
primes_sum = 0
primes_count = 0;
while(primes_count < 11):
	if isPrime(num):
		temp_num = num
		temp_num_2 = num
		while temp_num > 9 and temp_num_2 > 9:
			temp_num = temp_num // 10
			temp_num_2 = temp_num_2 - int(str(temp_num_2)[0] + '0' * (len(str(temp_num_2)) - 1))
			if not (isPrime(temp_num) and isPrime(temp_num_2)):
				break
		if temp_num in [2, 3, 5, 7] and temp_num_2 in [2, 3, 5, 7]:
			primes_count += 1
			primes_sum += num
			print('{}: {}'.format(primes_count, num))
	num += 1

print('The sum of these primes is ' + str(primes_sum))

