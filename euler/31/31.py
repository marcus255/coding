
coins = [200, 100, 50, 20, 10, 5, 2, 1]
total = 200

sets = 0
temp_coins = coins
coin_sum = total
for i in range(0, coin_sum // coins[0] + 1):
	if (coin_sum - i*coins[0]) > 0:
		coin_sum1 = coin_sum - i*coins[0]
		for i in range(0, coin_sum1 // coins[1] + 1):
			if (coin_sum1 - i*coins[1]) > 0:
				coin_sum2 = coin_sum1 - i*coins[1]
				for i in range(0, coin_sum2 // coins[2] + 1):
					if (coin_sum2 - i*coins[2]) > 0:
						coin_sum3 = coin_sum2 - i*coins[2]
						for i in range(0, coin_sum3 // coins[3] + 1):
							if (coin_sum3 - i*coins[3]) > 0:
								coin_sum4 = coin_sum3 - i*coins[3]
								for i in range(0, coin_sum4 // coins[4] + 1):
									if (coin_sum4 - i*coins[4]) > 0:
										coin_sum5 = coin_sum4 - i*coins[4]
										for i in range(0, coin_sum5 // coins[5] + 1):
											if (coin_sum5 - i*coins[5]) > 0:
												coin_sum6 = coin_sum5 - i*coins[5]
												for i in range(0, coin_sum6 // coins[6] + 1):
													if (coin_sum6 - i*coins[6]) > 0:
														coin_sum7 = coin_sum6 - i*coins[6]
														for i in range(0, coin_sum7 // coins[7] + 1):
															if (coin_sum7 - i*coins[7]) > 0:
																coin_sum8 = coin_sum7- i*coins[7]
															else:
																sets += 1
													else:
														sets += 1
											else:
												sets += 1
									else:
										sets += 1
							else:
								sets += 1
					else:
						sets += 1
			else:
				sets += 1
	else:
		sets += 1

print(str(sets))

