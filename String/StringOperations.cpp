#include <iostream>
#include "VeriableString.h"

/*字符串赋值操作*/
int strassign(Str& str, char* ch)
{
	if (str.ch)
		free(str.ch);
	int len = 0;
	char* c = ch;
	while (*c)
	{
		++len;
		++c;
	}
	if (len == 0)
	{
		str.ch = NULL;
		str.length = 0;
		return 1;
	}
	else
	{
		str.ch = (char*)malloc(sizeof(char) * (len + 1));                                   //取len+1是为了多分配一个空间存放'\0'字符
		if (str.ch == NULL)
			return 0;
		else
		{
			c = ch;
			for (int i = 0; i <= len; i++)
				str.ch[i] = *c;
			/*循环条件用<=是为了把'\0'复制进去*/
			str.length = len;
			return 1;
		}
	}

}

/*取串长度操作*/
int strlength(Str str)
{
	return str.length;
}

/*串比较操作*/
/*
* 规则：设字符串A和B，待比较字符为a和b，如果a的ASCII码小于b的，则返回A小于B标记；大于则返回A大于B标记；如果相等，继续按以上规则比较下一位的字符。
* 先结束的为较小串。
*/
int strcompare(Str s1, Str s2)
{
	for (int i = 0; i < s1.length && i < s2.length; i++)
		if (s1.ch[i] != s2.ch[i])
			return s1.ch[i] - s2.ch[i];
	return s1.length - s2.length;
}

/*串连接操作*/
/*将两个串首尾相连，合并成一个字符串的操作*/
int concat(Str& str, Str str1, Str str2)
{
	if (str.ch)                                                                             //释放原串空间
	{
		free(str.ch);
		str.ch = NULL;
	}
	str.ch = (char*)malloc(sizeof(char) * (str1.length + str2.length + 1));					//注意多申请一位空间放'\0'
	if (str.ch == NULL)                                                                     //申请空间失败
		return 0;
	/*下面两个循环把两个串赋值到新串*/
	int i = 0;
	while (i<str1.length)
	{
		str.ch[i] = str1.ch[i];
		i++;
	}
	int j = 0;
	while (j <= str2.length)                                                                //使用<=号是为了把'\0'复制进去
	{
		str.ch[i + j] = str2.ch[j];                                                         //Warning C6386
		j++;
	}
	str.length = str1.length + str2.length;                                                 //设定新串长度
	return 1;
}

/*求子串操作*/
/*实现求str串中从pos位置开始，长度为len的子串，由substr返回*/
int substring(Str& substr, Str str, int pos, int len)
{
	if (pos < 0 || pos >= str.length || len < 0 || len > str.length - pos)                  //非法输入判断
		return 0;
	if (substr.ch)
	{
		free(substr.ch);
		substr.ch = NULL;
	}
	if (len == 0)                                                                           //求子串为空串
	{
		substr.ch = NULL;
		substr.length = 0;
		return 1;
	}
	else
	{
		substr.ch = (char*)malloc(sizeof(char) * (len + 1));                                //申请len+1个空间
		if (substr.ch == NULL)
			return 0;

		int i = pos;
		int j = 0;
		while (j < len)//while(i<pos+len)
		{
			substr.ch[j] = str.ch[i];
			++i;
			++j;
		}
		substr.ch[j] = '\0';
		substr.length = len;
		return 1;
	}
}

/*清空串操作*/
int clearstring(Str& str)
{
	if (str.ch)
	{
		free(str.ch);
		str.ch = NULL;
	}
	str.length = 0;
	return 1;
}