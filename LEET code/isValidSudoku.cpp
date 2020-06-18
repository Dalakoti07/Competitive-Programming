class Solution {
public:
    bool validRow(vector<vector<char>>& board,int r){
        vector<int> numsOccurenceCount(10,0);
        for(int i=0;i<9;i++){
            if(board[r][i]=='.') continue;
            if(numsOccurenceCount[board[r][i]-'0']==1){
                return false;
            } else{
                numsOccurenceCount[board[r][i]-'0']+=1;
            }
        }
        return true;
    }

    bool validColumn(vector<vector<char>>& board,int c){
        vector<int> numsOccurenceCount(10,0);
        for(int i=0;i<9;i++){
            if(board[i][c]=='.') continue;
            if(numsOccurenceCount[board[i][c]-'0']==1){
                return false;
            }else{
                numsOccurenceCount[board[i][c]-'0']+=1;
            }
        }
        return true;
    }

    bool validateSubGrid(vector<vector<char>>& board, int a,int b,int c,int d){
        // cout<<"prinitng subgrid \n";
        vector<int> numsOccurenceCount(10,0);
        for(;a<=c;a++){
            for(int bCopy=b;bCopy<=d;bCopy++){
                // cout<<board[a][bCopy]<<" ";
                if(board[a][bCopy]=='.') continue;
                if(numsOccurenceCount[board[a][bCopy]-'0']==1){
                    return false;
                } else{
                    numsOccurenceCount[board[a][bCopy]-'0']+=1;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // we are given 9*9 sudoku
        // validate each row
        for(int i=0;i<9;i++){
            // cout<<"validating row: "<<i<<" and res: "<<validRow(board,i)<<endl;
            if(validRow(board,i)==false) return false;
        }
        // validate each col
        for(int i=0;i<9;i++){
            // cout<<"validating col: "<<i<<"res: "<<validColumn(board,i)<<endl;
            if(validColumn(board,i)==false) return false;
        }
        // validate each 3*3 cell, [(0,0) to (2,2)], [(0,3) to (2,5)], [(0,6) to (2,8)] 
        for(int i=0;i<9;i=i+3){
            for(int j=0;j<9;j=j+3){
            // cout<<"validating grid: "<<i<<":"<<j<<" to "<<i+2<<" : "<<j+2<<endl;
                if (! validateSubGrid(board, i, j,i+2 ,j+2))
                    return false;
            }
        }
        return true;
    }
};