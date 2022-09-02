#include"student.h"
#include"bookManage.h"
student::student(int NO,string name,string borrowBook,	int num)
{
	this->NO=NO;
	this->name=name;
	this->borrowBook=borrowBook;
	this->num=num;
}
student::student(int NO,string name)
{
	this->NO=NO;
	this->name=name;
}
student::~student()
{
	
} 
void student::menu_student()
{
	cout << "ͼ����Ϣ����ϵͳ" << endl;
    cout << "-----------------" << endl;
    cout << "1������ͼ��" << endl;
    cout << "2���黹ͼ��" << endl;
    cout << "3���ѽ�ͼ��" << endl;
    cout << "4��ͼ��չʾ" << endl;
    cout << "5��ͼ�����" << endl;
    cout << "0���˳�ϵͳ" << endl;
    cout << "-----------------" << endl;
}
void student::operation_Student(student &stu)
{
	while(1)
    {   system("cls");
    	stu.menu_student();
    int ch=0;
    cout<<"��ѡ��";cin>>ch;
    switch(ch)
    {
    	case 1:
    		system("cls");
    	  stu.borrow_Book();
    	  system("pause");
    		break;
    	case 2:
    	    system("cls");
    	  stu.still_Book();
    	  system("pause");
    		break;
    	case 3:
    		system("cls");
    	  stu.borrowed_Book();
    	  system("pause");
    		break;
    	case 4:
    		system("cls");
    	  stu.printBook();
    	  system("pause");
    		break;
    	case 5:
    		system("cls");
    	  stu.lookup(stu);
    	  system("pause");
    		break;
		case 0:
			stu.backups_student();
			Index();
    		break;
    		default:
    			cout<<"����������������룺"<<endl; 
	}
}
}
void student::read_Student()//��ȡ������Ϣ 
{
    int NO;
	string name;
	string borrowBook;
	int num;
	ifstream ifs;
	ifs.open("studentSystem.txt");
	if(!ifs)
	{
		cout<<"�򲻿�studentSystem�ļ�";  
	} else 
	while(!ifs.eof())
	{
		ifs>>NO>>name>>borrowBook>>num;
		student stu(NO,name,borrowBook,num);
		v.push_back(stu);
		ifs.get();
		if(ifs.peek()=='\n')break;	
	}
	ifs.close();
}
void student::backups_student()//���ݽ�����Ϣ 
{
	ofstream ofs;
	ofs.open("studentSystem.txt");
	if(!ofs)
	{
		cout<<"�򲻿�studentSystem�ļ�";  
	} 
	else
	for(vector<student>::iterator T=v.begin();T!=v.end();T++)
	ofs<<T->getNo()<<"\t"<<T->getName()<<"\t"<<T->getBorrowbook()<<"\t"<<T->getNum()<<endl;
	ofs.close();
	cout<<"лл����ʹ�ã�"<<endl;
}
int student::getNo()
{
	return NO; 
}
string student::getName()
{
	return name;
}
string student::getBorrowbook()
{
	return borrowBook;
}
int student::getNum()
{
	return num;
}
int student::getNum(int n)
{
	num=num-n;
	return num;
}
void student::borrow_Book()//���� 
{
	string bookName,author;
	int n,i=0,j=0;
	cout<<"����������Ҫ�����鼮�����ֺ�����:";
	cin>>bookName>>n;
	for(vector<books>::iterator it=b.begin();it!=b.end();it++)
	{
		if(it->getbookName()==bookName)
		{
			j++;
			for(vector<student>::iterator S=v.begin();S!=v.end();S++)
			if(S->getBorrowbook()==bookName)
			i++;
			if(i==0)
			{
				if(it->getbookQuantity()>=n)
			{
				it->getbookQuantity(it->getbookQuantity()-n);
				this->getNum(n);
				cout<<bookName<<"\t"<<"�Ѿ����"<<endl;
				student stu(this->NO,this->name,bookName,n);
		        v.push_back(stu);
			    break;
			}else cout<<"����"<<bookName<<"����"<<"������������";
			}	
			else cout<<"���Ѿ����"<<"����"<<bookName<<"����"<<"�Ȿ����"<<endl;
		 } 
		 else if(it==b.end()-1&&j==0)
		 cout<<"û�С���"<< bookName<<"�����Ȿ��"<<endl;
	 }
}
void student::still_Book()//���� 
{
	string bookName;
	int n=0; 
	cout<<"�����뻹�������:";
	cin>>bookName;
	for(vector<student>::iterator T=v.begin();T!=v.end();T++)
	if(T->getBorrowbook()==bookName&&T->getNo()==this->NO)
		{
			n=T->getNum();
			for(vector<books>::iterator it=b.begin();it!=b.end();it++)
	        if(it->getbookName()==bookName)
    {
		it->getbookQuantity(it->getbookQuantity()+n);
		cout<<"�ѹ黹ͼ��"<<endl; 
	}
			v.erase(T);
			break;
		 }
		 else if(T==v.end()-1)
		 cout<<"û�н衶��"<< bookName<<"�����Ȿ��"<<endl;
}
void student::borrowed_Book()//�ѽ���鼮 
{
	int i=0;
	for(vector<student>::iterator T=v.begin();T!=v.end();T++)
	{
		if(this->name==T->getName())
		{
			i++;
			cout<<"�ѽ衶��"<<T->getBorrowbook()<<"����\t"<<T->getNum()<<"��"<<endl;
		}else if(T==v.end()-1&&i==0) cout<<"û�н�һ����"<<endl; 
	}
}
int student::signIn_student()
{
	int NO;
	string Name;
	cout<<"������ѧ��:";cin>>NO;
	cout<<"����������:";cin>>Name;
	ifstream ifs;
	ifs.open("VIP.txt");
	if(!ifs)
	{
		cout<<"�򲻿��ļ�";  
	} else 
	while(!ifs.eof())
	{
		int no;
		string name;
		ifs>>no>>name;
		if(ifs.fail())
		{
			return 3;
			break;
		}
		if(NO==no&&Name==name)
		{
			this->NO=NO;
			this->name=Name;
			return 1;
			break;
		}
		ifs.get();
	}
	ifs.close(); 
}

