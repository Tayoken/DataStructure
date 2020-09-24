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
	int mid = arr[end];                                                 //基准值
	int idx_left = start, idx_right = end - 1;
	while (idx_left < idx_right)
	{                                                                   //在整个范围内搜寻比枢纽元值小或大的元素，然后将左侧元素与右侧元素交换
		while (arr[idx_left] < mid && idx_left < idx_right)				//找一个比基准数大的数，等于也可以
			idx_left++;
		while (arr[idx_right] >= mid && idx_left < idx_right)           //找一个比基准数小的数
			idx_right--;
		swap(arr[idx_left], arr[idx_right]);
	}
	if (arr[idx_left] >= arr[end])
		swap(arr[idx_left], arr[end]);
	else
		idx_left++;                                                     //
	quick_sort(arr, start, idx_left - 1);
	quick_sort(arr, idx_right + 1, end);
}