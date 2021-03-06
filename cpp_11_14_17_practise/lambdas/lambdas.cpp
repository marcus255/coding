#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <time.h>

void lambdaSort();
class Point {
public:
	int x;
	int y;
	Point() : x{ rand() % 100 }, y{ rand() % 100 } {}
};

int main()
{
	srand(time(NULL));
	std::vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// use anonymous lambda
	int mod3_count = std::count_if(v.begin(), v.end(), [](int x) {return !(x % 3); });
	printf("mod3_sum is %d\n", mod3_count);

	// place referenced variables inside square brackets, use '[=]' to capture all variables
	// use reference operator to modify captured values
	int odd_sum = 0, mod = 2;
	std::for_each(std::begin(v), std::end(v), [&odd_sum, mod](int x) { odd_sum += x % mod ? x : 0; });
	printf("odd sum is %d\n", odd_sum);

	// use '-> type' to specify return type
	int mod2or3count = std::count_if(v.begin(), v.end(), 
		[] (int x) -> bool 
		{
			bool r = false; 
			r = !(x % 2 && x % 3); 
			return r; 
		}
	);
	printf("mod2or3count is %d\n", mod2or3count);

	// create handle to lambda function
	auto addNums = [](int a, int b) -> float {return a + b; };
	printf("addNums(3, 4) is %0.2f\n", addNums(3, 4));
		
	lambdaSort();

	return 0;
}

void lambdaSort() {
	std::vector<Point> points;
	for (int i = 0; i < 10; i++) {
		points.push_back(Point());
		printf("(%d,%d)\n", points[i].x, points[i].y);
	}
	std::sort(points.begin(), points.end(), [](Point p1, Point p2) -> bool {
		return (p1.x*p1.x + p1.y*p1.y < p2.x*p2.x + p2.y*p2.y);
	});
	for(auto p : points)
		printf("(%d,%d) = %d\n", p.x, p.y, (p.x*p.x+p.y*p.y));
}
