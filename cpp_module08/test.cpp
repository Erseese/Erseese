#include <iostream>
#include <vector>

int	main(void)
{
	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(100);
	numbers.push_back(10);
	numbers.push_back(70);
	numbers.push_back(2);
	numbers.insert(numbers.begin(), 7);
	int num2 = numbers.size();
	std::cout << num2 << std::endl;
	return 0;
}