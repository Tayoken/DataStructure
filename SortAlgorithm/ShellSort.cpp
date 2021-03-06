/*
该算法是在插入排序的基础上改进得到的，原因：
1.插入排序对几乎已经排好序的数组是高效的，可以达到线性的时间
2.一般来说插入排序是低效的，因为插入排序每次只能将数据移动一位
*/

/*
希尔排序的基本思想是：先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，
待整个序列中的记录"基本有序"时，再对全体记录进行依次直接插入排序。
*/

/*算法步骤
1.选择一个增量序列 t1，t2，……，tk，其中 ti > tj, tk = 1；
2.按增量序列个数k ，对序列进行 k 趟排序；
3.每趟排序，根据对应的增量 ti ，将待排序列分割成若干长度为 m 的子序列，分别对各子表进行直接插入排序。
仅增量因子为 1 时，整个序列作为一个表来处理，表长度即为整个序列的长度。
*/

#include "swap.h"

/*希尔排序*/
void shell_sort(int arr[], int len)
{
	int gap = 1;
	while (gap < len / 3)//动态分配间隔
		gap = 3 * gap + 1;
	while (gap >= 1) {	
		for (int i = gap; i < len; i++)
			for (int j = i; j >= gap && arr[j - gap] > arr[j]; j-=gap)//每次对比的时候都是间隔gap，有相同间隔的算一组
				swap(arr[j], arr[j - gap]);
		gap = gap / 3;
	}
}

/*希尔排序算法复杂度分析很复杂，目前最好为O(n^1,3),和间隔有关*/
