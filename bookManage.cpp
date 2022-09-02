#include"bookManage.h"
void bookManage::menu_Manage()
{
	cout << "图书信息管理系统" << endl;
    cout << "-----------------" << endl;
    cout << "1、图书信息添加" << endl;
    cout << "2、图书信息展示" << endl;
    cout << "3、图书信息查找" << endl;
    cout << "4、图书信息删除" << endl;
    cout << "5、图书信息修改" << endl;
    cout << "6、管理学生权限" << endl;
    cout << "7、展示已借图书" << endl;
    cout << "0、备份退出系统" << endl;
    cout << "-----------------" << endl;
}
void bookManage::operation_Manage(bookManage &book)
{
	while(1)
    {   system("cls");
    	book.menu_Manage();
    int ch=0;
    cout<<"请选择：";cin>>ch;
    switch(ch)
    {
    	case 1:
    		system("cls");
    	  book.addBook();
    	  system("pause");
    		break;
    	case 2:
    	    	system("cls");
    	  book.printBook();
    	  system("pause");
    		break;
    	case 3:
    			system("cls");
    	  book.lookup(book);
    	  system("pause");
    		break;
    	case 4:
    		system("cls");
    	  book.deleteBook();
    	  system("pause");
    		break;
		case 5:
			system("cls");
    	  book.modifyBook();
    	  system("pause");
    		break;
    	case 6:
			system("cls"); 
			book.student_Manage(book);
    	  system("pause");
    		break;
    	case 7:
			system("cls"); 
			book.print_book(book);
    	  system("pause");
    		break;
		case 0: 
		book.sortStudent();
			book.backups_Vip();
			book.backupsBook();
			book.backups_student();
			Index();
    		break;
    		default:
    			cout<<"输入错误请重新输入："<<endl; 
	}
	}
}
void bookManage::deleteBook()//删除书籍 
{
	string bookName;
	cout<<"输入你要删除的书籍名：";
	cin>>bookName;
	for(vector<books>::iterator it=b.begin();it!=b.end();it++)
	{
		if(it->getbookName()==bookName)
		{
			b.erase(it);
			cout<<bookName<<"\t"<<"已经删除"<<endl;
			break; 
		 } 
		 else if(it==b.end()-1)
		 cout<<"没有《《"<< bookName<<"》》这本书"<<endl;
	 }
}
void bookManage::addBook()//添加书籍 
{
	int i=0,j=0;
	string bookName,author,press;
	int bookQuantity;
	cout<<"输入你要添加的书籍名字，作者，出版社，数量。空格隔开"<<endl;
	cin>>bookName>>author>>press>>bookQuantity;
	for(vector<books>::iterator it=b.begin();it!=b.end();it++)
	{
		++i;
		if(it->getbookName()!=bookName)
		{
			++j;
		}
	 }
	 if(i==j)
	 {
	 	books book(bookName,author,press,bookQuantity);
	    b.push_back(book); 
	 }
	 else cout<<"<<"<<bookName<<">>"<<"该书已经存在"<<endl;
}
void bookManage::modifyBook()//修改书籍信息 
{
	string bookName,author,press;
	int bookQuantity;
	cout<<"输入你要修改图书的书名：";
	cin>>bookName;
	for(vector<books>::iterator it=b.begin();it!=b.end();it++)
	{
		if(it->getbookName()==bookName)
		{
			int m;
			string bookName,author,press;
	        int bookQuantity;
			cout<<(*it).getbookName()<<"\t"<<it->getAuthor()<<"\t"<<it->getPress()<<"\t数量："<<it->getbookQuantity()<<endl;
			while(1){
			system("cls");
			cout << "需要修改的："<<endl;
			cout << "1、书名"<<endl;
			cout << "2、作者"<<endl;
			cout << "3、出版社"<<endl;
			cout << "4、数量"<<endl;
			cout << "0、返回主界面"<<endl;
			cout << "请选择：";
			cin>>m;
			switch(m)
			{
				case 1:cout << "请输入书名：";cin>>bookName;it->getbookName(bookName);cout<<"修改成功！"<<endl;return;
				case 2:cout << "请输入作者：";cin>>author;it->getAuthor(author);cout<<"修改成功！"<<endl;return;
				case 3:cout << "请输入出版社：";cin>>press;it->getPress(press);cout<<"修改成功！"<<endl;return;
				case 4:cout << "请输入数量：";cin>>bookQuantity;it->getbookQuantity(bookQuantity);cout<<"修改成功！"<<endl;return;
				case 0:return;
				default:cout<<"输入有误，请重试..."<<endl;break;system("pause");
			}
			cout<<"修改成功！"<<endl;
			}
		 } else if(it==b.end()-1&&it->getbookName()!=bookName) cout<<"没有"<<"《《"<<bookName<<"》》"<<"这本书"<<endl; 
	 }
}
void Index()
{
	int i;
	system("cls");
	cout<<"\n";
	      cout<<"1,学生端 students "<<endl;
		  cout<<"2，管理员端 managers"<<endl;
		  cout<<"0，退出系统 exit "<<endl;
		  cout<<endl; 
		  cout<<"请选择 select ：";
		  cin>>i;
		  student stu;
		  bookManage book;
		  switch(i){
			case 1:
				system("cls");
				if(stu.signIn_student()==1)
				{
					stu.readBook();
					stu.read_Student();
				    stu.operation_Student(stu);
				}else cout<<"请重新确认学号和姓名"<<endl;
				system("pause");
				Index();
			case 2:
				system("cls");
				if(book.signIn_Manage()==1)
				{
					book.read_Vip();
					book.readBook();
					book.read_Student();
	                book.operation_Manage(book);
				}else cout<<"管理员密钥不正确请重新确认"<<endl;
	            system("pause");
				Index();
			case 0:	cout<<"谢谢您的使用！"<<endl;exit(0);
				break; 
			default:
				cout<<"请重新输入输入"<<endl;
				system("pause");
				Index();
}
}
int bookManage::signIn_Manage()
{
	string NO;
	cout<<"请输入管理员密钥:";cin>>NO;
	ifstream ifs;
	ifs.open("administrators.txt");
	if(!ifs)
	{
		cout<<"打不开文件";  
	} else 
	while(1)
	{
		string no;
		ifs>>no;
		if(NO==no)
		{
			return 1;
			break;
		}
		ifs.get();
		if(ifs.peek()==EOF)
		{
			return 2;
			break;
		}
	}
	ifs.close(); 
}
void bookManage::student_Manage(bookManage &book)
{
	int i;
		while(1)
		{
			system("cls");
			cout<<"学生信息管理"<<endl;
			cout << "1、删除学生"<<endl;
			cout << "2、增加学生"<<endl;
			cout << "3、展示白名单"<<endl;
			cout << "0、返回主界面"<<endl;
			cout << "请选择：";
			cin>>i;
			switch(i)
			{
				case 1:book.delete_Student();return;
				case 2:book.add_Student();return;
				case 3:book.print_student();return;
				case 0:return;
				default:cout<<"输入有误，请重试..."<<endl;break;
			}
		}
}
void bookManage::add_Student()//增加学生 
{
	system("cls");
	int i=0,j=0;
	int NO;
	string name;
	cout<<"输入你要添加的学生的学号和名字。空格隔开"<<endl;
	cin>>NO>>name;
	for(vector<student>::iterator T=w.begin();T!=w.end();T++)
	{
		++i;
		if(T->getName()!=name)
		{
			++j;
		}
	 }
	 if(i==j)
	 {
	 	student stu(NO,name);
	    w.push_back(stu); 
	    cout<<"学号："<<NO<<"姓名："<<name<<"已经添加"<<endl;
	 }
	 else cout<<"<<"<<name<<">>"<<"该学生已经存在白名单中"<<endl;
}
void bookManage::delete_Student()//删除学生 核心迭代器失效 
{
	system("cls");
	int NO;
	cout<<"输入你要删除的学生的学号：";
	cin>>NO;
	for(vector<student>::iterator T=w.begin();T!=w.end();)//白名单容器迭代器 
	{
		if(T->getNo()==NO)
		{
			T=w.erase(T);
			cout<<"学号为："<<NO<<"\t"<<"的学生已经从白名单中删除"<<endl;
				for(vector<student>::iterator S=v.begin();S!=v.end();)//借书名单迭代器 
	        if(S->getNo()==NO)
		{
			for(vector<books>::iterator it=b.begin();it!=b.end();it++)//书籍迭代器 
	        if(it->getbookName()==S->getBorrowbook())
		    it->getbookQuantity(it->getbookQuantity()+S->getNum());
			v.erase(S);
		}
		else S++;
		 } 
		 else if(T==v.end()-1)
		 cout<<"没有学号为："<< NO<<"的学生"<<endl;
		 else T++ ; 
	 }
}
void bookManage::print_student()//展示白名单 
{
	system("cls");
	cout<<"借书白名单"<<endl; 
	cout<<"学号"<<"\t"<<"姓名"<<endl;
	for(vector<student>::iterator T=w.begin();T!=w.end();T++)
	{
		cout<<(*T).getNo()<<"\t"<<T->getName()<<endl;
	 }
}
void bookManage::print_book(bookManage& book)//借书的情况 
{
	cout<<"借书人"<<" "<<"借的书"<<" "<<"借的数量"<<endl;
	for(vector<student>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<(*it).getName()<<"\t"<<it->getBorrowbook()<<"\t"<<it->getNum()<<endl;
	 }
}
void bookManage::read_Vip()//读取借书白名单 
{
	ifstream ifs;
	ifs.open("VIP.txt");
	if(!ifs)
	{
		cout<<"打不开文件";  
	} else 
	while(ifs.peek()!=EOF)
	{
		int NO;
	    string name;
		ifs>>NO>>name;
		if(ifs.fail())break;
		student stu(NO,name);
		w.push_back(stu);	
		ifs.get();
		//if(ifs.peek()=='\n')break;
	}
	ifs.close();
}
void bookManage::backups_Vip()//备份借书白名单 
{
	ofstream ofs;
	ofs.open("VIP.txt");
	if(!ofs)
	{
		cout<<"打不开文件";  
	} 
	else
	for(vector<student>::iterator T=w.begin();T!=w.end();T++)
	ofs<<T->getNo()<<"\t"<<T->getName()<<endl;
	ofs.close();
}
void bookManage::sortStudent()  
{
	bool cmp(student &,student &); 
    sort(w.begin(),w.end(),cmp);
    sort(v.begin(),v.end(),cmp);
} 
bool cmp(student& stu1,student& stu2)
{
	return stu1.getNo()<stu2.getNo();
}
