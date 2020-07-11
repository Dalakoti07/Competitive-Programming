class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());

        int count =0,peopleINCurrentBoat=0;
        for(int i=0;i<people.size();i++){
            peopleINCurrentBoat+=people[i];
            if(peopleINCurrentBoat==limit){
                count++;
                peopleINCurrentBoat=0;
            }else if(peopleINCurrentBoat>limit){
                count++;
                peopleINCurrentBoat=people[i];
            }
        }
        return count;
    }
};