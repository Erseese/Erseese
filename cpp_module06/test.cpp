#include <cstdlib>
#include <iostream>

int main() {
	const char* str = "\200";
	char* endptr;
	double value = strtod(str, &endptr);

	if (*endptr != '\0')
		std::cout << "Conversion failed" << std::endl;
	else
		std::cout << "Converted value: " << value << std::endl;

	float value2 = static_cast<float>(value);
	std::cout << "Converted value: " << value2 << std::endl;

	char	value3 = static_cast<char>(value);
	std::cout << "Converted value: " << value3 << std::endl;

	value = static_cast<int>(value);
	std::cout << "Converted value: " << value << std::endl;

	return 0;
}