/**
*复习各种排序算法
*/#include <iostream>
#include <vector>
#include<string.h>
using namespace std;

class Sort {//从小到大排序
public:
	static void exchange(int* a,int* b) {//交换两个数据
		int temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}
	static void show(const int arr[], const int length, const char message[]) {
		cout << message << ":";
		for (int i = 0; i < length; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	//冒泡排序
	//平均复杂度:O(n2)
	//最好复杂度:O(n)(已经排好序了)
	//最坏复杂度:O(n2)
	//空间复杂度:O(1)
	//稳定性:稳定
	static void BubbleSort(const int arr[], const int length) {
		int* stat = new int[length];
		memcpy(stat, arr, length * sizeof(int));
		if (stat!=nullptr) {
			for (int i = 0; i < length; i++) {
				for (int j = 0; j < length - i -1; j++) {//减去已经排好的元素个数，再减去1，避免移除
					if (stat[j] > stat[j + 1]) {//大的向上冒泡
						exchange(&stat[j + 1],&stat[j]);					}
				}
			}
		}
		show(stat, length, "冒泡排序算法");
		delete[](stat);//回收内存
	}
	//选择排序
	//平均复杂度:O(n2)
	//最好复杂度:O(n2)不确定
	//最坏复杂度:O(n2)
	//空间复杂度:O(1)
	//稳定性:不稳定
	static void SelectSort(const int arr[], const int length) {
		int* stat = new int[length];
		int i, j;
		memcpy(stat, arr, length * sizeof(int));
		if (stat != nullptr) {
			for (i = 0; i < length - 1; i++) {//每次选择最小的放在目前的最前面
				int smallest = i;//记录最小下标
				for (j = i + 1; j < length; j++) {
					if (stat[j] < stat[smallest]) {
						smallest = j;//找到最小坐标
					}
				}
				exchange(&stat[smallest], &stat[i]);//将最小的放在当前第一个
			}
		}
		show(stat, length, "选择排序算法");
		delete[](stat);//回收内存
	}
	//插入排序
	//平均复杂度:O(n2)
	//最好复杂度:O(n)
	//最坏复杂度:O(n2)
	//空间复杂度:O(1)
	//稳定性:稳定
	static void InsertSort(const int arr[], const int length) {
		int* stat = new int[length];
		memcpy(stat, arr, length * sizeof(int));
		if (stat != nullptr) {
			for (int i = 0; i < length - 1; i++) {
				for (int j = i + 1; j >= 0 && stat[j] < stat[j - 1]; j--) {//和前一个比较,直到找到插入到合适的位置
					//交换两元素位置
					exchange(&stat[j - 1], &stat[j]);
				}
			}
		}
		Sort::show(stat, length, "插入排序算法");
		delete[](stat);//回收内存
	}
	//希尔排序
	//平均复杂度:O(n1.3-n2)
	//最好复杂度:O()
	//最坏复杂度:O()
	//空间复杂度:O(1)
	//稳定性:不稳定
	static void ShellSort(const int arr[], const int length) {
		int* stat = new int[length];
		int gap = length / 2;
		memcpy(stat, arr, length * sizeof(int));
		while (gap) {
			for (int i = 0; i < gap; i++) {//总共有gap-1个分组，对每个分组进行插入排序
				//插入排序
				for (int j = i + gap; j < length; j += gap) {//从第i组第一个元素开始，遍历每个组的元素，进行插入排序
					int k = j - gap;//记录前一个元素的下标
					while (k >= 0 && stat[k] > stat[k + gap]) {//k>=0说明还需要进行比较
						Sort::exchange(&stat[k], &stat[k + gap]);
						k -= gap;
					}
				}
			}
			gap /= 2;//缩小间距
		}
		Sort::show(stat, length, "希尔排序算法");
		delete[](stat);//回收内存
	}
	//快速排序
	//平均复杂度:O(nlogn)
	//最好复杂度:O(nlogn)
	//最坏复杂度:O(n2)
	//空间复杂度:O(logn-n)
	//稳定性:不稳定
	static void QuickSortEnter(const int arr[], const int length) {//快速排序入口
		int* stat = new int[length];
		memcpy(stat, arr, length * sizeof(int));
		if (stat != nullptr) 
			Sort::QuickSort(stat, 0, length - 1);
		Sort::show(stat, length, "快速排序算法");
		delete[](stat);//回收内存
	}
	static void QuickSort(int arr[],int low,int high) {//快速排序
		if (low >= high) return;//已经有序
		int key = arr[low];//默认基准为low
		int i = low;
		int j = high + 1;//因为j会先自减
		while (i < j) {//当两个标记相遇时
			while (i < j && arr[--j] > key);
			while (i < j && arr[++i] < key);
			if (i >= j) break;//已经分好了
			Sort::exchange(&arr[i], &arr[j]);//交换i,j的值
		}
		Sort::exchange(&arr[low], &arr[j]);//将基准放入
		Sort::QuickSort(arr, low, j - 1);
		Sort::QuickSort(arr, j + 1, high);
	}
	//归并排序
	//平均复杂度:O(nlogn)
	//最好复杂度:O(nlogn)
	//最坏复杂度:O(nlogn)
	//空间复杂度:O(n)
	//稳定性：稳定
	static void MergeSortEnter(const int arr[],const int length) {
		int* stat = new int[length];
		int* result = new int[length];
		memcpy(stat, arr, length * sizeof(int));
		if (stat != nullptr&&result != nullptr) {
			Sort::MergeSort(stat, 0, length - 1, result);
		}
		Sort::show(stat, length, "归并排序算法");
		delete[](stat);//回收内存
		delete[](result);//回收内存
	}
	static void MergeSort(int arr[],int low,int high,int result[]) {
		if(low < high){
			int mid = low + (high - low) / 2;//避免int溢出
			Sort::MergeSort(arr, low, mid, result);
			Sort::MergeSort(arr, mid+1, high, result);
			Sort::Merge(arr,low,high,mid,result);
		}
	}
	static void Merge(int arr[],int low,int high,int mid,int result[]) {
		int i, j, k;
		i = low;
		j = mid + 1;
		k = 0;
		while (i <= mid && j <= high) {
			if (arr[i] < arr[j]) {
				result[k++] = arr[i++];
			}
			else {
				result[k++] = arr[j++];
			}
		}
		while (i <= mid) {
			result[k++] = arr[i++];
		}
		while (j <= high) {
			result[k++] = arr[j++];
		}
		for (int i = 0; i < k; i++) {
			arr[low+i] = result[i];
		}
	}
	//堆排序
	//平均复杂度:O(nlogn)
	//最好复杂度:O()
	//最坏复杂度:O()
	//空间复杂度:O(1)
	//稳定性:不稳定
	static void HeapSort(const int arr[],const int length) {
		int* stat = new int[length];
		memcpy(stat, arr, length * sizeof(int));
		if (stat != nullptr) {
			//初始化大顶堆
			for (int i = length / 2 - 1; i >= 0; i--) {
				Sort::HeapAjust(stat, i, length - 1);
			}
			//交换顶部和最后一个元素，继续调整
			for (int i = length - 1; i > 0; i--) {
				Sort::exchange(&stat[0], &stat[i]);
				Sort::HeapAjust(stat, 0, i - 1);
			}
		}
		Sort::show(stat, length, "堆排序算法  ");
		delete[](stat);
	}
	static void HeapAjust(int arr[], int start,int end) {//从i节点开始调整
		int dad = start;
		int son = 2 * dad + 1;
		while (son <= end) {//子节点在范围内才会比较
			//选择更大的那个儿子
			if (son + 1 <= end && arr[son] < arr[son + 1]) {
				son++;
			}
			if (arr[dad] > arr[son]) return;//不需要交换
			else {
				Sort::exchange(&arr[dad], &arr[son]);//交换位置
				dad = son;//继续向下调整大顶堆
				son = 2 * dad + 1;
			}
		}
	}
};

int main()
{
	const int arr[] = { 4,6,5,7,1,3,2,8,0,9 };
	int length = (int)sizeof(arr) / sizeof(*arr);
	Sort::BubbleSort(arr, length);
	Sort::SelectSort(arr, length);
	Sort::InsertSort(arr, length);
	Sort::ShellSort(arr, length);
	Sort::QuickSortEnter(arr, length);
	Sort::MergeSortEnter(arr, length);
	Sort::HeapSort(arr, length);
}
