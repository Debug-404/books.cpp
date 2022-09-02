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
	cout << "图书信息管理系统" << endl;
    cout << "-----------------" << endl;
    cout << "1、借阅图书" << endl;
    cout << "2、归还图书" << endl;
    cout << "3、已借图书" << endl;
    cout << "4、图书展示" << endl;
    cout << "5、图书查找" << endl;
    cout << "0、退出系统" << endl;
    cout << "-----------------" << endl;
}
void student::operation_Student(student &stu)
{
	while(1)
    {   system("cls");
    	stu.menu_student();
    int ch=0;
    cout<<"请选择：";cin>>ch;
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
    			cout<<"输入错误请重新输入："<<endl; 
	}
}
}
void student::read_Student()//读取借书信息 
{
    int NO;
	string name;
	string borrowBook;
	int num;
	ifstream ifs;
	ifs.open("studentSystem.txt");
	if(!ifs)
	{
		cout<<"打不开studentSystem文件";  
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
void student::backups_student()//备份借书信息 
{
	ofstream ofs;
	ofs.open("studentSystem.txt");
	if(!ofs)
	{
		cout<<"打不开studentSystem文件";  
	} 
	else
	for(vector<student>::iterator T=v.begin();T!=v.end();T++)
	ofs<<T->getNo()<<"\t"<<T->getName()<<"\t"<<T->getBorrowbook()<<"\t"<<T->getNum()<<endl;
	ofs.close();
	cout<<"谢谢您的使用！"<<endl;
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
void student::borrow_Book()//借书 
{
	string bookName,author;
	int n,i=0,j=0;
	cout<<"请输入你需要借阅书籍的名字和数量:";
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
				cout<<bookName<<"\t"<<"已经借出"<<endl;
				student stu(this->NO,this->name,bookName,n);
		        v.push_back(stu);
			    break;
			}else cout<<"《《"<<bookName<<"》》"<<"该书数量不足";
			}	
			else cout<<"你已经借过"<<"《《"<<bookName<<"》》"<<"这本书了"<<endl;
		 } 
		 else if(it==b.end()-1&&j==0)
		 cout<<"没有《《"<< bookName<<"》》这本书"<<endl;
	 }
}
void student::still_Book()//还书 
{
	string bookName;
	int n=0; 
	cout<<"输入想还书的名字:";
	cin>>bookName;
	for(vector<student>::iterator T=v.begin();T!=v.end();T++)
	if(T->getBorrowbook()==bookName&&T->getNo()==this->NO)
		{
			n=T->getNum();
			for(vector<books>::iterator it=b.begin();it!=b.end();it++)
	        if(it->getbookName()==bookName)
    {
		it->getbookQuantity(it->getbookQuantity()+n);
		cout<<"已归还图书"<<endl; 
	}
			v.erase(T);
			break;
		 }
		 else if(T==v.end()-1)
		 cout<<"没有借《《"<< bookName<<"》》这本书"<<endl;
}
void student::borrowed_Book()//已借的书籍 
{
	int i=0;
	for(vector<student>::iterator T=v.begin();T!=v.end();T++)
	{
		if(this->name==T->getName())
		{
			i++;
			cout<<"已借《《"<<T->getBorrowbook()<<"》》\t"<<T->getNum()<<"本"<<endl;
		}else if(T==v.end()-1&&i==0) cout<<"没有借一本书"<<endl; 
	}
}
int student::signIn_student()
{
	int NO;
	string Name;
	cout<<"请输入学号:";cin>>NO;
	cout<<"请输入姓名:";cin>>Name;
	ifstream ifs;
	ifs.open("VIP.txt");
	if(!ifs)
	{
		cout<<"打不开文件";  
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

