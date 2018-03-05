#include <iostream>

unsigned perimiter;
unsigned a, b, c;
int max_solutions = 0, solutions;
int max_solut_perim = 3; 

int main(){
	for (perimiter = 3; perimiter < 1001; perimiter++){
		solutions = 0;
		for (a = 1; a < perimiter / 2; a++){
			for (b = 1; b < perimiter / 2; b++){
				c = perimiter - (a + b);
				if ((a * a + b * b) == (c * c))
					solutions++;//printf("%d, %d, %d\n", a, b, c);
			}
		}
		if (solutions > max_solutions) {
			max_solutions = solutions;
			max_solut_perim = perimiter;
		}
	}
	printf("Solutions: %d, perimiter for max solutions: %d\n", max_solutions / 2, max_solut_perim);

	return 0;
}