class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        // we will try to make a jumbo burger and see if from remaining burger we can make the small burger
        // we can also use BS 
        int jumboBurger=-1,smallBurgers=-1, tRem=0,cRem=0;
        for(int i=tomatoSlices/4;i>=0;i--){
            bool possible=false;
            jumboBurger=i;
            tRem=tomatoSlices-(jumboBurger)*4;
            cRem=cheeseSlices-(jumboBurger)*2;
            if(tRem>0 and tRem%2==0){
                if(tRem/2==cRem){
                    smallBurgers=tRem/2;
                    possible=true;
                }
            }
            if(!possible)
                jumboBurger=-1;
        }
        if(tomatoSlices)
            
    }
};