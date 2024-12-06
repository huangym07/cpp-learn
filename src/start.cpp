#include <iostream>

class Test {
	public:
		Test(): a(10) {}
	public:
		int a;
};

Test create_test() {
	return Test();
}

Test create_test_2() {
	Test test;

	return test;
}

int main() {
	std::cout << "Just a test" << '\n';

	// Test __attribute__((unused)) test1 = create_test();
	// Test __attribute__((unused))  test2 = create_test_2();
	
	const int a = 10;
	std::cout << "const int a is " << a << '\n';

	int *pa = (int *)&a;
	std::cout << "*pa is " << *pa << '\n';

	*pa = 20;
	std::cout << "*pa is " << *pa << '\n';

	std::cout << "a is " << a << '\n';
	std::cout << "a is " << *(&a) << '\n';

	const int c = a * 5;
	std::cout << "c is " << c << '\n';

	int *pc = (int *)&c;
	*pc = 500;

	std::cout << "*pc is " << *pc << '\n';

	std::cout << "c is " << c << '\n';
	std::cout << "c is " << *(&c) << '\n';

	return 0;
}
