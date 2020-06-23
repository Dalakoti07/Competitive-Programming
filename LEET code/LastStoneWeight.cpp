class Solution {
public:
    /* A Far better implementation */
    int lastStoneWeight(vector<int>& s) {
      make_heap(s.begin(),s.end());
      for(int i:s){
          cout<<i<<" ";
      }
      cout<<endl;
    while(s.size()>1){
        int y=s.front();
        pop_heap(s.begin(),s.end());
        s.pop_back();
        int x=s.front();
        pop_heap(s.begin(),s.end());
        s.pop_back();
       
        if(x!=y){
            s.push_back(y-x);
            push_heap(s.begin(),s.end());
        }
    }
        return s.size()==0?0:s[0];
    }
};