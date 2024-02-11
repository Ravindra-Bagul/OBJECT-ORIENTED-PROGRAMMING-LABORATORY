#include<iostream>
#include<iterator>
#include<map>
using namespace std;
int main()
{
	string state_no,state_no1;
	int po,n;
	map<string,int>state;
	cout<<"How many entries in a map :";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"State Nmae : ";
		cin>>state_no;
		cout<<"Population :";
		cin>>po;
		state.insert(pair<string,int>(state_no,po));
	}
	map<string,int>::iterator itr;
	cout<<"The map state is :"<<endl;
	cout<<"State \t Population\n";
	for(itr=state.begin();itr!=state.end();itr++)
	{
		cout<<"\t"<<itr->first<<"\t"<<itr->second<<"\n";
	}
	cout<<endl;
	cout<<"Enter the state:";
	cin>>state_no1;
	itr=state.find(state_no1);
	if(itr==state.end())
	{
		cout<<"Key.value pair is not present in map";
	}
	else
	{
		cout<<"key.value pair is present";
		cout<<itr->first<<"->"<<itr->second;
		cout<<endl;
	}
	return 0;
}
