/*write a c++ program using STL for sorting,searching such as item records,code,name,cost, quantity using vector container.*/

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

class item
{
	public:
		string name,cost,code,quantity;

	bool operator ==(const item &i1)
	{
		if (code==i1.code)
		return 1;
		return 0;
	}

	bool operator <(const item &i1)
	{
		if (cost<i1.cost)
		return 1;
		return 0;
	}	
};

bool compare(const item &i1, const item &i2)
{
 if (i1.name != i2.name) 
 return i1.cost < i2.cost;
 //return i1.cost < i2.cost;
}

vector<item>o1;
void insert()
{
	item i1;
	cout<<"Enter name of item to be inserted : ";
	cin>>i1.name;

	cout<<"Enter the code of the object : ";
	cin>>i1.code;
	
	cout<<"Enter the cost of the item : ";
	cin>>i1.cost;
	
	cout<<"Enter the quantity of the item : ";
	cin>>i1.quantity;
    cout<<endl;
	o1.push_back(i1);
}

void display()
{
	for_each(o1.begin(),o1.end(),print);
}

void print(item &i1)
{
	cout<<"Name  of the  item is : "<<i1.name<<"\n";
	cout<<"Code of the object is : "<<i1.code<<"\n";
	cout<<"Cost of the object is : "<<i1.cost<<"\n";
	cout<<"Quantity of object is : "<<i1.quantity<<"\n";
	cout<<"____________________________________________";
	cout<<"\n\n";
}

void search()
{
	vector<item>::iterator p;
	item i1;
	cout<<"\nEnter code of item to be searched : ";
	cin>>i1.code;
	p=find(o1.begin(),o1.end(),i1);
	if(p==o1.end())
	{
		cout<<"The element is not found.\n";
	}
	else
	{
		cout<<"\nElement is found. \n";
		cout<<"\nName of the item : "<<p->name;
		cout<<"\nQuantity of the item is : "<<p->quantity;
		cout<<"\nCost of the item is : "<<p->cost;
		cout<<"\nCode of the item is : "<<p->code<<endl<<endl;
	}
}

void del()
{
	vector<item>::iterator p;
	item i1;
	cout<<"\nEnter code to be deleted. ";
	cin>>i1.code;
	p=find(o1.begin(),o1.end(),i1);
	if(p==o1.end())
	{
		cout<<"The element is not found. ";
	}
	else
	{
		o1.erase(p);
		cout<<"\nThe element is deleted. \n";
	}
}

int main()
{
	int ch;
	do
	{
    cout<<"_____________________________\n\n";
	cout<<"1.Insert the data of item. \n";
	cout<<"2.Display the data of item. \n";
	cout<<"3.Sort the data of items. \n";
	cout<<"4.Search the data in items. \n";
	cout<<"5.Delete any element. \n";
	cout<<"6.Exit from program. \n";
    cout<<"\nEnter your choise : ";
	cin>>ch;
    cout<<endl;
	
	switch(ch)
	{
		case 1:
			insert();
			break;
		case 2:
			display();
			break;
		case 3:
			sort(o1.begin(),o1.end(),compare);
			cout<<"Sorted on cost : \n";
			display();
			break;
		case 4:
			search();
			break;
		case 5:
			del();
			break;
		case 6:
			exit(0);
			break;
	}
	}while(ch!=6);
}