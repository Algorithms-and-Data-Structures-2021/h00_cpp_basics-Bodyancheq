#include <iostream>  // cout

#include "tasks.hpp"

using namespace std;

int main() {
	vector<int> arr_a;
	arr_a.push_back(1);
	arr_a.push_back(3);
	arr_a.push_back(2);
	arr_a.push_back(2);
	arr_a.push_back(1);

	vector<int> arr_b;
	arr_b.push_back(1);
	arr_b.push_back(2);
	arr_b.push_back(3);
	arr_b.push_back(5);


	vector<int> arr = find_common_elements(arr_a, arr_b);
	
	for (auto x : arr) {
		cout << x << '\t';
	}
	
	int y;
	cin >> y;
    return 0;
}