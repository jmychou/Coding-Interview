#include "stdio.h";
#include "stdlib.h";
#include "String.h";
#include "map";
#include<iostream>
#include "sstream"

using namespace std;

string tt(int i){
	string  s;
	stringstream ss;
	ss << i;
	ss >> s;
	return s;

}

float ff(string tmp){
	float  s;
	stringstream ss;
	ss << tmp;
	ss >> s;
	return s;
}

void mainm()
{
	/*map<int, int> str;
	int a[8] = { 1,1,11,11,11,0,0,0 };
	for (int i = 0; i < 8; ++i){
		++str[a[i]];
	}
	int value = (str.begin())->first;
	int Max = (str.begin())->second;
	for (map<int, int>::iterator iter = str.begin(); iter != str.end(); iter++)
	{
		if (iter->second>Max)
		{
			value = iter->first;
			Max = iter->second;
		}
	}

	cout << "������Ϊ:" << value << endl;*/

	/*int i = 11 ;
	int j = 12;
	string  s = tt(i) + tt(j) ;
	
	cout << ff(s)<< endl;
	system("pause");
	*/

	char a[5] = { 'A', 'B', 'C', 'D' };   //aҲ��ָ�룬����Ϊchar*[5]
	
	char *p1[10];	//ָ������
	char(*p2)[5];	//����ָ�룬ָ��char[5],������char(*)[5]
		p2=&a;  //p2ָ��a,p2����һ������ָ�룬a��һ��ָ��

		for (int i = 0; i < 4; ++i){
			p1[i] = &a[i];    //a���鸳ֵ��p1��p1�洢�ľ���a��Ԫ�صĵ�ַ
		}

	
		cout << *p1[2]<<*(*p1+2) << endl;		 //���һ�� 
	cout << (*p2)[2]<< "   " <<*(*p2+2) << endl;  //���һ��

	/*
	char *str[] = { "welcome", "to", "Fortemedia", "Nanjing" };     //ָ�����飬����һ����ά���飬����������һ������ָ�룬��Ϊ�ַ����Ǵ����ַ������е�
	char**p = str + 1;		//str��һ�����飬�Ϳ�������һ������ָ��������飬Ҳ����ָ��ָ�������еĵ�һ��Ԫ�أ�Ҳ��ָ�룬���Զ���һ������ָ��


	str[0] = (*p++) + 2;	//7
	str[1] = *(p + 1);		//8
	str[2] = p[1] + 3;      //9
	str[3] = p[0] + (str[2] - str[1]);	//10
	cout << str[0] << endl;   
	cout << str[1] << endl;
	cout << str[2] << endl;
	cout << str[3] << endl;


	 
	int bb[5][5];
	int(*pp)[5];
	pp = bb;
	

	int tmp[] = { 1, 2, 3 };
	int *tt = tmp;
	cout << &tmp << " " << tt << endl;
*/

	char ch[20] = " You_are_a_girl";
	char *p = ch;
	char **ptr = &p;

	cout << **ptr << endl;

	ptr++;

	//cout << **ptr << endl;


	system("pause");
}

