#include<iostream>
#include<stdlib.h>
using namespace std;

class student
{
	string name,clas,dob,bg,addr,lic;
	int*rollno,div;
	long int mob;
	
	public:
	friend class teacher;
	
	student()
	{
	    rollno=new int;
	    name,clas,bg,addr,lic=" ";
	    dob = "dd/mm/yyyy";
	    *rollno,div,mob=0;
	    
	}
	
	student(student &obj)
		{
		    this->name=obj.name;
		    this->addr=obj.addr;
		    this->clas=obj.clas;
		    this->div=obj.div;
		    this->rollno=obj.rollno;
		    this->bg=obj.bg;
		    this->dob=obj.dob;
		}
	~student()
	{
	    delete rollno;
	}
	
	inline static void display_header()
	{
	    cout<<"---------------------Student Information System------------------------"<<endl;
	    cout<<"Name\t\t Roll No\t Division\t Class\t Date of Birth\t Mobile\t Blood Group\tAddress\tLicense Number"<<endl;
	}
	
	void getdata()
	{
	    cout<<endl<<"Enter Roll no. :  ";
	    cin>>*rollno;
	    cout<<endl<<"Enter name :  ";
	    cin.ignore();
	    getline(cin,name);
	    cout<<endl<<"Enter division :  ";
	    cin>>div;
	    cout<<endl<<"Enter Mobile No. :  ";
	    cin>>mob;
	    cout<<endl<<"Enter class :  ";
	    cin>>clas;
	    cout<<endl<<"Enter Date of Birth :  ";
	    cin>>dob;
	    cout<<endl<<"Enter Blood Groop :  ";
	    cin>>bg;
	    cout<<endl<<"Enter Address :  ";
	    cin>>addr;
	    cout<<endl<<"Enter License Number :  ";
	    cin>>lic;
	    
	}
	
	void display()
	{
	    cout<<"\n"<<name<<"\t"<<*rollno<<"\t"<<div<<"\t"<<clas<<"\t"<<dob<<"\t"<<mob<<"\t"<<bg<<"\t"<<addr<<"\t"<<lic;
	
	}
};

class teacher
{
	int id;
	public:
	teacher()
	{
	    id=0;
	}
	void display_t(student &obj1,int t_d)
	{
	    try{
	        if(obj1.div==t_d)
	        obj1.display();
	        else
	        throw(obj1.div);
	    }
	    catch(int x)
	    {
	        cout<<"student & teacher division can not match"<<endl;
	    }
	}
};

int main()
{
    student s[10];
    teacher t;
    int ch,count=0;
    do
    {
        cout<<endl<<"Student Information System"<<endl;
        cout<<"------------Menu------------"<<endl;
        cout<<"1.Add Student Record"<<endl;
        cout<<"2.Display Student Record"<<endl;
        cout<<"3.Copy Constructor"<<endl;
        cout<<"4.Division Wise Information"<<endl;
        cout<<"5.Exit"<<endl<<endl;
        cout<<"Enter your Choise :  ";
		cin>>ch;
		cout<<endl;
        
		
        switch(ch)
        {
            case 1:
            s[count].getdata();
            count++;
            break;

            case 2:
            student::display_header();
            for(int i=0; i<count; i++)
            {
                s[i].display();
            }
            break;

            case 3:
            {
                cout<<"copy constructor"<<endl;
                student s1;
                s1.getdata();
                student s2(s1);
                s2.display();

            }
            break;

            case 4:
            int t_div;
            cout<<"enter division"<<endl;
            cin>>t_div;
            for(int i=0; i<count; i++)
            {
                t.display_t(s[i],t_div);

            }
            break;

            case 5:
            exit(0);
        } 
    } while (ch!=5);
    return 0;
}
