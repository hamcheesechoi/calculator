#include <vector>

class cal {
public:
	int getSum(int a, int b) {
		return a + b;
	}

	std::vector<int> get_absolute_sum(std::vector<int> v) {
		std::vector<int> abs_vector;

		for (int element : v) {
			if (element < 0) abs_vector.push_back(element * -1);
			else abs_vector.push_back(element);
		}
		return abs_vector;
	}
};

