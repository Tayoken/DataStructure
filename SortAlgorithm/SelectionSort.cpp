#include "swap.h"

/*选择排序*/
/*
首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置。
再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
重复第二步，直到所有元素均排序完毕。
*/
void selection_sort(int arr[], int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		int min = i;
		/*下面的循环选出最小值*/
		for (j = i + 1; j < len; j++)
			if (arr[j] < arr[min])
				min = j;										//记录最小值
		swap(arr[i], arr[min]);                                 //最小值与arr[i]起始元素交换
	}
}
/*数据规模越小越好*/
/*复杂度O(n^2)*/