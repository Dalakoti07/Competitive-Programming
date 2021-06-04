#include <bits/stdc++.h>
using namespace std;

vector<string> mappings=vector<string>{"","","abc","def","ghi"
	,"jkl","mno","pqrs","tuv","wxyz",""};

vector<string> phoneNumberMnemonics(string phoneNumber) {
	if(phoneNumber.size()==0)
		return{};
	vector<string> answers;
	if(phoneNumber.size()==1){
		string tempStr="";
		char first=phoneNumber[0];
		vector<string> answers;
		string mapped=mappings[first-'0'];
		if(mapped.size()==0){
			answers.push_back(tempStr+first);
		}else{
			for(int i=0;i<mapped.size();i++)
				answers.push_back(tempStr+mapped[i]);
		}
		return answers;
	}
	vector<string> answerRec=phoneNumberMnemonics(phoneNumber.substr(1));
	char first=phoneNumber[0];
	string mapped=mappings[first-'0'];
	for(string s:answerRec){
		if(mapped.size()==0){
			answers.push_back(first+s);
		}else{
			for(int i=0;i<mapped.size();i++)
				answers.push_back(mapped[i]+s);
		}
	}
  return answers;
}
