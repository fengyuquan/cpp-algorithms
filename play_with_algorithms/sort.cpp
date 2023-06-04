#include "sort.h"

void selection_sort(int* arr, int n)
{
	for (int i = 0; i < n; i++) {
		int minIdx = i;
		//  寻找[i, n)区间里的最小值
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIdx]) {
				minIdx = j;
			}
		}
		// 交换最小值到i索引
		swap(arr, i, minIdx);
	}
}

void insertion_sort(int* arr, int n)
{
	for (int i = 1; i < n; i++) {
		// 暂存待排序的元素的值
		int temp = arr[i];
		int j;
		// 寻找arr[i]合适的插入位置
		for (j = i; j > 0 && temp < arr[j - 1]; j--) {
			arr[j] = arr[j - 1];
		}

		arr[j] = temp;
	}
}

// 归并排序的合并算法
void _merge(int* arr, int l, int mid, int r)
{
	int i = l, j = mid + 1, k = 0, n = r - l + 1;
	int* tempArr = new int[n];

	while (i <= mid && j <= r)
	{
		if (arr[i] <= arr[j]) {
			tempArr[k++] = arr[i++];
		}
		else {
			tempArr[k++] = arr[j++];
		}
	}

	while (i <= mid) {
		tempArr[k++] = arr[i++];
	}

	while (j <= r) {
		tempArr[k++] = arr[j++];
	}

	for (int m = 0; m < n; m++) {
		arr[l + m] = tempArr[m];
	}

	delete[] tempArr;
}

// 递归使用归并排序，对arr[l...r]的范围进行排序
void _merge_sort(int* arr, int l, int r, int len)
{
	/*if (l >= r) {
		return;
	}*/

	// 优化点2：使用insertion_sort排序数据量不大时的情况
	if (r - l <= len) {
		insertion_sort(arr + l, r - l + 1);
		return;
	}

	int mid = (l + r) / 2;
	_merge_sort(arr, l, mid, len);
	_merge_sort(arr, mid + 1, r, len);

	// 优化点1: 对于近乎有序的数组时，有效果
	// 如果arr[mid] <= arr[mid+1]时，是不需要merge的。
	// 怎么理解：因为在栈顶，arr[l...mid]中arr[mid]一定是最大的，同理arr[mid+1...r]中，arr[mid+1]一定是最小的
	// 此时，如果arr[mid] <= arr[mid+1]，则不需要归并arr[l...r]
	if (arr[mid] > arr[mid + 1]) {
		_merge(arr, l, mid, r);
	}
}

void merge_sort(int* arr, int n, int len)
{
	_merge_sort(arr, 0, n - 1, len);
}

// 快速排序的partition操作
int _partition(int* arr, int l, int r)
{
	//int v = arr[l];
	// 优化点1：随机选择v，避免出现递归树极端不平衡的情况出现
	swap(arr, l, rand() % (r - l + 1) + l);
	int v = arr[l];

	int j = l; // j指向左边部分的最后一个元素

	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < v) {
			swap(arr, j + 1, i);
			j++;
		}
	}

	swap(arr, l, j);

	return j;
}

// 快速排序的partition操作
// 优化点3：双端的快速排序，能避免数组包含大量重复元素时，递归树极端不平衡的情况出现。两边同时比对，能尽量均分值同v相同的元素。
int _partition2(int* arr, int l, int r)
{
	//int v = arr[l];
	// 优化点1：随机选择v，避免出现递归树极端不平衡的情况出现
	swap(arr, l, rand() % (r - l + 1) + l);
	int v = arr[l];

	// arr[l+1...i] <= v <= arr[j...r]
	int i = l + 1, j = r;
	while (true)
	{
		while (i <= r && arr[i] < v) i++;
		while (j >= l + 1 && arr[j] > v) j--;

		// 此时arr[i] >= v && arr[j] <= v，交换他们
		if (i > j) break;
		if (arr[i] != arr[j]) {
			swap(arr, i, j);
		}
		i++;
		j--;
	}

	swap(arr, l, j);
	return j; // 此时 j < i
}

// 对arr[l...r]进行快速排序
void _quick_sort(int* arr, int l, int r)
{
	/*if (l >= r) {
		return;
	}*/

	// 优化点2：使用insertion_sort排序数据量不大时的情况
	if (r - l <= 15) {
		insertion_sort(arr + l, r - l + 1);
		return;
	}

	//int p = _partition(arr, l, r); // 在partition后，arr[l...p-1] < arr[p] <= arr[p+1...r]
	int p = _partition2(arr, l, r); // 在partition2后，arr[l...p-1] <= arr[p] <= arr[p+1...r]
	_quick_sort(arr, l, p - 1);
	_quick_sort(arr, p + 1, r);
}

void quick_sort(int* arr, int n)
{
	// 设置随机种子，用于优化v的选择
	srand(time(NULL));
	_quick_sort(arr, 0, n - 1);
}

// 快速排序的三路快排，对包含重复元素比较多的元素效果好
// 优化点4：arr[l+1...lt] < v; arr[lt+1...i-1] == v; arr[gt...r] > v
void _quick_sort3(int* arr, int l, int r)
{
	/*if (l >= r) {
		return;
	}*/

	// 优化点2：使用insertion_sort排序数据量不大时的情况
	if (r - l <= 15) {
		insertion_sort(arr + l, r - l + 1);
		return;
	}

	//int v = arr[l];
	// 优化点1：随机选择v，避免出现递归树极端不平衡的情况出现
	swap(arr, l, rand() % (r - l + 1) + l);
	int v = arr[l];

	int lt = l, gt = r + 1, i = l + 1;

	while (i < gt) {
		if (arr[i] < v) {
			swap(arr, lt + 1, i);
			lt++;
			i++;
		}
		else if (arr[i] > v) {
			swap(arr, gt - 1, i);
			gt--;
		}
		else {
			i++;
		}
	}

	swap(arr, l, lt);
	_quick_sort3(arr, l, lt - 1);
	_quick_sort3(arr, gt, r);
}

void quick_sort3(int* arr, int n)
{
	// 设置随机种子，用于优化v的选择
	srand(time(NULL));
	_quick_sort3(arr, 0, n - 1);
}