class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());

        int count=0,i=0,j=people.size()-1;
        while(i<j){
            if(people[i]+people[j] >limit){
                j--;
            }else{
                people[i]=-1;
                people[j]=-1;
                j--;
                i++;
                count++;
            }
        }
        for(int i:people)
            if(i!=-1)
                count++;
        return count;
    }
};