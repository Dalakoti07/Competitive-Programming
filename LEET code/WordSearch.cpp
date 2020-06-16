class Solution {
public:
    bool searchWord(vector<vector<char>>& board,string word,int startI,int startJ){
        // cout<<" char at i: "<<startI<<" j: "<<startJ<<"word: "<<word<<endl;
        int rows=board.size();
        int cols =board[0].size();

        if(word.length()==1) return true;
        char currentChar=board[startI][startJ];
        board[startI][startJ]='.';
        bool possible=false;
        // see top
        if(startI-1 >=0 and board[startI-1][startJ]==word[1]){
            possible=possible || searchWord(board,word.substr(1),startI-1,startJ);
            if (possible) return possible;
        }
        // see left
        if(startJ-1 >=0 and board[startI][startJ-1]==word[1]){
            possible=possible || searchWord(board,word.substr(1),startI,startJ-1);
            if (possible) return possible;
        }
        // see bottom
        if(startI+1 <rows and board[startI+1][startJ]==word[1]){
            possible=possible || searchWord(board,word.substr(1),startI+1,startJ);
            if (possible) return possible;
        }
        // see right
        if(startJ+1 <cols and board[startI][startJ+1]==word[1]){
            possible=possible || searchWord(board,word.substr(1),startI,startJ+1);
            if (possible) return possible;
        }
        board[startI][startJ]=currentChar;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int idx=0,rows=board.size();
        if(rows==0) return false;
        int cols =board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]==word[0]){
                    if(searchWord(board,word,i,j))
                        return true;
                }
            }
        }
        return false;
    }
};