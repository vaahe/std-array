#include "array.h"

int main() {
	Array<int, 3> array{123,133,144};
	Array<int, 3> array2 {1,1,1,1};
	
	for (std::size_t i = 0; i < array.size(); i++) {
		std::cout << array[i] << " ";
	}
	return 0;
}