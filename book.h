#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#pragma once
using namespace std;
class books{
	protected: 
	string bookName;//����
	string author;//����
	string press;//������ 
	int bookQuantity;//ͼ������
	public:
	books(string ,string ,string ,int );
	books(){};
	~books();   
	string getbookName();//�������� 
	string getAuthor();//�������� 
	string getPress();//���س����� 
	int getbookQuantity();//�������� 
	string getbookName(string);//�������� 
	string getAuthor(string);
	string getPress(string);
	int getbookQuantity(int);
	void lookup(books &); 
	void lookupBook();//���������� 
	void lookupAuthor();//�������߲���
	void lookupPress();//���ճ�������� 
	void printBook();//չʾȫ��ͼ�� 
	void readBook();//���ļ��ж�ȡͼ����Ϣ
	void backupsBook();//����ͼ����Ϣ���ļ� 
	vector<books> b;
};
