#include"book.h"
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#pragma once
class student:public books{
	protected:
	int NO;//ѧ��
	string name;//����
	string borrowBook;//���ĵ��鼮
	int num;//�����鼮������ 
	public:
		student(){};
		student(int,string,string,int);
		student(int,string);
		~student();
	int getNo();//����ѧ��
	string getName(); //�������� 
	string getBorrowbook();//���ؽ��ĵ��鼮 
	int getNum();//�������� 
	int getNum(int);
	void borrowed_Book();//������� 
	void borrow_Book();//���� 
	void still_Book();//���� 
	void read_Student();//��ȡ������Ϣ 
	void backups_student();//���ݽ�����Ϣ  
	void menu_student();//�������� 
	void operation_Student(student &); //����
	int signIn_student();//ѧ����¼ 
	vector<student> v;
};
