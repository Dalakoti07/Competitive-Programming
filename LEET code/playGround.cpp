#include<bits/stdc++.h>
using namespace std;

int main(){
    string testString ="hello";
    cout<<testString.substr(0,1)<<endl; //h
    cout<<testString.substr(1,0)<<endl; // ''
    cout<<testString.substr(1,1)<<endl; //e

    for(char i:testString){
        cout<<i<<"\t";
    }

    vector<string> mappy{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    for(string i :mappy){
        cout<<i<<endl;
    }

    vector<string> answer= vector<string>();// remember bo new keyword
    char itchy='a';
    string s(1,itchy);
    answer.push_back(s);
    for(string s:answer){
        cout<<s<<endl;
    }

    // it would make the vector named set, with 1,2 and 3 as it entries
    vector<int> set = vector<int>{1,2,3};

    if(NULL and 1){
        cout<<" null and 1 is true \n";
    }else{
        cout<<" null and 1 is false \n";
    }

    if(NULL or 1){
        cout<<" null or 1 is true \n";
    }else{
        cout<<" null or 1 is false \n";
    }
}