#include<string>
#include<iostream>
using namespace std;
bool check(string str)
{
	if(str=="bob"||str=="obb"||str=="bbo")
		return true;
	else
		return false;
}
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		string str1,str2;
		cin>>str1>>str2;
	if(check(str1)||check(str2))
			cout<<"yes\n";
	// string one flipped one by one
	else if(check(str2[0]+str1.substr(1,2)))
	
		cout<<"yes\n";
		
	
	else if(check(str1.substr(0,1)+str2[1]+str1[2]))
	
		cout<<"yes\n";
		
	
	
	else if(check(str1.substr(0,2)+str2[2]))
	
		cout<<"yes\n";
		
	
	
	// string two flipped one by one
	else if(check(str1[0]+str2.substr(1,2)))
	
		cout<<"yes\n";
		
	
	else if(check(str2.substr(0,1)+str1[1]+str2[2]))
		
		cout<<"yes\n";
		
	
	else if(check(str2.substr(0,2)+str1[2]))
		
		cout<<"yes\n";
		
	
	else
		cout<<"no\n";
		
	}
	

}