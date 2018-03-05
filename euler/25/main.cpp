#include <iostream>
#include <gmpxx.h>

mpz_class t1 = 1, t2 = 1, temp;
mpz_class i = 0;
mpz_class counter = 0;
int main(){
	while(++counter && i < 1001) {
		temp = t2;
		t2 += t1;
		t1 = temp;
		if (t2 > [](mpz_class x){mpz_class iter = x; mpz_class res = 1; while (iter--) res *= 10; return res;}(i))
			std::cout << "digits: " << ++i << " term: " << counter + 2 << " sum: " << t2 << std::endl;
	}

	return 0;
}
