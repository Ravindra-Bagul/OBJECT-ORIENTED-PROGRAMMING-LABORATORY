#include<iostream>
using namespace std;

class complex
{
    public:
    float real,img;
    complex()
    {
        real=img=0;
    }
    complex operator + (complex);
    complex operator * (complex);
    friend ostream &operator << (ostream &, complex &);
    friend istream &operator >> (istream &, complex &);
};

complex complex :: operator + (complex obj)
{
    complex temp;
    temp.real = real + obj.real;
    temp.img = img + obj.img;
    return temp;
}
complex complex :: operator * (complex obj)
{
	
    complex temp;
    temp.real = ((real*obj.real) - (img*obj.img));
    temp.img = ((img*obj.real) + (real*obj.img));
    return temp;
}
istream &operator >>(istream &input, complex &obj)
{
    input>>obj.real;
    input>>obj.img;
    return input;
}

ostream &operator <<(ostream &output, complex &obj)
{
    output<<" "<<obj.real<<"+"<<obj.img<<"i";
    return output;
}
int main()
{
	complex c1,c2,c3,c4;
	int a;
	do
	{
	cout<<"\n 1.Default constructor which assigns x=0,y=0. \n";
	cout<<" 2.Input the two complex numbers. \n";
	cout<<" 3.Display the two complex numbers. \n";
	cout<<" 4.Add the two complex numbers. \n";
	cout<<" 5.Multiply the two complex numbers. \n";
	cout<<" 6.Exit\n";
	cout<<"\nEnter the choice : ";
	cin>>a;
    cout<<endl;
	switch(a)
	{
		case 1:
				cout<<"Current value of complex number is : ";
				cout<<c1<<endl;
				break;
		case 2:
			{	cout<<"For 1st complex number : \n";
				cin>>c1;
				cout<<"For 2nd complex number : \n";
				cin>>c2;
				break;
			}
		case 3:
			{	cout<<"1st complex number is : \t"<<c1<<endl;
				cout<<"2nd complex number is : \t"<<c2<<endl;
				break;
			}
		case 4:
				c3=c1+c2;
				cout<<"The Addition of the two complex numbers is : \t"<<c3<<endl;
			    break;
		case 5:
				c4=c1*c2;
				cout<<"The Multiplication of the two complex numbers is : \t"<<c4<<endl;
				break;
	}
	}while(a!=6);
	return 0;  
}