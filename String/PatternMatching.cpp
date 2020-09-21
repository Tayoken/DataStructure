#include "VeriableString.h"
#include <iostream>

/*模式匹配算法默认字符串从下标1开始存储 这样做next数组即为PMT表把第一个变成-1*/

/*
*简单模式匹配算法
*/
int index(Str str, Str substr)
{
	int i = 1, j = 1, k = 1;														//假设串的存储从下标1开始
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
			i = ++k;                                                                //匹配失败，i从主串的下一位置开始，k中记录了上一次的起始位置
		}
	}
	if (j > substr.length)
		return k;
	else return 0;

}

/*"Partial match" table (also known as "failure function") 部分匹配表/失配函数
PMT中的值是字符串的前缀集合与后缀集合的交集中最长元素的长度

在主串与模式串失配的时候，算法核心是找一个当前同时满足主串末尾和子串开头的最大公共串，让下一个模式串中的字符和主串的下一个字符比较。
实现最少的搜索次数，使算法可以达到线性时间

在不错过任何潜在匹配的情况下，我们"预搜索"这个模式串本身并将其译成一个包含所有可能失配的位置对应可以绕过最多无效字符的列表。

例如，对于"aba"，它的前缀集合为{"a", "ab"}，后缀 集合为{"ba", "a"}。
两个集合的交集为{"a"}，那么长度最长的元素就是字符串"a"了，长 度为1，所以对于"aba"而言，
它在PMT表中对应的值就是1。
再比如，对于字符串"ababa"，它的前缀集合为{"a", "ab", "aba", "abab"}，它的后缀集合为{"baba", "aba", "ba", "a"}，
两个集合的交集为{"a", "aba"}，其中最长的元素为"aba"，长度为3。
*/



/*KMP算法*/
/*获取substr的next数组*/
void getNext(Str substr, int next[])
{                                                                                   //把获取next数组当成一次模式串匹配
	/*具体来说，就是从模式字符串的第一位(注意，不包括第0位)开始对自身进行匹配运算。 在任一位置，能匹配的最长长度就是当前位置的next值。*/
	int i = 1, j = 0;                                                               //i表示主串下标，j表示模式串下标，同时也表示匹配的字符串数目
	next[1] = 0;
	while (i < substr.length)
	{
		if (j == 0 || substr.ch[i] == substr.ch[j]) 
		{
			i++;
			j++;
			next[i] = j;                                                            //next[i]的值就是当前匹配的字符数
		}
		else
			j = next[j];                                                            //如果不匹配，从头开始配
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
/*
* 如果模式串中有重复，如"AAAAAB"
*/

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
			/*
			next[i] = j;
			if(substr.ch[i] != substr.ch[ij])
				nextval[i] = next[j];
			else
				nextval[i] = nextval[next[j]];
			*/
			if (substr.ch[i] != substr.ch[j])                                       //替换上面的代码
				nextval[i] = j;
			else                                                                   
				nextval[i] = nextval[j];                                           
		}
		else
			j = nextval[j];
	}
}