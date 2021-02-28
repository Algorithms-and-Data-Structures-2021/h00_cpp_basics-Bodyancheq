#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

void swap_args(int *lhs, int *rhs) {
	/* обмен значений переменных по указателю.

		Требуется обрабатывать ситуации, когда указатели нулевые(функция в этом случае ничего не должна делать).
		Гарантируется, что указатели ссылаются на разные участки памяти.
		Указатели могут ссылаться на участки памяти в стеке и куче. */
	if (lhs && rhs) {
		int temp = *lhs;
		*lhs = *rhs;
		*rhs = temp;
	}
	else {
		return;
	}

}

int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
	/* выделение памяти под двумерный динамический массив определенного размера с инициализацией всех элементов одним значением.

		Требуется обрабатывать некорректные значения размера массива(в этом случае должен возвращаеться нулевой указатель).
		Все элементы массива должны быть инициализированы определенным значением. */
	if ((num_cols > 0) && (num_rows > 0)) {
		int **array_2d = new int *[num_rows];

		for (int row_index = 0; row_index < num_rows; ++row_index) {
			array_2d[row_index] = new int[num_cols];
		}

		for (int row_index = 0; row_index < num_rows; row_index++) {
			for (int column_index = 0; column_index < num_cols; column_index++) {
				array_2d[row_index][column_index] = init_value;
			}
		}

		return array_2d;
	}
	else { return nullptr; }
}

// TODO 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
	if ((num_rows > 0) && (num_rows > 0) && (arr_2d_source != nullptr) && (arr_2d_target != nullptr)) {
		for (int i = 0; i < num_rows; i++) {
			for (int j = 0; j < num_cols; j++) {
				arr_2d_target[i][j] = arr_2d_source[i][j];
			}
		}
		return true;
	}
	return false;
}

void reverse_1d_array(vector<int> &arr) {
	/*  переворот массива, все элементы должны зеркально отразиться относительно середины.

		Массив может оказаться пустым.
		Количество элементов в массиве может быть как четным, так и нечетным.
 */
	for (int i = 0; i < arr.size() / 2; i++) {
		int temp = arr[i];
		arr[i] = arr[arr.size() - 1 - i];
		arr[arr.size() - 1 - i] = temp;
	}
}


void reverse_1d_array(int *arr_begin, int *arr_end) {
	/*  переворот динамического или статического массива с использованием двух указателей на начальный и конечный элементы массива.

		Требуется обрабатывать случай, когда указатели нулевые (функция ничего не должна делать).
		Конечный указатель ссылается на последний элемент массива (ячейку памяти), а не на ячейку после неё.
 */
	while (arr_begin < arr_end) {
		int temp = *arr_begin;
		*arr_begin = *arr_end;
		*arr_end = temp;
		arr_begin++;
		arr_end--;
	}
}


int *find_max_element(int *arr, int size) {
	/*   поиск максимального элемента в одномерном массиве.

		Требуется обрабатывать случаи передачи нулевого указателя и неположительного размера. (в этом случае функций ничего не должна делать и вернуть нулевой указатель).
		Функция при успешном нахождении максимального элемента должна вернуть указатель на этот элемент.
 */
	if (arr && (size > 0)) {
		int *to_return = arr;
		int max = arr[0];
		for (int i = 1; i < size; i++) {
			if (arr[i] > max) {
				max = arr[i];
				to_return = &arr[i];
			}
		}
		return to_return;
	}
	else return nullptr;
}


vector<int> find_odd_numbers(vector<int> &arr) {
	/*   поиск нечетных чисел в динамическом массиве.

			При отсутсвии нечетных элементов, возвращается пустой массив.
			В функцию может передаваться пустой массив.
			Требуется вернуть массив, состоящий из найденнх нечетных элементов.
*/
	vector<int> odd_array;
	for (auto elem : arr) {
		if (elem % 2 != 0) odd_array.push_back(elem);
	}
	return odd_array;
}

// TODO
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
	/*   поиск общих элементов двух динамических массивах.

			Каждый из массивов может быть пустым.
			Требуется вернуть массив, состоящий из общих элементов двух массивов.
			При отсутствии общих элементов должен вернуться пустой массив.
*/
	vector<int> common_array;
	for (int i = 0; i < arr_a.size(); i++) {
		for (int j = 0; j < arr_b.size(); j++) {
			if (arr_a[i] == arr_b[j]) {
				common_array.push_back(arr_a[i]);
				arr_b[j] = NULL;
				break;
			}
		}
	}
	return common_array;
}
