#include "array.h"

int main() {
	Array<int, 3> array {123,133,144};
	Array<int, 3> array2 {1,1,1};

	std::cout << "Array1: ";
	for (auto& i : array) {
		std::cout << i << " ";
	}	
	std::cout << std::endl;

	std::cout << array.at(0) << std::endl;
	std::cout << array.size() << std::endl;

	std::cout << "Array1 with reversed iterators: ";
	for (auto it = array.rbegin(); it != array.rend(); it--) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << std::boolalpha << "Array1<Array2: " << array.operator<(array2) << std::endl;
	std::cout << std::boolalpha << "Array1<=Array2: " << array.operator<=(array2) << std::endl;
	std::cout << std::boolalpha << "Array1>Array2: " << array.operator>(array2) << std::endl;
	std::cout << std::boolalpha << "Array1>=Array2: " << array.operator>=(array2) << std::endl;
	std::cout << std::boolalpha << "Array1==Array2: " << array.operator==(array2) << std::endl;
	std::cout << std::boolalpha << "Array1!=Array2: " << array.operator!=(array2) << std::endl;

	Array<float, 0> array3;

	std::cout << std::boolalpha << array3.empty() << std::endl;

	Array<int, 5> array4;
	array4.fill(1);
	std::cout << "Array 4: ";
	for (int i : array4) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	
	Array<int, 3> array5 = array;
	std::cout << "Array 5: ";
	for (auto i : array5) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	array += array2;
	for (auto i : array) {
		std::cout << i << " ";
	}

	return 0;
}