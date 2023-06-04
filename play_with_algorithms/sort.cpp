#include "sort.h"

void selection_sort(int* arr, int n)
{
	for (int i = 0; i < n; i++) {
		int minIdx = i;
		//  Ѱ��[i, n)���������Сֵ
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIdx]) {
				minIdx = j;
			}
		}
		// ������Сֵ��i����
		swap(arr, i, minIdx);
	}
}

void insertion_sort(int* arr, int n)
{
	for (int i = 1; i < n; i++) {
		// �ݴ�������Ԫ�ص�ֵ
		int temp = arr[i];
		int j;
		// Ѱ��arr[i]���ʵĲ���λ��
		for (j = i; j > 0 && temp < arr[j - 1]; j--) {
			arr[j] = arr[j - 1];
		}

		arr[j] = temp;
	}
}

// �鲢����ĺϲ��㷨
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

// �ݹ�ʹ�ù鲢���򣬶�arr[l...r]�ķ�Χ��������
void _merge_sort(int* arr, int l, int r, int len)
{
	/*if (l >= r) {
		return;
	}*/

	// �Ż���2��ʹ��insertion_sort��������������ʱ�����
	if (r - l <= len) {
		insertion_sort(arr + l, r - l + 1);
		return;
	}

	int mid = (l + r) / 2;
	_merge_sort(arr, l, mid, len);
	_merge_sort(arr, mid + 1, r, len);

	// �Ż���1: ���ڽ������������ʱ����Ч��
	// ���arr[mid] <= arr[mid+1]ʱ���ǲ���Ҫmerge�ġ�
	// ��ô��⣺��Ϊ��ջ����arr[l...mid]��arr[mid]һ�������ģ�ͬ��arr[mid+1...r]�У�arr[mid+1]һ������С��
	// ��ʱ�����arr[mid] <= arr[mid+1]������Ҫ�鲢arr[l...r]
	if (arr[mid] > arr[mid + 1]) {
		_merge(arr, l, mid, r);
	}
}

void merge_sort(int* arr, int n, int len)
{
	_merge_sort(arr, 0, n - 1, len);
}

// ���������partition����
int _partition(int* arr, int l, int r)
{
	//int v = arr[l];
	// �Ż���1�����ѡ��v��������ֵݹ������˲�ƽ����������
	swap(arr, l, rand() % (r - l + 1) + l);
	int v = arr[l];

	int j = l; // jָ����߲��ֵ����һ��Ԫ��

	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < v) {
			swap(arr, j + 1, i);
			j++;
		}
	}

	swap(arr, l, j);

	return j;
}

// ���������partition����
// �Ż���3��˫�˵Ŀ��������ܱ���������������ظ�Ԫ��ʱ���ݹ������˲�ƽ���������֡�����ͬʱ�ȶԣ��ܾ�������ֵͬv��ͬ��Ԫ�ء�
int _partition2(int* arr, int l, int r)
{
	//int v = arr[l];
	// �Ż���1�����ѡ��v��������ֵݹ������˲�ƽ����������
	swap(arr, l, rand() % (r - l + 1) + l);
	int v = arr[l];

	// arr[l+1...i] <= v <= arr[j...r]
	int i = l + 1, j = r;
	while (true)
	{
		while (i <= r && arr[i] < v) i++;
		while (j >= l + 1 && arr[j] > v) j--;

		// ��ʱarr[i] >= v && arr[j] <= v����������
		if (i > j) break;
		if (arr[i] != arr[j]) {
			swap(arr, i, j);
		}
		i++;
		j--;
	}

	swap(arr, l, j);
	return j; // ��ʱ j < i
}

// ��arr[l...r]���п�������
void _quick_sort(int* arr, int l, int r)
{
	/*if (l >= r) {
		return;
	}*/

	// �Ż���2��ʹ��insertion_sort��������������ʱ�����
	if (r - l <= 15) {
		insertion_sort(arr + l, r - l + 1);
		return;
	}

	//int p = _partition(arr, l, r); // ��partition��arr[l...p-1] < arr[p] <= arr[p+1...r]
	int p = _partition2(arr, l, r); // ��partition2��arr[l...p-1] <= arr[p] <= arr[p+1...r]
	_quick_sort(arr, l, p - 1);
	_quick_sort(arr, p + 1, r);
}

void quick_sort(int* arr, int n)
{
	// ����������ӣ������Ż�v��ѡ��
	srand(time(NULL));
	_quick_sort(arr, 0, n - 1);
}

// �����������·���ţ��԰����ظ�Ԫ�رȽ϶��Ԫ��Ч����
// �Ż���4��arr[l+1...lt] < v; arr[lt+1...i-1] == v; arr[gt...r] > v
void _quick_sort3(int* arr, int l, int r)
{
	/*if (l >= r) {
		return;
	}*/

	// �Ż���2��ʹ��insertion_sort��������������ʱ�����
	if (r - l <= 15) {
		insertion_sort(arr + l, r - l + 1);
		return;
	}

	//int v = arr[l];
	// �Ż���1�����ѡ��v��������ֵݹ������˲�ƽ����������
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
	// ����������ӣ������Ż�v��ѡ��
	srand(time(NULL));
	_quick_sort3(arr, 0, n - 1);
}