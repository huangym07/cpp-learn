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

	Test __attribute__((unused)) test1 = create_test();
	Test __attribute__((unused))  test2 = create_test_2();

	return 0;
}
