/*归并排序*/
/*分治思想*/

/*
算法步骤
申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列；
设定两个指针，最初位置分别为两个已经排序序列的起始位置；
比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置；
重复步骤 3 直到某一指针达到序列尾；
将另一序列剩下的所有元素直接复制到合并序列尾。
*/

/*递归版*/

//合并有序数组算法
void merge(int arr[], int front, int mid, int end, int temp[])
{
	//前提条件：
	//arr[]的[front,...,mid]有序
	//arr[]的[mid+1,...end]有序
	//操作：
	//合并有序数组
	//temp 参数可以换成即时申请
	//int* temp = (int*)malloc((front - end + 1) * sizeof(int));
	int i = front, j = mid + 1;
	int m = mid, n = end;
	int k = 0;

	/*循环比较两个数组第一个数，谁小取谁放到temp[]中*/
	while (i <= m && j <= n)
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i];
		else
			temp[k++] = arr[j];
	}

	/*下面两个循环，把数组中剩余的元素复制进temp[]数组*/
	while (i <= m)
		temp[k++] = arr[i++];
	while (j <= n)
		temp[k++] = arr[j++];
	/*把temp数组复制回原来的arr数组*/
	for (i = 0; i < k; i++)
		arr[front + 1] = temp[i];

}

//归并排序的算法递归版
void merge_sort(int arr[], int front, int end, int temp[])
{
	if (front < end)
	{
		int mid = (front + end) / 2;
		merge_sort(arr, front, mid, temp);
		merge_sort(arr, mid + 1, end, temp);
		merge(arr, front, mid, end, temp);
	}
}


int min(int a, int b)
{
	return a < b ? a : b;
}

//归并排序算法的迭代版
void merge_sort_nonrecursion(int arr[], int len)
{
	int* a = arr;
	int* b = new int(len);
	for(int i = 1; i<len;i+=i)
	{
		for (int start = 0; start < len; start += i + i)
		{
			int front = start, mid = min(start + i, len), end = min(start + i + i, len);
			int k = front;
			int left_start = start, left_end = mid;
			int right_start = mid, right_end = end;
			while (left_start < left_end && right_start < right_end)
				b[k++] = arr[left_start] < arr[right_start] ? arr[left_start++] : arr[right_start++];
			while (left_start < left_end)
				b[k++] = arr[left_start++];
			while (right_start < right_end)
				b[k++] = arr[right_start++];
		}
		int* temp = a;
		a = b;
		b = temp;
	
	}
	if (a != arr)
	{
		for (int i = 0; i < len; i++)
			b[i] = arr[i];
		b = a;
	}
	delete[] b;
}

