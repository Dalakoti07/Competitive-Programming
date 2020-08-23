#include<bits/stdc++.h>
using namespace std;
// #include"findMinFibonacciNumbers.cpp"
// #include"findDuplicate.cpp"
#include"uniqueBST.cpp"

void readVector(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
}

void readGraph(){
    // see questions
}

void readString(){
    string str;
    cin>>str;

}

void readInt2DMatrix(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];

}

void readChar2DMatrix(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> arr(n,vector<char>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    
}

void readAInteger(){
    cout<<"reading an int ";
    int a;
    cin>>a;

    Solution* solution= new Solution();
    cout<<solution->numTrees(a)<<endl;
}

int main(){
    cout<<"read following data strructures \n1. vector of size n\n";
    cout<<"2. graph with n nodes and e edges\n";
    cout<<"3. string \n";
    cout<<"4. 2d matrix of int size n*m \n";
    cout<<"5. 2d matrix of char size n*m\n";
    cout<<"6. a simple integer\n";
    int choice;
    cin>>choice;
    switch(choice){
        case 1: readVector(); break;
        case 2: readGraph(); break;
        case 3: readString(); break;
        case 4: readInt2DMatrix(); break;
        case 5: readChar2DMatrix(); break;
        case 6: readAInteger(); break;
        default: break;
    }
}