#include "util.h"

void swap(int* arr, int i, int j) 
{
	if (arr[i] == arr[j]) return;

	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

namespace SortTestHelp {
	// 生成有n个元素的随机数组，每个元素的随机范围为 [rangeL, rangeR]
	int* generateRandomArray(int n, int rangeL, int rangeR) {

		assert(rangeL <= rangeR);

		int* arr = new int[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}

		return arr;
	}

	// 复制数组
	int* copyIntArray(int* arr, int n)
	{
		int* copyArr = new int[n];
		copy(arr, arr + n, copyArr);
		return copyArr;
	}
}