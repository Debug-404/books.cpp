#include"bookManage.h"
void bookManage::menu_Manage()
{
	cout << "ͼ����Ϣ����ϵͳ" << endl;
    cout << "-----------------" << endl;
    cout << "1��ͼ����Ϣ���" << endl;
    cout << "2��ͼ����Ϣչʾ" << endl;
    cout << "3��ͼ����Ϣ����" << endl;
    cout << "4��ͼ����Ϣɾ��" << endl;
    cout << "5��ͼ����Ϣ�޸�" << endl;
    cout << "6������ѧ��Ȩ��" << endl;
    cout << "7��չʾ�ѽ�ͼ��" << endl;
    cout << "0�������˳�ϵͳ" << endl;
    cout << "-----------------" << endl;
}
void bookManage::operation_Manage(bookManage &book)
{
	while(1)
    {   system("cls");
    	book.menu_Manage();
    int ch=0;
    cout<<"��ѡ��";cin>>ch;
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
    			cout<<"����������������룺"<<endl; 
	}
	}
}
void bookManage::deleteBook()//ɾ���鼮 
{
	string bookName;
	cout<<"������Ҫɾ�����鼮����";
	cin>>bookName;
	for(vector<books>::iterator it=b.begin();it!=b.end();it++)
	{
		if(it->getbookName()==bookName)
		{
			b.erase(it);
			cout<<bookName<<"\t"<<"�Ѿ�ɾ��"<<endl;
			break; 
		 } 
		 else if(it==b.end()-1)
		 cout<<"û�С���"<< bookName<<"�����Ȿ��"<<endl;
	 }
}
void bookManage::addBook()//����鼮 
{
	int i=0,j=0;
	string bookName,author,press;
	int bookQuantity;
	cout<<"������Ҫ��ӵ��鼮���֣����ߣ������磬�������ո����"<<endl;
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
	 else cout<<"<<"<<bookName<<">>"<<"�����Ѿ�����"<<endl;
}
void bookManage::modifyBook()//�޸��鼮��Ϣ 
{
	string bookName,author,press;
	int bookQuantity;
	cout<<"������Ҫ�޸�ͼ���������";
	cin>>bookName;
	for(vector<books>::iterator it=b.begin();it!=b.end();it++)
	{
		if(it->getbookName()==bookName)
		{
			int m;
			string bookName,author,press;
	        int bookQuantity;
			cout<<(*it).getbookName()<<"\t"<<it->getAuthor()<<"\t"<<it->getPress()<<"\t������"<<it->getbookQuantity()<<endl;
			while(1){
			system("cls");
			cout << "��Ҫ�޸ĵģ�"<<endl;
			cout << "1������"<<endl;
			cout << "2������"<<endl;
			cout << "3��������"<<endl;
			cout << "4������"<<endl;
			cout << "0������������"<<endl;
			cout << "��ѡ��";
			cin>>m;
			switch(m)
			{
				case 1:cout << "������������";cin>>bookName;it->getbookName(bookName);cout<<"�޸ĳɹ���"<<endl;return;
				case 2:cout << "���������ߣ�";cin>>author;it->getAuthor(author);cout<<"�޸ĳɹ���"<<endl;return;
				case 3:cout << "����������磺";cin>>press;it->getPress(press);cout<<"�޸ĳɹ���"<<endl;return;
				case 4:cout << "������������";cin>>bookQuantity;it->getbookQuantity(bookQuantity);cout<<"�޸ĳɹ���"<<endl;return;
				case 0:return;
				default:cout<<"��������������..."<<endl;break;system("pause");
			}
			cout<<"�޸ĳɹ���"<<endl;
			}
		 } else if(it==b.end()-1&&it->getbookName()!=bookName) cout<<"û��"<<"����"<<bookName<<"����"<<"�Ȿ��"<<endl; 
	 }
}
void Index()
{
	int i;
	system("cls");
	cout<<"\n";
	      cout<<"1,ѧ���� students "<<endl;
		  cout<<"2������Ա�� managers"<<endl;
		  cout<<"0���˳�ϵͳ exit "<<endl;
		  cout<<endl; 
		  cout<<"��ѡ�� select ��";
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
				}else cout<<"������ȷ��ѧ�ź�����"<<endl;
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
				}else cout<<"����Ա��Կ����ȷ������ȷ��"<<endl;
	            system("pause");
				Index();
			case 0:	cout<<"лл����ʹ�ã�"<<endl;exit(0);
				break; 
			default:
				cout<<"��������������"<<endl;
				system("pause");
				Index();
}
}
int bookManage::signIn_Manage()
{
	string NO;
	cout<<"���������Ա��Կ:";cin>>NO;
	ifstream ifs;
	ifs.open("administrators.txt");
	if(!ifs)
	{
		cout<<"�򲻿��ļ�";  
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
			cout<<"ѧ����Ϣ����"<<endl;
			cout << "1��ɾ��ѧ��"<<endl;
			cout << "2������ѧ��"<<endl;
			cout << "3��չʾ������"<<endl;
			cout << "0������������"<<endl;
			cout << "��ѡ��";
			cin>>i;
			switch(i)
			{
				case 1:book.delete_Student();return;
				case 2:book.add_Student();return;
				case 3:book.print_student();return;
				case 0:return;
				default:cout<<"��������������..."<<endl;break;
			}
		}
}
void bookManage::add_Student()//����ѧ�� 
{
	system("cls");
	int i=0,j=0;
	int NO;
	string name;
	cout<<"������Ҫ��ӵ�ѧ����ѧ�ź����֡��ո����"<<endl;
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
	    cout<<"ѧ�ţ�"<<NO<<"������"<<name<<"�Ѿ����"<<endl;
	 }
	 else cout<<"<<"<<name<<">>"<<"��ѧ���Ѿ����ڰ�������"<<endl;
}
void bookManage::delete_Student()//ɾ��ѧ�� ���ĵ�����ʧЧ 
{
	system("cls");
	int NO;
	cout<<"������Ҫɾ����ѧ����ѧ�ţ�";
	cin>>NO;
	for(vector<student>::iterator T=w.begin();T!=w.end();)//���������������� 
	{
		if(T->getNo()==NO)
		{
			T=w.erase(T);
			cout<<"ѧ��Ϊ��"<<NO<<"\t"<<"��ѧ���Ѿ��Ӱ�������ɾ��"<<endl;
				for(vector<student>::iterator S=v.begin();S!=v.end();)//�������������� 
	        if(S->getNo()==NO)
		{
			for(vector<books>::iterator it=b.begin();it!=b.end();it++)//�鼮������ 
	        if(it->getbookName()==S->getBorrowbook())
		    it->getbookQuantity(it->getbookQuantity()+S->getNum());
			v.erase(S);
		}
		else S++;
		 } 
		 else if(T==v.end()-1)
		 cout<<"û��ѧ��Ϊ��"<< NO<<"��ѧ��"<<endl;
		 else T++ ; 
	 }
}
void bookManage::print_student()//չʾ������ 
{
	system("cls");
	cout<<"���������"<<endl; 
	cout<<"ѧ��"<<"\t"<<"����"<<endl;
	for(vector<student>::iterator T=w.begin();T!=w.end();T++)
	{
		cout<<(*T).getNo()<<"\t"<<T->getName()<<endl;
	 }
}
void bookManage::print_book(bookManage& book)//�������� 
{
	cout<<"������"<<" "<<"�����"<<" "<<"�������"<<endl;
	for(vector<student>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<(*it).getName()<<"\t"<<it->getBorrowbook()<<"\t"<<it->getNum()<<endl;
	 }
}
void bookManage::read_Vip()//��ȡ��������� 
{
	ifstream ifs;
	ifs.open("VIP.txt");
	if(!ifs)
	{
		cout<<"�򲻿��ļ�";  
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
void bookManage::backups_Vip()//���ݽ�������� 
{
	ofstream ofs;
	ofs.open("VIP.txt");
	if(!ofs)
	{
		cout<<"�򲻿��ļ�";  
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
