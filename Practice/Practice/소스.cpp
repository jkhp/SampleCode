#include <iostream>

template <typename T>
T TestFunc(T a)
{
	std::cout << "�Ű����� a: " << a << std::endl;

	return a;
}

int main(int argc, char* argv[]) {
	std::cout << "int	" << TestFunc(3) << std::endl;

	return 0;
}