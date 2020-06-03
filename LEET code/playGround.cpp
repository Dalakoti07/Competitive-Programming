#include<bits/stdc++.h>
using namespace std;

int main(){
    // endl is slow and "\n" is fast
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

    // make a 2d array
    /*
    int** a = new int*[rowCount];
    for(int i = 0; i < rowCount; ++i)
        a[i] = new int[colCount];

    // delete array
    for(int i = 0; i < sizeY; ++i) {
        delete [] ary[i];
    }
    delete [] ary; 


    vector<vector<bool> > dp(N, vector<bool>(N, false));
    
    // fill array[N][N] diagonally
    for(int l = 1; l < N; l++) {
        for(int i = 0; i < N - l; i++) {
            int j = i + l;
            //arr[i][j] denotes a cell 
        }
    }*/
    
    cout<<testString[testString.length()-1]<<endl;
    string moreTest ="a";
    cout<<moreTest.substr(1).length();

    string emptyString="",nonEmptyString="nonEmpty";
    cout<<" is string empty : "<<emptyString.empty()<<"\n"; // if moreTest ="" ,its true
    cout<<" is string empty : "<<nonEmptyString.empty()<<"\n";// false

    //Generating every possible substring from a string of length n , requires O(n^2)

    vector<int> dp= vector<int>(100,0); // hundred sized dp vector withh all 0 initially
    cout<<moreTest+"b"<<"\n";

    string fakeString ="funk";
    cout<<"replacing "<<fakeString.replace(0,1,"d");
}