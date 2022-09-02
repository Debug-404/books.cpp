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
void books::readBook()//读取书籍信息 
{
	
	ifstream ifs;
	ifs.open("Book.txt");
	if(!ifs)
	{
		cout<<"打不开Book文件";  
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
void books::backupsBook()//备份图书信息到文件  
{
	ofstream ofs;
	ofs.open("Book.txt");
	if(!ofs)
	{
		cout<<"打不开Book文件";  
	} 
	else
	for(vector<books>::iterator it=b.begin();it!=b.end();it++)
	ofs<<(*it).getbookName()<<"\t"<<it->getAuthor()<<"\t"<<it->getPress()<<"\t"<<it->getbookQuantity()<<endl;
	ofs.close();
	cout<<"谢谢您的使用！"<<endl;
 } 
string books::getbookName()//返回书名
{
	return bookName;
}
string books::getbookName(string bookName)//重载 
{
	this->bookName=bookName;
	return bookName;
}
string books::getAuthor()//返回作者
{
	return author;
}
string books::getAuthor(string Author)//重载 
{
	this->author=Author;
	return author;
}
string books::getPress()//返回出版社
{
	return press;
}
string books::getPress(string Press)//重载 
{
	this->press = Press;
	return Press;
 } 
int books::getbookQuantity()//返回数量
{
	return bookQuantity;
}
int books::getbookQuantity(int bookQuantity)//重载 
{
	this->bookQuantity=bookQuantity;
	return bookQuantity;
}
void books::printBook()//展示全部图书 
{
	cout<<"书名"<<"\t"<<"作者"<<"\t"<<"出版社"<<"\t"<<"数量"<<endl;
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
			cout<<"请选择查找方式"<<endl;
			cout << "1、按书名查找"<<endl;
			cout << "2、作者查找"<<endl;
			cout << "3、出版社查找"<<endl;
			cout << "0、返回主界面"<<endl;
			cout << "请选择：";
			cin>>i;
			switch(i)
			{
				case 1:;book.lookupBook();return;
				case 2:;book.lookupAuthor();return;
				case 3:;book.lookupPress();return;
				case 0:return;
				default:cout<<"输入有误，请重试..."<<endl;break;
			}
			}
}
void books::lookupBook()//按书名查找
{
	system("cls");
	string bookName;
	int i=0;
	cout<<"输入你要查找书籍的名字：";
	cin>>bookName; 
	for(vector<books>::iterator it=b.begin();it!=b.end();it++)
	{
		if(it->getbookName()==bookName)
		{
			cout<<"您查找的书籍信息：";
			cout<<(*it).getbookName()<<"\t"<<it->getAuthor()<<"\t"<<it->getPress()<<"\t数量："<<it->getbookQuantity()<<endl;
			i++;
		 } 
		 else 
		 	if(it==b.end()-1&&it->getbookName()!=bookName&&i==0)
		 {
		 	cout<<"没有"<<bookName<<"这本书"<<endl;
		 }
	 }
} 
void books::lookupAuthor()//按照作者查找 
{
	system("cls");
	int i=0;
	string author;
	 cout<<"输入你要查找书籍的作者：";
	 cin>>author;
 	for(vector<books>::iterator it=b.begin();it!=b.end();it++)
	{
		if(it->getAuthor()==author)
		{
			cout<<"您查找作者写的书有：";
			cout<<(*it).getbookName()<<"\t"<<it->getAuthor()<<"\t"<<it->getPress()<<"\t数量："<<it->getbookQuantity()<<endl;
			i++;
		 } 
		 else 
		 	if(it==b.end()-1&&it->getAuthor()!=author&&i==0)
		 {
		 	cout<<"没有"<<author<<"作者写的书"<<endl;
		 }
	 }
}
void books::lookupPress()//按照出版社查找 
{
	system("cls");
	int i=0; 
	string press;
	cout<<"输入你要查找书籍的出版社：";
	cin>>press;
	for(vector<books>::iterator it=b.begin();it!=b.end();it++)
	{
		if(it->getPress()==press)
		{
			cout<<"您查找的出版社出版的书有：";
			cout<<(*it).getbookName()<<"\t"<<it->getAuthor()<<"\t"<<it->getPress()<<"\t数量："<<it->getbookQuantity()<<endl;
			i++;
		}
		else
		    if(it==b.end()-1&&it->getPress()!=press&&i==0)
		   {
		   	 cout<<"没有"<<press<<"出版社出版的书"<<endl;
		   }
	}
	
}
