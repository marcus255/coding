// smart_pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <memory>

class Dog {
	std::string _name;
public:
	Dog() { _name = "nameless_dog"; };
	Dog(std::string n) : _name{ n } { std::cout << _name << " is created\n"; }
	~Dog() { std::cout << _name << " is destroyed\n"; }
	void bark() { std::cout << _name << ": bark!\n"; }
};

void shared_foo() {
	/* Shared pointer */
	// An object should be assigned to smart pointer as soon as it is created
	// Raw pointer should not be used
	std::shared_ptr<Dog> dog(new Dog("Ahmed"));
	std::cout << dog.use_count() << std::endl;
	dog->bark();
	{
		std::shared_ptr<Dog> dog2 = dog;
		std::cout << dog.use_count() << std::endl;
		dog2->bark();
	}
	std::cout << dog.use_count() << std::endl;
	// Dog* p = dog.get() // raw pointer can be taken from shared pointer
}

void shared_bar() {
	// ptr with default deleter
	std::shared_ptr<Dog> dog1 = std::make_shared<Dog>("Azor");
	// ptr with custom deleter
	std::shared_ptr<Dog> dog2(new Dog("Baca"), [](Dog* p) { std::cout << "Custom deleter\n"; delete p; });
	dog1 = dog2; // As no pointer points to dog1, it is destroyed
	//dog1 = nullptr; // will also delete dog1
	//dog1.reset();   // will also delete dog1
	dog1->bark();
	dog2->bark();

	//custom deleter is important when we create array of objects
	// std::shared_ptr<Dog> dogs(new Dog[3]); // dogs[0] will be deleted after end of scope, dogs[1] and dogs[2] will cause mem leak
	// Correct usage: whole array will be deleted
	std::shared_ptr<Dog> dogs2(new Dog[3], [](Dog *p) {delete[] p; }); 
}

void unique_foo() {
	std::unique_ptr<Dog> dog = std::make_unique<Dog>("Cezar");
	dog->bark();
	// No need to delete
	// Dog* p = dog.release() // if we release dog ptr, then nobody owes it and it wont be deleteed automaticaly
}

int main()
{
	shared_foo();
	std::cout << std::endl;
	shared_bar();
	std::cout << std::endl;

	unique_foo();
	std::cout << std::endl;

	// Another preffered way of creating shared pointer. Faster and safer than previous way
	// Only default deleter can be called in such case
	std::shared_ptr<Dog> dog3 = std::make_shared<Dog>("Burek");
	dog3->bark();

	// Raw pointer
	Dog *ptr = new Dog("not_freed_doggie");
	delete ptr; // Must be freed!!!

    return 0;
}

