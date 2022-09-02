#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#pragma once
using namespace std;
class books{
	protected: 
	string bookName;//书名
	string author;//作者
	string press;//出版社 
	int bookQuantity;//图书数量
	public:
	books(string ,string ,string ,int );
	books(){};
	~books();   
	string getbookName();//返回书名 
	string getAuthor();//返回作者 
	string getPress();//返回出版社 
	int getbookQuantity();//返回数量 
	string getbookName(string);//函数重载 
	string getAuthor(string);
	string getPress(string);
	int getbookQuantity(int);
	void lookup(books &); 
	void lookupBook();//按书名查找 
	void lookupAuthor();//按照作者查找
	void lookupPress();//按照出版社查找 
	void printBook();//展示全部图书 
	void readBook();//从文件中读取图书信息
	void backupsBook();//备份图书信息到文件 
	vector<books> b;
};
