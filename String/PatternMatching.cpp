#include "VeriableString.h"
#include <iostream>

/*模式匹配算法默认字符串从下标1开始存储*/


/*
*简单模式匹配算法
*/
int index(Str str, Str substr)
{
	int i = 1, j = 1, k = 1;//假设串的存储从下标1开始
	while (i <= str.length && j <= substr.length)
	{
		if (str.ch[i] == substr.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			j = 1;
			i = ++k;//匹配失败，i从主串的下一位置开始，k中记录了上一次的起始位置
		}
	}
	if (j > substr.length)
		return k;
	else return 0;

}


/*KMP算法*/
/*获取substr的next数组*/
void getNext(Str substr, int next[])
{
	int i = 1, j = 0;
	next[1] = 0;
	while (i < substr.length)
	{
		if (j == 0 || substr.ch[i] == substr.ch[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

/*由得到next数组的算法修改得KMP算法*/
int KMP(Str str, Str substr, int next[])
{
	int i = 1, j = 1;
	while (i <= str.length && j <= substr.length)
	{
		if (j == 0 || str.ch[i] == substr.ch[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j > substr.length)
		return i - substr.length;
	else
		return 0;
}


/*KMP算法的改进*/
void getnextval(Str substr, int nextval[])
{
	int i = 1, j = 0;
	nextval[1] = 0;
	while (i < substr.length)
	{
		if (j == 0 || substr.ch[i] == substr.ch[j])
		{
			++i;
			++j;
			if (substr.ch[i] != substr.ch[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
}