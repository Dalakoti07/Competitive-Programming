#include<bits/stdc++.h>
using namespace std;
int main()
{
	// this is perfect example where I related this problem with finding subsets, and it clicked, otherwise I was wondering find all the anagrams(which are permutations of the word) and then see those in the word
	int t;
	cin>>t;
	while(t--)
	{
		string text,word;
		cin>>text>>word;
		// make two hashmap for storing all the alphabets of the word, one for permanent copy and another for changes 
		unordered_map<char,int> map1,map2;
		int lenText=text.length();
		int lenWord=word.length();
		int count=0;
		// filling the maps
		for(int i=0;i<lenWord;i++)
		{	
			if(map1.count(word[i]))
				map1[word[i]]++;
			else
				 map1[word[i]]=1;
		}
		// coping the map1 to map2 in each loop
		for(int i=0;i<lenText-lenWord+1;i++)
		{
			map2=map1;
			for(int j=i;j<i+lenWord;j++)
			{
				if(map2.count(text[j]))
					map2[text[j]]--;
			}
			// if hashmaps' all entry value is zero than its anagram
			auto x =map2.begin();
			for(;x!=map2.end();x++)
			{
				if(x->second!=0)
					break;	
			}
			if(x==map2.end())
				count++;
		}
	cout<<count<<endl;
	}
	return 0;
}