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
			for (i = 0; i < length - 2; i++) {//每次选择最小的放在目前的最前面
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
			for (int i = 1; i < length - 1; i++) {
				for (int j = i + 1; j > 0 && stat[j] < stat[j - 1]; j--) {//和前一个比较,直到找到插入到合适的位置
					//交换两元素位置
					exchange(&stat[j - 1], &stat[j]);
				}
			}
		}
		Sort::show(stat, length, "插入排序算法");
		delete[](stat);//回收内存
	}
	//希尔排序
	//平均复杂度:O()
	//最好复杂度:O()
	//最坏复杂度:O()
	//空间复杂度:O()
	//稳定性:
	//快速排序
	//平均复杂度:O()
	//最好复杂度:O()
	//最坏复杂度:O()
	//空间复杂度:O()
	//稳定性:
	//归并排序
	//平均复杂度:O()
	//最好复杂度:O()
	//最坏复杂度:O()
	//空间复杂度:O()
	//稳定性:
	//堆排序
	//平均复杂度:O()
	//最好复杂度:O()
	//最坏复杂度:O()
	//空间复杂度:O()
	//稳定性:
};

int main()
{
	const int arr[] = { 4,6,5,7,1,3,2,8,0,9 };
	Sort::BubbleSort(arr, 10);
	Sort::SelectSort(arr, 10);
	Sort::InsertSort(arr, 10);
}
