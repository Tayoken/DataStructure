#include "swap.h"
/*快速排序算法的思想相当简单*/

/*步骤
1.从数列中挑出一个元素，称为 "基准"（pivot）;

2.重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。
在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；

3.递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序；
*/

/*快速排序*/
void quick_sort(int arr[], int start, int end)
{
	if (start >= end)
		return;
	int mid = arr[end];                                          //基准值
	int i = start, j = end - 1;
	while (i < j)
	{//在整个范围内搜寻比基准值小或大的元素，然后将左侧元素与右侧元素交换                                                            
		while (arr[i] < mid && i < j)				             //找一个比基准数大的数，等于也可以
			i++;
		while (arr[j] >= mid && i < j)				             //找一个比基准数小的数
			j--;
		swap(arr[i], arr[j]);
	}
	if (arr[i] >= arr[end])
		swap(arr[i], arr[end]);
	else
		i++;                                                     //
	quick_sort(arr, start, i - 1);
	quick_sort(arr, j + 1, end);
}


void quickSort(int s[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r, temp = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= temp)                           // 从右向左找第一个小于x的数
				j--;
			if (i < j)
				s[i++] = s[j];
			while (i < j && s[i] < temp)                            // 从左向右找第一个大于等于x的数
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = temp;
		quickSort(s, l, i - 1);                                  // 递归调用
		quickSort(s, i + 1, r);
	}
}
