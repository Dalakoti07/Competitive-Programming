#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        float targets;
        cin>>targets;
        vector<vector<char>> board=vector<vector<char>>(9,vector<char>(9,'.'));
        int row=ceil(targets/8);
        int col=int(targets)%8;
        // place the king
        board[row][col]='O';

        if((int(targets))%8 ==0){
            // handle the king at last index and make col=7
            col=8;
            board[row][8]='O';
        }

        // place the hurdle in remaining col of row        
        if(col!=0)
        for(int i=col+1;i<=8;i++)
            board[row][i]='X';
                
        
        // place hurdle in next row until diagonal hurdle
        if(row+1 <9 and col!=0)
        for(int i=1;i<=col+1 and i<=9;i++)
            board[row+1][i]='X';
    
        // print board
        for(int i=1;i<9;cout<<"\n",i++)
            for(int j=1;j<9;j++)
                cout<<board[i][j];
        // cout<<"\n";
    }
}