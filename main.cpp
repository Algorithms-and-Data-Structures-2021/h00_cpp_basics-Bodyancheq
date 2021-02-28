#include <iostream>  // cout

#include "tasks.hpp"

using namespace std;

int main() {
	int num_rows = 3;
	int num_cols = 7;
	// [указатель 0, указатель 1, указатель 2]
	int **array_2d1 = new int *[num_rows];
	for (int row_index = 0; row_index < num_rows; ++row_index) {
		array_2d1[row_index] = new int[num_cols] {1, 1, 1, 1, 1, 1, 1};  // с инициализацией
	}
	
	int **array_2d2 = new int *[num_rows];
	for (int row_index = 0; row_index < num_rows; ++row_index) {
		array_2d2[row_index] = new int[num_cols];
	}

	copy_2d_array(array_2d1, array_2d2, num_rows, num_cols);
	
	for (int row_index = 0; row_index < num_rows; row_index++) {
		for (int column_index = 0; column_index < num_cols; column_index++) {
			cout << array_2d2[row_index][column_index] << '\t';
		}
		cout << endl;
	}
	
	
	for (int row_index = 0; row_index < num_rows; row_index++) {
		delete[] array_2d1[row_index];
	}
	for (int row_index = 0; row_index < num_rows; row_index++) {
		delete[] array_2d2[row_index];
	}
	
	int x;
	cin >> x;
	delete[] array_2d1;
	delete[] array_2d2;
    return 0;
}