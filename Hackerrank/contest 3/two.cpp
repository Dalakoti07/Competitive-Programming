#include<bits/stdc++.h>
using namespace std;


int findCount(vector<string>& names,string target){
    int count =0;
    for(int i=0;i<names.size();i++){
        if(target.length()>names[i].length()) continue;
        int j=0;
        for(;j<target.length();j++){
            if(names[i][j]!=target[j])
                break;
        }
        if (j==target.length()) {
            count++;
        }
    }
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    string type,x;
    scanf("%d",&n);
    vector<string> names;
    vector<string> zeroResults;
    unordered_map<string,int> ans;
    bool arrayChanged=false;
    string lastQuery;
    for(int i=0;i<n;i++){
        scanf("%s",type);
        scanf("%s",x);
        //cin>>type>>x;
        if(type=="add"){
            arrayChanged=true;
            names.push_back(x);
        }else{
                if(arrayChanged==false){
                    if(ans.count(x)==0) cout<<findCount(names,x)<<"\n";
                    else cout<<ans[x]<<"\n";
                }else{
                    int o=findCount(names,x);
                    ans[x]=o;
                    cout<<o<<"\n";
                    arrayChanged=false;
                }
        }
    }
    return 0;
}