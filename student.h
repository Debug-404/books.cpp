#include"book.h"
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#pragma once
class student:public books{
	protected:
	int NO;//学号
	string name;//姓名
	string borrowBook;//借阅的书籍
	int num;//借阅书籍的数量 
	public:
		student(){};
		student(int,string,string,int);
		student(int,string);
		~student();
	int getNo();//返回学号
	string getName(); //返回名字 
	string getBorrowbook();//返回借阅的书籍 
	int getNum();//返回数量 
	int getNum(int);
	void borrowed_Book();//借过的书 
	void borrow_Book();//借书 
	void still_Book();//还书 
	void read_Student();//读取借书信息 
	void backups_student();//备份借书信息  
	void menu_student();//引导界面 
	void operation_Student(student &); //操作
	int signIn_student();//学生登录 
	vector<student> v;
};
