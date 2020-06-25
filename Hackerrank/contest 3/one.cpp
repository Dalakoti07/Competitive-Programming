// print tree in level order
// using tries would do the trick

#include "bits/stdc++.h" 
using namespace std; 
  
// Trie Node 
struct TrieNode { 
  
    // Using map to store the pointers 
    // of children nodes for dynamic 
    // implementation, for making the 
    // program space efiicient 
    map<char, TrieNode*> children; 
  
    // If isEndOfWord is true, then 
    // node represents end of word 
    bool isEndOfWord; 
  
    // num represents number of times 
    // a character has appeared during 
    // insertion of the words in the 
    // trie 
    map<char, int> num; 
}; 
  
// Declare root node 
struct TrieNode* root; 
  
// Function to create New Trie Node 
struct TrieNode* getNewTrieNode() 
{ 
    struct TrieNode* pNode = new TrieNode; 
    pNode->isEndOfWord = false; 
    return pNode; 
} 
  
// Function to insert a string in trie 
void insertWord(string word) 
{ 
    // To hold the value of root 
    struct TrieNode* current = root; 
  
    // To hold letters of the word 
    char s; 
  
    // Traverse through strings in list 
    for (int i = 0; i < word.length(); i++) { 
        s = word[i]; 
  
        // If s is not present in the 
        // character field of current node 
        if (current->children.find(s) 
            == current->children.end()) { 
  
            // Get new node 
            struct TrieNode* p = getNewTrieNode(); 
  
            // Insert s in character 
            // field of current node 
            // with reference to node p 
            (current->children)[s] = p; 
  
            // Insert s in num field 
            // of current node with 
            // value 1 
            (current->num)[s] = 1; 
        } 
        else { 
  
            // Increment the count 
            // corressponding to the 
            // character s 
            current->num[s] = (current->num)[s] + 1; 
        } 
  
        // Go to next node 
        current = (current->children)[s]; 
    } 
    current->isEndOfWord = true; 
} 
  
// Function to count the number of 
// words in trie with given prefix 
int countWords( string prefix) { 
  
    struct TrieNode* current = root; 
    char s; 
  
    // Initialize the wordCount = 0 
    int wordCount = 0; 
  
    for (int i = 0; prefix[i]; i++) { 
        s = prefix[i]; 
  
        // If the complete prefix is 
        // not present in the trie 
        if (current->children.find(s) 
            == current->children.end()) { 
  
            // Make wordCount 0 and 
            // break out of loop 
            wordCount = 0; 
            break; 
        } 
  
        // Update the wordCount 
        wordCount = (current->num)[s]; 
  
        // Go to next node 
        current = (current->children)[s]; 
    } 
  
    return wordCount; 
} 

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    string type,x;
    cin>>n;
    root = getNewTrieNode(); 
    for(int i=0;i<n;i++){
        cin>>type>>x;
        if(type=="add"){
            insertWord(x);
        }else{
            cout<<countWords(x)<<endl;
        }
    }
    return 0;
}