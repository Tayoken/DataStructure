#include "swap.h"

/*默认用int型数据*/
/*默认按从小到大排序*/

/*冒泡排序*/
/*从前向后比较，每次比较两个数，如果大小关系错了，就交换两个数*/
void bubble_sort(int arr[], int length)
{
	int i, j;
	for (i = 0; i < length; i++)
		for (j = 0; j < length - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

/*复杂度O(n^2)*/
/*数据已经是从小到大排列时最快，反之最慢.*/

