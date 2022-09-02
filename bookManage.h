#include"student.h"
class bookManage:public student{  
	public:
	void menu_Manage();//管理员操作界面
	void operation_Manage(bookManage &);//操作 
	void deleteBook();//删除图书
	void addBook();//增加图书
	void modifyBook();//修改图书信息
	void student_Manage(bookManage &);//学生管理 
	void print_student();//展示白名单
	void add_Student();//增加学生 
	void delete_Student();//删除学生 
	int signIn_Manage();//管理员登录 
	void print_book(bookManage&);//借书的情况 
	void print_book_Manage();//借书管理 
	void read_Vip();//读取白名单 
	void backups_Vip();//备份白名单
	void sortStudent();//排序 
	vector<student> w;
};
void Index();
