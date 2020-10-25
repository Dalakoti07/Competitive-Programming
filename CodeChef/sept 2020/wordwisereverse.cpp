// CPP program to reverse a string
#include <bits/stdc++.h>
using namespace std;

// Function to reverse words*/
string reverseWords(string s)
{
    bool isFirstCapital=false;
    if(s[0]>='A' and s[0]<='Z')
        isFirstCapital=true;

	int start = 0;
	for (int end = 0; end < s.length(); end++) {

		if (s[end] == ' ') {
			reverse(s.begin() + start, s.begin() + end);
			start = end + 1;
		}
	}

	reverse(s.begin() + start, s.end());

	reverse(s.begin(), s.end());

    for(int i=0;i<s.length();i++){
        s[i]=tolower(s[i]);
    }
    if(isFirstCapital){
        s[0]=toupper(s[0]);
    }
    return s;
}

// Driver Code
int main()
{
	string s = "welcome to mettle";
	cout<<reverseWords(s);
	return 0;
}
