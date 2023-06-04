#pragma once
#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

void swap(int* arr, int i, int j);

namespace SortTestHelp {
	// 生成有n个元素的随机数组，每个元素的随机范围为 [rangeL, rangeR]
	int* generateRandomArray(int n, int rangeL, int rangeR);

	// 复制数组
	int* copyIntArray(int* arr, int n);

	// ============== 一些模板函数 ==================

	// 输出数组元素
	template<typename T>
	void printArray(T* arr, int n) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	// 测试数组是否有序
	template<typename T>
	bool isSorted(T* arr, int n)
	{
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				return false;
			}
		}

		return true;
	}

	// 输出排序算法排序的时间，以及测试数组是否有序
	template<typename T>
	void testSort(const string& sortName, void (*sort)(T*, int), T* arr, int n)
	{
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();

		cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << "s; ";

		bool ans = isSorted(arr, n);
		cout << "is arr sorted? Ans: " << ans << "; arr size is " << n << "." << endl;
		assert(ans);
	}

	// 输出排序算法排序的时间，以及测试数组是否有序
	template<typename T>
	void testSort(const string& sortName, void (*sort)(T*, int, int), T* arr, int n, int len = 15)
	{
		clock_t startTime = clock();
		sort(arr, n, len);
		clock_t endTime = clock();

		cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << "s; ";

		bool ans = isSorted(arr, n);
		cout << "is arr sorted? Ans: " << ans << "; arr size is " << n << "." << endl;
		assert(ans);
	}
}