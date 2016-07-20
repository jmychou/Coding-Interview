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

	cout << "最多的数为:" << value << endl;*/

	/*int i = 11 ;
	int j = 12;
	string  s = tt(i) + tt(j) ;
	
	cout << ff(s)<< endl;
	system("pause");
	*/

	char a[5] = { 'A', 'B', 'C', 'D' };   //a也是指针，类型为char*[5]
	
	char *p1[10];	//指针数组
	char(*p2)[5];	//数组指针，指向char[5],类型是char(*)[5]
		p2=&a;  //p2指向a,p2类似一个二级指针，a是一级指针

		for (int i = 0; i < 4; ++i){
			p1[i] = &a[i];    //a数组赋值给p1，p1存储的就是a的元素的地址
		}

	
		cout << *p1[2]<<*(*p1+2) << endl;		 //结果一样 
	cout << (*p2)[2]<< "   " <<*(*p2+2) << endl;  //结果一样

	/*
	char *str[] = { "welcome", "to", "Fortemedia", "Nanjing" };     //指针数组，类似一个二维数组，数组名就是一个二级指针，因为字符串是存在字符数组中的
	char**p = str + 1;		//str是一个数组，就可以设置一个变量指向这个数组，也就是指向指针数组中的第一个元素，也是指针，所以定义一个二级指针


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

