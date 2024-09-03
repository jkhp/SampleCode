#include <iostream>
using namespace std;

template <typename T>
T TestFunc(T a)
{
	std::cout << "매개변수 a: " << a << std::endl;

	return a;
}

int main(int argc, char* argv[]) {
	//std::cout << "int	" << TestFunc(3) << std::endl;

	const char* s("Hello");
	cout << *s << endl;

	return 0;
}