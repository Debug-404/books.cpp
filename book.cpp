#include"book.h"
books::books(string bookName,string author,string press,int bookQuantity)
{
	this->bookName=bookName;
	this->author=author;
	this->press=press;
	this->bookQuantity=bookQuantity;
}
books::~books()
{
	
}
void books::readBook()//��ȡ�鼮��Ϣ 
{
	
	ifstream ifs;
	ifs.open("Book.txt");
	if(!ifs)
	{
		cout<<"�򲻿�Book�ļ�";  
	} else 
	while(!ifs.eof())
	{
		string bookName;
	    string author;
	    string press; 
	    int bookQuantity;
		ifs>>bookName>>author>>press>>bookQuantity;
		if(ifs.fail())break;
		books book(bookName,author,press,bookQuantity);
		b.push_back(book);	
		ifs.get();
		//if(ifs.peek()==EOF)break;
		
	}
	ifs.close();
}
void books::backupsBook()//����ͼ����Ϣ���ļ�  
{
	ofstream ofs;
	ofs.open("Book.txt");
	if(!ofs)
	{
		cout<<"�򲻿�Book�ļ�";  
	} 
	else
	for(vector<books>::iterator it=b.begin();it!=b.end();it++)
	ofs<<(*it).getbookName()<<"\t"<<it->getAuthor()<<"\t"<<it->getPress()<<"\t"<<it->getbookQuantity()<<endl;
	ofs.close();
	cout<<"лл����ʹ�ã�"<<endl;
 } 
string books::getbookName()//��������
{
	return bookName;
}
string books::getbookName(string bookName)//���� 
{
	this->bookName=bookName;
	return bookName;
}
string books::getAuthor()//��������
{
	return author;
}
string books::getAuthor(string Author)//���� 
{
	this->author=Author;
	return author;
}
string books::getPress()//���س�����
{
	return press;
}
string books::getPress(string Press)//���� 
{
	this->press = Press;
	return Press;
 } 
int books::getbookQuantity()//��������
{
	return bookQuantity;
}
int books::getbookQuantity(int bookQuantity)//���� 
{
	this->bookQuantity=bookQuantity;
	return bookQuantity;
}
void books::printBook()//չʾȫ��ͼ�� 
{
	cout<<"����"<<"\t"<<"����"<<"\t"<<"������"<<"\t"<<"����"<<endl;
	for(vector<books>::iterator it=b.begin();it!=b.end();it++)
	{
		cout<<(*it).getbookName()<<"\t"<<it->getAuthor()<<"\t"<<it->getPress()<<"\t"<<it->getbookQuantity()<<endl;
	 }
}
void books::lookup(books &book)
{
	int i;
		while(1)
		{
			system("cls");
			cout<<"��ѡ����ҷ�ʽ"<<endl;
			cout << "1������������"<<endl;
			cout << "2�����߲���"<<endl;
			cout << "3�����������"<<endl;
			cout << "0������������"<<endl;
			cout << "��ѡ��";
			cin>>i;
			switch(i)
			{
				case 1:;book.lookupBook();return;
				case 2:;book.lookupAuthor();return;
				case 3:;book.lookupPress();return;
				case 0:return;
				default:cout<<"��������������..."<<endl;break;
			}
			}
}
void books::lookupBook()//����������
{
	system("cls");
	string bookName;
	int i=0;
	cout<<"������Ҫ�����鼮�����֣�";
	cin>>bookName; 
	for(vector<books>::iterator it=b.begin();it!=b.end();it++)
	{
		if(it->getbookName()==bookName)
		{
			cout<<"�����ҵ��鼮��Ϣ��";
			cout<<(*it).getbookName()<<"\t"<<it->getAuthor()<<"\t"<<it->getPress()<<"\t������"<<it->getbookQuantity()<<endl;
			i++;
		 } 
		 else 
		 	if(it==b.end()-1&&it->getbookName()!=bookName&&i==0)
		 {
		 	cout<<"û��"<<bookName<<"�Ȿ��"<<endl;
		 }
	 }
} 
void books::lookupAuthor()//�������߲��� 
{
	system("cls");
	int i=0;
	string author;
	 cout<<"������Ҫ�����鼮�����ߣ�";
	 cin>>author;
 	for(vector<books>::iterator it=b.begin();it!=b.end();it++)
	{
		if(it->getAuthor()==author)
		{
			cout<<"����������д�����У�";
			cout<<(*it).getbookName()<<"\t"<<it->getAuthor()<<"\t"<<it->getPress()<<"\t������"<<it->getbookQuantity()<<endl;
			i++;
		 } 
		 else 
		 	if(it==b.end()-1&&it->getAuthor()!=author&&i==0)
		 {
		 	cout<<"û��"<<author<<"����д����"<<endl;
		 }
	 }
}
void books::lookupPress()//���ճ�������� 
{
	system("cls");
	int i=0; 
	string press;
	cout<<"������Ҫ�����鼮�ĳ����磺";
	cin>>press;
	for(vector<books>::iterator it=b.begin();it!=b.end();it++)
	{
		if(it->getPress()==press)
		{
			cout<<"�����ҵĳ������������У�";
			cout<<(*it).getbookName()<<"\t"<<it->getAuthor()<<"\t"<<it->getPress()<<"\t������"<<it->getbookQuantity()<<endl;
			i++;
		}
		else
		    if(it==b.end()-1&&it->getPress()!=press&&i==0)
		   {
		   	 cout<<"û��"<<press<<"������������"<<endl;
		   }
	}
	
}
