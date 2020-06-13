class Solution {
public:
    bool validRow(vector<vector<char>>& board,int r){
        vector<int> numsOccurenceCount(10,0);
        // cout<<"size of vec: "<<numsOccurenceCount.size()<<" and first elem"<<numsOccurenceCount[0]<<endl;
        for(int i=0;i<9;i++){
            if(board[r][i]=='.') continue;
            if(numsOccurenceCount[board[r][i]]==1){
                return false;
            } else{
                numsOccurenceCount[board[r][i]]+=1;
            }
        }
        return true;
    }

    bool validColumn(vector<vector<char>>& board,int c){
        vector<int> numsOccurenceCount(10,0);
        for(int i=0;i<9;i++){
            if(board[i][c]=='.') continue;
            if(numsOccurenceCount[board[i][c]]==1){
                return false;
            }else{
                numsOccurenceCount[board[i][c]]+=1;
            }
        }
        return true;
    }

    bool validateSubGrid(vector<vector<char>>& board, int a,int b,int c,int d){
        vector<int> numsOccurenceCount(10,0);
        for(;a<=c;a++){
            for(;b<=d;){
                if(board[a][b]=='.') continue;
                if(numsOccurenceCount[board[a][b]]==1){
                    return false;
                } else{
                    numsOccurenceCount[board[a][b]]+=1;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // we are given 9*9 sudoku
        // validate each row
        for(int i=0;i<9;i++){
            cout<<"validating row: "<<i<<" and res: "<<validRow(board,i)<<endl;
            if(validRow(board,i)==false) return false;
        }
        // validate each col
        for(int i=0;i<9;i++){
            cout<<"validating col: "<<i<<endl;
            if(validColumn(board,i)==false) return false;
        }
        // validate each 3*3 cell, [(0,0) to (2,2)], [(0,3) to (2,5)], [(0,6) to (2,8)] 
        for(int i=0;i<9;i=i+3){
            for(int j=0;j<9;j=j+3){
            cout<<"validating grid: "<<i<<":"<<j<<endl;
                if (! validateSubGrid(board, i, j,i+2 ,j+2))
                    return false;
            }
        }
        return true;
    }
};