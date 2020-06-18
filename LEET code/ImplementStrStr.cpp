class Solution {
public:
	bool check(string& s, string& p, int idx)
	{
		int cur=0;
		while(cur<p.size())
		{
			if(p[cur]==s[idx+cur])
				cur++;
			else
			{
				return false;
			}
		}
		return true;
	}
	int strStr(string haystack, string needle) {
		if(haystack.size()<needle.size()) return -1;
		if(needle.size()==0) return 0;
		for(int i=0;i<=haystack.size()-needle.size()+1;i++)
		{
			if(check(haystack,needle,i))
				return i;
		}
		return -1;
	}
};