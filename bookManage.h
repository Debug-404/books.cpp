#include"student.h"
class bookManage:public student{  
	public:
	void menu_Manage();//����Ա��������
	void operation_Manage(bookManage &);//���� 
	void deleteBook();//ɾ��ͼ��
	void addBook();//����ͼ��
	void modifyBook();//�޸�ͼ����Ϣ
	void student_Manage(bookManage &);//ѧ������ 
	void print_student();//չʾ������
	void add_Student();//����ѧ�� 
	void delete_Student();//ɾ��ѧ�� 
	int signIn_Manage();//����Ա��¼ 
	void print_book(bookManage&);//�������� 
	void print_book_Manage();//������� 
	void read_Vip();//��ȡ������ 
	void backups_Vip();//���ݰ�����
	void sortStudent();//���� 
	vector<student> w;
};
void Index();
