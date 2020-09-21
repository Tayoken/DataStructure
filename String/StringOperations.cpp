#include <iostream>
#include "VeriableString.h"

/*�ַ�����ֵ����*/
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
		str.ch = (char*)malloc(sizeof(char) * (len + 1));                                   //ȡlen+1��Ϊ�˶����һ���ռ���'\0'�ַ�
		if (str.ch == NULL)
			return 0;
		else
		{
			c = ch;
			for (int i = 0; i <= len; i++)
				str.ch[i] = *c;
			/*ѭ��������<=��Ϊ�˰�'\0'���ƽ�ȥ*/
			str.length = len;
			return 1;
		}
	}

}

/*ȡ�����Ȳ���*/
int strlength(Str str)
{
	return str.length;
}

/*���Ƚϲ���*/
/*
* �������ַ���A��B�����Ƚ��ַ�Ϊa��b�����a��ASCII��С��b�ģ��򷵻�AС��B��ǣ������򷵻�A����B��ǣ������ȣ����������Ϲ���Ƚ���һλ���ַ���
* �Ƚ�����Ϊ��С����
*/
int strcompare(Str s1, Str s2)
{
	for (int i = 0; i < s1.length && i < s2.length; i++)
		if (s1.ch[i] != s2.ch[i])
			return s1.ch[i] - s2.ch[i];
	return s1.length - s2.length;
}

/*�����Ӳ���*/
/*����������β�������ϲ���һ���ַ����Ĳ���*/
int concat(Str& str, Str str1, Str str2)
{
	if (str.ch)                                                                             //�ͷ�ԭ���ռ�
	{
		free(str.ch);
		str.ch = NULL;
	}
	str.ch = (char*)malloc(sizeof(char) * (str1.length + str2.length + 1));					//ע�������һλ�ռ��'\0'
	if (str.ch == NULL)                                                                     //����ռ�ʧ��
		return 0;
	/*��������ѭ������������ֵ���´�*/
	int i = 0;
	while (i<str1.length)
	{
		str.ch[i] = str1.ch[i];
		i++;
	}
	int j = 0;
	while (j <= str2.length)                                                                //ʹ��<=����Ϊ�˰�'\0'���ƽ�ȥ
	{
		str.ch[i + j] = str2.ch[j];                                                         //Warning C6386
		j++;
	}
	str.length = str1.length + str2.length;                                                 //�趨�´�����
	return 1;
}

/*���Ӵ�����*/
/*ʵ����str���д�posλ�ÿ�ʼ������Ϊlen���Ӵ�����substr����*/
int substring(Str& substr, Str str, int pos, int len)
{
	if (pos < 0 || pos >= str.length || len < 0 || len > str.length - pos)                  //�Ƿ������ж�
		return 0;
	if (substr.ch)
	{
		free(substr.ch);
		substr.ch = NULL;
	}
	if (len == 0)                                                                           //���Ӵ�Ϊ�մ�
	{
		substr.ch = NULL;
		substr.length = 0;
		return 1;
	}
	else
	{
		substr.ch = (char*)malloc(sizeof(char) * (len + 1));                                //����len+1���ռ�
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

/*��մ�����*/
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