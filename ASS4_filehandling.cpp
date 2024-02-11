/* 
Author - Ravindra Dayaram Bagul
College - SKNCOE, Pune
University - SPPU
*/

/*
Assignment No: B-2
Write a C++ program that creates an output file, writes information to it, closes the file 
andopen it again as an input file and read the information from the file
*/

#include<iostream>
#include<fstream>
using namespace std;

class student
{
	string name;
	int rollno, marks;
	
	public:
	void getdata()
	{	
		ofstream f1;
		f1.open("ravi.txt",ios::app);
		cout<<"Enter name of Student : ";
		cin>>name;
		cout<<"Enter Roll No. of Student : ";
		cin>>rollno;
		cout<<"Enter Marks of Student : ";
		cin>>marks;
		f1<<"Name"<<"\t"<<"   Roll No"<<"\t"<<"Marks"<<endl;
		f1<<name<<"\t"<<rollno<<"\t"<<"\t"<<marks<<endl;
		f1.close();
	}
	void display()
	{	
		ifstream f2;
		f2.open("ravi.txt");
		cout<<"Name of Student : "<<name<<endl;
		cout<<"Roll No. of Student : "<<rollno<<endl;
		cout<<"Marks of Student : "<<marks<<endl;
		f2>>name>>rollno>>marks;
		f2.close();
	}
};

int main()
{	
	student s[10];
	int ch, count=0;
	do
	{
		cout<<endl<<"Student information System"<<endl;
		cout<<"===========Menu==========="<<endl;
		cout<<"1.Add Student Data"<<endl;
		cout<<"2.Display Student Data"<<endl;
		cout<<"3.Exit"<<endl;
		cout<<"Enter your Choise : ";
		cin>>ch;
		cout<<endl;		
		switch (ch)
		{
		case 1 :
		s[count].getdata();
		count++;
		break;
		
		case 2 :
		for(int i=0; i<count;i++)
		{	
			s[i].display();
		}
		break;
		
		case 3 :
		exit(0);
		}
	}while (ch!=3);
	return 0;
}