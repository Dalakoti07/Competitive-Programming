#include<bits/stdc++.h>
using namespace std;

string trim(const string& str){
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first){
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

class Solution {
public:
    int myAtoi(string str) {
        stringstream ss(str);
        str = "";
        ss >> str;
        int i = 0;
        int sign = 1;
        if(str[i] == '-' || str[i] == '+') {
            sign = (str[i++] == '-')? -1 : 1;
        }
        long long int res = 0;
        while('0'<= str[i] && str[i] <= '9') {
            res = res*10 + (str[i++]-'0');
            if(res*sign >= INT_MAX) return INT_MAX;
            if(res*sign <= INT_MIN) return INT_MIN;
        }
        return res * sign;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string n;
        getline(cin, n); 
        // cin>>n;
        // cin.ignore();
        while(n.length()==0){ // Explained at end of code
            getline(cin,n);
        }
        cout<<"string: "<<n<<endl;
        int ans=0;
        bool positive=true;
        n=trim(n);
        if(n[0]>='a' and n[0]<='z'){
            ans=0;
            cout<<ans<<endl;
        }
        else{
            if(n[0]=='-'){
                positive=false;
            }
            for(int i=0;i<n.length();i++){
                if(n[i]=='-')
                    continue;
                if(positive)
                    ans=ans*10 + (n[i]-'0');
                else
                    ans=ans*10 - (n[i]-'0');
            }
            if(positive and ans<0){
                ans=INT_MAX;
            }
            if(!positive and ans>0){
                ans=INT_MIN;
            }
            cout<<ans<<endl;
        }
    }
    
}