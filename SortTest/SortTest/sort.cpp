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

//���ֹ��� ��һ��Ԫ�ص����ᣬ�ֳ�������Ч������
//ʵ��˼�� һ�����ҵ����� ʹ��ָ��ָ���׵�ַ�������һ��
//�õ�һ������temp�����жԱȣ���������ͬʱ�Ƚ�
//�ұߵ�����tempС���ͽ�rightλ�õ�ֵ��ֵ��left����ʱright��λ��û��ֵ�������temp��������
//Ȼ����߱Ƚϣ���߱�tempС����ǰ�ƣ������temp�󣬸�ֵ��right
void QuickSort(int arr[], int left, int right)
{
	//ָ����һ��ֵ ���жԱ�
	int temp = arr[left]; //ÿ�ζ��������ѡ��׼��
	int index = right;
	if (left > right)
		return;
	cout << "aaa" << endl;
	//���ݶ�����ԭ�� ���С���ұߴ�
	while (left < right)
	{
		//����β��Ԫ��>tempʱ����ǰŲ��ָ��
		while ((left < right) && (arr[right] >= temp))
		{
			right--;
		}
		//�����β��Ԫ��<tempʱ����ֵ��ֵ��left
		if ((left < right) && (arr[right] < temp))
		{
			arr[left] = arr[right];
		}
		//��right�෴
		while ((left < right) && (arr[left] <= temp))
		{
			left++;
		}
		
		arr[right] = arr[left]; //��leftλ�õ�ֵ��ֵ��right
		
		
	}
	
	//ѭ��һȦ������ָ��ͬʱָ��һ���ط�
	arr[left] = temp; //��temp��ֵ��ֵ����ǰλ��

	//��ʱ����ָ��ָ��ͬһ��λ��
	//�ֳ��������л�������ͬʱ����ֱ������ʣһ����λ��
	QuickSort(arr, 0, left - 1);
	QuickSort(arr, right + 1, index);
}
int main() {
	int arr[] = { 34,65,12,43,67,5,78,10,3,70 };
	int len = sizeof(arr) / sizeof(arr[0]);
	cout << "����ǰ��" << endl;
	MyPrint(arr, len);

	cout << "�����" << endl;
	//ð��
	/*BubbleSort(arr, len);
	MyPrint(arr, len);*/
	//ѡ��
	/*SelectSort(arr, len);
	MyPrint(arr, len);*/
	//����
	QuickSort(arr, 0, len-1);
	MyPrint(arr, len);
	

	system("pause");
	return EXIT_SUCCESS;
}