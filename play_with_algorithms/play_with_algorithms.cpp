#include <iostream>
#include "util.h"
#include "sort.h"

using namespace std;

int main()
{
	int n = 500000;
	int* arr = SortTestHelp::generateRandomArray(n, 1, n);
	int* copyArr1 = SortTestHelp::copyIntArray(arr, n);
	int* copyArr2 = SortTestHelp::copyIntArray(arr, n);
	int* repeatArr = SortTestHelp::generateRandomArray(n, 1, 10);
	int* copyRepeatArr1 = SortTestHelp::copyIntArray(repeatArr, n);
	int* copyRepeatArr2 = SortTestHelp::copyIntArray(repeatArr, n);

	SortTestHelp::printArray(copyArr1, 10);
	SortTestHelp::printArray(copyArr2, 10);
	SortTestHelp::printArray(repeatArr, 20);
	SortTestHelp::printArray(copyRepeatArr1, 20);
	SortTestHelp::printArray(copyRepeatArr2, 20);

	cout << "copyArr1 = " << copyArr1 << endl;
	cout << "copyArr2 = " << copyArr2 << endl;
	cout << "repeatArr = " << repeatArr << endl;
	cout << "copyRepeatArr1 = " << copyRepeatArr1 << endl;
	cout << "copyRepeatArr2 = " << copyRepeatArr2 << endl;


	cout << "is arr sorted? Ans: " << SortTestHelp::isSorted(arr, n) << endl;
	cout << "is copyArr1 sorted? Ans: " << SortTestHelp::isSorted(copyArr1, n) << endl;
	cout << "is copyArr2 sorted? Ans: " << SortTestHelp::isSorted(copyArr2, n) << endl;
	cout << "is repeatArr1 sorted? Ans: " << SortTestHelp::isSorted(repeatArr, n) << endl;
	cout << "is copyRepeatArr1 sorted? Ans: " << SortTestHelp::isSorted(copyRepeatArr1, n) << endl;
	cout << "is copyRepeatArr2 sorted? Ans: " << SortTestHelp::isSorted(copyRepeatArr2, n) << endl;
	cout << endl;

	//SortTestHelp::testSort("selection_sort", selection_sort, arr, n);
	//SortTestHelp::testSort("insertion_sort", insertion_sort, copyArr1, n);
	SortTestHelp::testSort("merge_sort    ", merge_sort, copyArr2, n);
	SortTestHelp::testSort("quick_sort    ", quick_sort, copyArr1, n);
	SortTestHelp::testSort("quick_sort3   ", quick_sort3, arr, n);

	cout << "\n对于差不多有序的数组，排序效果：\n" << endl;
	//SortTestHelp::testSort("selection_sort", selection_sort, arr, n);
	//SortTestHelp::testSort("insertion_sort", insertion_sort, copyArr1, n);
	SortTestHelp::testSort("merge_sort    ", merge_sort, copyArr2, n);
	SortTestHelp::testSort("quick_sort    ", quick_sort, copyArr1, n);
	SortTestHelp::testSort("quick_sort3   ", quick_sort3, arr, n);

	cout << "\n对于有很多重复元素的数组，排序效果：\n" << endl;
	SortTestHelp::testSort("merge_sort    ", merge_sort, repeatArr, n);
	SortTestHelp::testSort("quick_sort    ", quick_sort, copyRepeatArr1, n);
	SortTestHelp::testSort("quick_sort3   ", quick_sort3, copyRepeatArr2, n);

	cout << "\n对于有很多重复且差不多有序元素的数组，排序效果：\n" << endl;
	SortTestHelp::testSort("merge_sort    ", merge_sort, repeatArr, n);
	SortTestHelp::testSort("quick_sort    ", quick_sort, copyRepeatArr1, n);
	SortTestHelp::testSort("quick_sort3   ", quick_sort3, copyRepeatArr2, n);

	cout << endl;
	cout << "is arr sorted? Ans: " << SortTestHelp::isSorted(arr, n) << endl;
	cout << "is copyArr1 sorted? Ans: " << SortTestHelp::isSorted(copyArr1, n) << endl;
	cout << "is copyArr2 sorted? Ans: " << SortTestHelp::isSorted(copyArr2, n) << endl;
	cout << "is repeatArr sorted? Ans: " << SortTestHelp::isSorted(repeatArr, n) << endl;
	cout << "is copyRepeatArr1 sorted? Ans: " << SortTestHelp::isSorted(copyRepeatArr1, n) << endl;
	cout << "is copyRepeatArr2 sorted? Ans: " << SortTestHelp::isSorted(copyRepeatArr2, n) << endl;

	delete[] arr;
	delete[] copyArr1;
	delete[] copyArr2;
	delete[] repeatArr;
	delete[] copyRepeatArr1;
	delete[] copyRepeatArr2;

}
