#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>

int main (int argc, char **argv) {
	//Use 'std::function' to declare a function pointer(C++11):
	std::function<double(double, double)> multiply;
	//Define lambda(C++11):
	multiply = [] (double x, double y) -> double {//So, a lambda's type is 'std::function'
		return x * y;
	};
	std::cout << multiply(1.234, 5.6789) << std::endl;
	
	//In C++14, even the parameters' type can be `auto`:
	auto multiplyX = [] (auto x, auto y) {
		return x * y;
	};
	std::cout << multiplyX(-1234, 5.6789) << std::endl;

	double pi = 3.14;
	/*
	Capture variables outside of the lambda:
	'[]':        Capture nothing;
	'[=]':       Capture all variables by making a copy;
	'[var]'      Capture the variable 'var' by making a copy.
	'[&]':       Capture all variables by reference;
	'[&var]'     Capture the variable 'var' by reference;
	'[=, &var]': Capture all variables by making a copy, but capture the variable 'var' by reference;
	'[&, var]':  Capture all variables by reference, but capture the variable 'var' by making a copy;
	While capturing a variable by reference, it can be modified if it's not a 'const'.
	*/
	auto circleSpace = [=, &pi] (double radius) -> double {
		pi = 3.1415926535;
		return pi * radius * radius;
	};
	std::cout << circleSpace(1.23456789) << std::endl;

	//We can also add a 'mutable' keyword after the parameters-list if we wanna modify the variables:
	auto circleSpaceM = [=] (double radius) mutable -> double {
		pi = 3.1415926535;
		return pi * radius * radius;
	};
	std::cout << circleSpaceM(1.23456789) << std::endl;

	//In C++14, the capturing can be a initializing expression.
	//So you can capture a move-only variable:
	std::unique_ptr<std::string> nameP(new std::string("Rinc"));
	auto readName = [nameP = move(nameP)] {
		return *nameP;
	};
	//Of cource you can release it as well:
	/*
	auto readName = [nameP = nameP.release()] {
		return *nameP;
	};
	*/
	std::cout << readName() << std::endl;

	//In C++14, you can initialize more than one variables:
	std::shared_ptr<std::string> str1, str2;
	auto print = [
		str1 = std::make_shared<std::string>("Rinc"), 
		str2 = std::make_shared<std::string>("Liu")
		] () { 
		std::cout << *str1 << " " << *str2 << std::endl;
	};
	print();

	std::vector<char> v;
	for (int i = 0; i < 26; i++) {
		v.push_back((char)('A' + i));
	}
	//Use lambda with 'for_each' template:
	for_each(v.begin(), v.end(), [] (char c) -> void {
		std::cout << c << std::endl; 
	});

	return 0;
}