#include <iostream>
#include <memory>

class TMP {
 public:
	TMP(int a, int b) : a_(a), b_(b) {}

	friend std::ostream& operator << (std::ostream &out, TMP &tmp) {
		out << tmp.a_ << " " << tmp.b_;

		return out;
	}

 private:
	int a_, b_;
};

int main() {
	auto uptr = std::make_unique<TMP>(10, 20);

	std::cout << (*uptr.get()) << std::endl;

	return 0;
}
