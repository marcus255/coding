#include <stdio.h>

typedef unsigned long long uint64;

uint64 possible_sets_iterative(uint64 cents);
uint64 possible_sets_iterative_n2(uint64 cents);
uint64 possible_sets_iterative_linear(uint64 cents);

const int coins[] = {25, 10, 5, 1};

int main()
{
#if 0
	for (uint64 i = 1; i < 10000; i++){
        uint64 a = possible_sets_iterative_n2(i);
        uint64 b = possible_sets_iterative_linear(i);
        if (a != b)
		printf("   f(%llu) = %llu %s %llu\n", i, b, a!=b ? "\tNOT EQUAL TO " : "", a);
    }   
#endif
    
    for (uint64 i = 1; i < 1ULL << 30; i <<= 1){
        uint64 a = possible_sets_iterative_linear(i);
		printf("f(%llu) = %llu\n", i, a);
    }     
	return 0;
}

uint64 possible_sets_iterative_linear(uint64 cents)
{
	uint64 sets = 0;
    uint64 n, max, min, sum;
    cents = cents - cents % 5 + 5; // make this divisible by 5
    for(int i = cents; i > 0; i -= 25){
        max = i - (i % 10);
        min = 10;
        n = max / 10;
        if (n % 2) {   // n is odd
            sum = (min + max) / 2 + (min + max) * n/2;
            if (!(i%10)) sum -= 5*n + 5; 
        }
        else {         // n is even
            sum = (min + max) * n/2;
            if (!((i+25)%10)) sum += 5*n + 5; 
        }      
        sets += sum / 5 + (n ? n + 1 : 1) * ((i % 5) ? 1 : 0);        
    } 
	return sets;
}

uint64 possible_sets_iterative_n2(uint64 cents)
{
	uint64 sets = 0;
    for(int i = cents + 1; i > 0; i -= 25){
        for(int j = i; j > 0; j -= 10){
            sets += (j / 5 + ((j % 5) ? 1 : 0));
        }
    }
	return sets;
}

uint64 possible_sets_iterative(uint64 cents)
{
	uint64 sets = 0;
    for(int i = cents + 1; i > 0; i -= 25){
        for(int j = i; j > 0; j -= 10){
            for(int k = j; k > 0; k -= 5){
                sets += 1;
            }
        }
    }
	return sets;
}