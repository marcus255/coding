// cpp_11_14_17_practise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <iterator>
#include <array>
#include <set>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <random>

void algorithms();

int main()
{
	/* vector */
	std::vector<int> vec = { 3, 4, 5 };
	for (auto& it : vec)
		it++;
	for (auto it : vec)
		std::cout << it << " ";
	std::cout << std::endl;

	/* list */
	std::list<std::string> list = { "Car", "Plane", "Car", "Bike" };
	list.push_back("Back");
	list.push_front("Front");
	list.sort();
	list.unique();
	std::list<std::string>::iterator it;
	for (it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	/* stack */
	// no initializer list
	// no random access
	std::stack<int> stack;
	stack.push(3);
	stack.push(5);
	stack.push(8);
	auto s = stack.size();
	for (int i = 0; i < s; i++) {
		std::cout << stack.top() << " ";
		stack.pop();
	}
	std::cout << std::endl;

	/* queue */
	// no initializer list
	// no random access
	std::queue<int> queue;
	queue.push(3);
	queue.push(5);
	queue.push(8);
	s = queue.size();
	for (int i = 0; i < s; i++) {
		std::cout << queue.front() << " ";
		queue.pop();
	}
	std::cout << std::endl;

	/* deque - double ended queue */
	// initializer list
	// has random access
	// can insert elements
	std::deque<int> deq = { 8, 4, 6, 8 };
	deq.push_back(10);
	deq.push_front(2);
	std::deque<int>::iterator dit = deq.begin() + 1;
	deq.insert(dit, 6);
	for (auto i = 0; i < deq.size(); i++)
		std::cout << deq.at(i) << " ";
	std::cout << std::endl;

	/* array */
	std::array<int, 5> array = { 1, 2, 3, 4, 5 };
	for (auto &a : array)
		a *= 2;
	for (auto a : array)
		std::cout << a << " ";
	std::cout << std::endl;

	/* set */
	// multiple entries ignored (not ignored in multiset container)
	// elements sorted
	std::set<std::string> names = { "Marcus", "Ada" };
	names.insert("Alex");
	names.insert("Ada");
	for (auto n : names)
		std::cout << n << " ";
	std::cout << std::endl;

	/* map */
	// elements sorted
	// multiple entries allowed in multimap
	std::multimap<std::string, int> people = { {"Ada", 12 }, {"John", 40} };
	people.insert(std::make_pair("Marcus", 26));
	people.insert(std::pair<std::string, int>("John", 15));
	for (auto p : people)
		std::cout << p.first << " " << p.second << std::endl;

	/* unordered set */
	// elements not sorted
	std::unordered_set<int> numbers = { 4, 7, 4, 2, 9 };
	for (auto n : numbers)
		std::cout << n << " ";
	std::cout << std::endl << std::endl;

	algorithms();

	return 0;
}

void algorithms() {
	std::vector<int> v = { 51, 35, 88, 53, 53, 32, 98, 10 };
	for (auto elem : v)
		printf("%d ", elem);

	// count elems greater than 50
	int greater_than_50 = std::count_if(v.begin(), v.end(), [](int a) {return a > 50; });
	printf("\nGreater than 50: %d\n", greater_than_50);

	//find max and min
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> minmax;
	minmax = std::minmax_element(v.begin(), v.end());
	printf("Min: %d, max: %d\n", *minmax.first, *minmax.second);
	
	// sort by last digit
	std::sort(v.begin(), v.end(), [](int x, int y) {return x % 10 < y % 10; });
	for (auto elem : v)
		printf("%d ", elem);

	// search 2 consecutive 53's
	auto iter = std::search_n(v.begin(), v.end(), 2, 53);
	printf("\nconsecutive 53's index: %d\n", iter - v.begin());

	// shuffle vector
	auto rng = std::default_random_engine{};
	std::shuffle(v.begin(), v.end(), rng);
	for (auto elem : v)
		printf("%d ", elem);
}

