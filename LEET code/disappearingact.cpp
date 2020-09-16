#include <vector>
using namespace std;

vector<int> minimalMoves(vector<vector<int>> initialCameraPositionList){
    vector<int> optimalAnswer;

    if(initialCameraPositionList.size()==0)
        return optimalAnswer;
    int cols=initialCameraPositionList[0].size();
    vector<int> recurringTime(initialCameraPositionList.size());
    for(int i=0;i<initialCameraPositionList.size();i++){
        for(int j=0;j<initialCameraPositionList[i].size();j++){
            if(initialCameraPositionList[i][j]==1)
                recurringTime[i]=cols-j;
        }
    }
    // not traverse the recurring array
    // greedy approach we will move if its okay
    for(int i=optimalAnswer.size()-1;i>=1;i--){
        // if suitable to move
        if(recurringTime[i-1]!=1){
            optimalAnswer.push_back(1);// we move
        }else{
            if(recurringTime[i]==1){
                //we lose
                return vector<int>();
            }
            optimalAnswer.push_back(0);// we dont move
        }
    }

    return optimalAnswer;
}
