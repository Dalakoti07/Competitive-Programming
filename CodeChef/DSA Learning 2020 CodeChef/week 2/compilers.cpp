#include <bits/stdc++.h>
using namespace std;
// >>>>><> is 0 as we are hunting for prefix of valid expression, fix this
int main() {
	int t;
	cin>>t;
	while(t--){
        string expression;
        cin>>expression;
        int n =expression.size(),count=0,nestedCount=0;
        stack<char> stacky;
        for(int i=0;i<n;i++){
            char c= expression[i];
            if(c=='>'){
                if(! stacky.empty()){
                    if(stacky.top()=='<'){
                        nestedCount+=2;
                        stacky.pop();
                        if(stacky.empty()){
                            count+=nestedCount;
                            nestedCount=0;
                        }else{
                            // do nothing
                        }
                    }
                    else
                        break;// wrong pattern
                }else{
                    break;// means we get invalid sequ no need to go forward
                }
            }else
                stacky.push(c);
        }
        cout<<count<<"\n";
	}
	return 0;
}