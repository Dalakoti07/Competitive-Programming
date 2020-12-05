void go(string s,int l,int r){
    if(l==r){
        allPerms.push_back(s);
        return;
    }
    for(int i=l;i<=r;i++){
        // Swapping done 
        swap(s[l],s[i]);
        // Recursion called 
        go(s, l+1, r); 
        //backtrack 
        swap(s[l], s[i]); 
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        // sort(s.begin(),s.end());
        // cout<<"string after soting we have : "<<s<<endl;
        go(s,0,s.length()-1);
        sort(allPerms.begin(),allPerms.end());
        for(string st:allPerms)
            cout<<st<<" ";
        cout<<endl;
        allPerms.clear();
    }
    
	return 0;
}