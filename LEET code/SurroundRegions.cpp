class Solution {
public:
    void checkIfConnected(vector<vector<char>>& board, int startI,int startJ){
        cout<<"i: "<<startI<<" j: "<<startJ<<endl;
        int rows=board.size();
        int cols= board[0].size();
        bool atCorner=false,isConnectedToO=false;
        // check top
        if(startI-1 >=0){
            if(board[startI-1][startJ]=='O'){
            checkIfConnected(board,startI-1,startJ);
                isConnectedToO=true;
            }
        }
        else atCorner=true;
        // check right 
        if(startJ+1 <cols){
            if(board[startI][startJ+1]=='O'){
                isConnectedToO=true;
            checkIfConnected(board,startI,startJ+1);
            }
        }
        else atCorner=true;
        // check bottom 
        if(startI+1 <rows){
            if(board[startI+1][startJ]=='O'){
            checkIfConnected(board,startI+1,startJ);
                isConnectedToO=true;
            }
        }
        else atCorner=true;
        // check left
        if(startJ-1>=0){
            if(board[startI][startJ-1]=='O'){
            checkIfConnected(board,startI,startJ-1);
                isConnectedToO=true;
            }
        }
        else atCorner=true;

        if(atCorner==true){
            // do nothing
        }else{
            board[startI][startJ]='X';
        }
    }

    void solve(vector<vector<char>>& board) {
        int rows=board.size();
        if(rows==0) return;
        int cols= board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<rows;j++){
                if(board[i][j]=='O'){
                    checkIfConnected(board,i,j);
                }
            }
        }
    }
};