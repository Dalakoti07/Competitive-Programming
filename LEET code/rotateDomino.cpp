class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> digitsInUpper(7,0),digitsInLowe(7,0);
        for(auto i:A)
            digitsInUpper[i]++;
        for(auto i:B)
            digitsInLowe[i]++;
        
    }
};