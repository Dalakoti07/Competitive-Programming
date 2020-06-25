class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // greedy in the sense that
        // we sort the array on the basis of k, bcoz there will be in front and then rearrange the peopele

        sort(people.begin(),end(people),[](vector<int>& a, vector<int>& b){
            return a[1]<b[1] || (a[1]==b[1] && a[0] < b[0]);
        });
    
        for(int i=0;i<people.size();i++){
            auto p= people[i];
            if(p[1]==0) continue;
            else{
                int peopleGreatAhead = p[1];
                int currentIdx = i-1,count=0;
                for(;currentIdx>=0;currentIdx--){
                    if(people[currentIdx][0]>=people[i][0])
                        count++;
                }
                if(count-peopleGreatAhead !=0){
                    people.insert(begin(people) + (i - (count-peopleGreatAhead) ),p);
                    people.erase(begin(people)+i+1);
                }
            }
        }
        return people;
    }
};