/*计数排序*/
/*技术排序的核心在于将数据值转化为键值存储在二维开辟的数组空间中。
作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定方位的整数。*/
/*算法步骤
1.找出待排序数组中最大和最小的元素
2.统计数组中每个值为i的元素出现的次数，存入数组的第i项
3.对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）
4.反向填充目标数组：将每个元素i房子新数组的第C(i)项,每放图个元素就将C(i)减去1
*/

void counting_sort(int ini_arr[], int sorted_arr[], int len)
{
	int count_arr[101];
	//int* count_arr = new int[101]; // 假设数据从0到100,新建计数数组
	int i, j, k;
	for (k = 0; k < 101; k++)//初始化count_arr
		count_arr[k] = 0;
	for (i = 0; i < len; i++)//计数每个数据出现的次数
		count_arr[ini_arr[i]]++;
	for (k = 1; k < 101; k++)//所有的计数累加
		count_arr[k] += count_arr[k - 1];
	for (j = len; j > 0; j--)//反向填充
		sorted_arr[--count_arr[ini_arr[j - 1]]] = ini_arr[j - 1];
	//delete[] count_arr;
}