#include <iostream>

int main (int argc, char **argv) {
	//static_cast:
	int x = 8, y = 9;
	double z = static_cast<double>(x) / y;
	std::cout << z << std::endl;

	//const_cast:
	const char cc = 'x';
	const char *ccp = &cc;//*ccp cannot be modified
	char *cp = const_cast<char*>(ccp);//*cp can be modified
	*cp = 'y';
	std::cout << *cp << std::endl;

	//reinterpret_cast:
	int i = 90;
	int *ip = &i;
	char *cpx = reinterpret_cast<char*>(ip);
	std::cout << cpx << std::endl;

	return 0;
}