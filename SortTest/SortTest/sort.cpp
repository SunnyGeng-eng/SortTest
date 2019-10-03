#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void MyPrint(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void BubbleSort(int* arr, int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-i-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


void SelectSort(int *arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (i != min)
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

//划分过程 第一个元素当枢轴，分成两个有效子序列
//实现思想 一排杂乱的数据 使用指针指向首地址，和最后一个
//用第一个数（temp）进行对比，两个方向同时比较
//右边的数比temp小，就将right位置的值赋值给left，此时right的位置没有值，如果比temp大，往左移
//然后左边比较，左边比temp小，往前移，如果比temp大，赋值给right
void QuickSort(int arr[], int left, int right)
{
	//指定第一个值 进行对比
	int temp = arr[left]; //每次都从最左侧选基准数
	int index = right;
	if (left > right)
		return;
	cout << "aaa" << endl;
	//根据二叉树原理 左边小，右边大
	while (left < right)
	{
		//当队尾的元素>temp时，向前挪动指针
		while ((left < right) && (arr[right] >= temp))
		{
			right--;
		}
		//如果队尾的元素<temp时，将值赋值给left
		if ((left < right) && (arr[right] < temp))
		{
			arr[left] = arr[right];
		}
		//跟right相反
		while ((left < right) && (arr[left] <= temp))
		{
			left++;
		}
		
		arr[right] = arr[left]; //将left位置的值赋值给right
		
		
	}
	
	//循环一圈后，左右指针同时指向一个地方
	arr[left] = temp; //把temp的值赋值给当前位置

	//此时左右指针指向同一个位置
	//分成两个序列化，两遍同时排序，直到数组剩一个数位置
	QuickSort(arr, 0, left - 1);
	QuickSort(arr, right + 1, index);
}
int main() {
	int arr[] = { 34,65,12,43,67,5,78,10,3,70 };
	int len = sizeof(arr) / sizeof(arr[0]);
	cout << "排序前：" << endl;
	MyPrint(arr, len);

	cout << "排序后：" << endl;
	//冒泡
	/*BubbleSort(arr, len);
	MyPrint(arr, len);*/
	//选择
	/*SelectSort(arr, len);
	MyPrint(arr, len);*/
	//快速
	QuickSort(arr, 0, len-1);
	MyPrint(arr, len);
	

	system("pause");
	return EXIT_SUCCESS;
}