//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    class TrieNode{
	public:
		char data;
		TrieNode* children[26];
		bool isTerminal;
		
		TrieNode(char ch){
			data = ch;
			
			for(int i =0;i<26;i++){
				children[i]=NULL;
			}
			
			isTerminal = false;
		}
};
    class Trie{
        public:
        TrieNode* root;
        
        Trie(){
            root = new TrieNode('\0');
        }
        
        void insertUtil(TrieNode* root, string word){
            if(word.length()==0){
                root->isTerminal = true;
                return;
            }
            
            int index = word[0]-'a';
            TrieNode* child;
            
            if(root->children[index]!=NULL){
                child  = root->children[index];
            }
            else{
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }
            
            insertUtil(child,word.substr(1));
        }
        
        void insertWord(string word){
            insertUtil(root,word);
        }
        
        void printSuggestions(TrieNode* curr, vector<string>&temp, string prefix){
            if(curr->isTerminal){
                temp.push_back(prefix);
            }
            
            for(char ch='a';ch<='z';ch++){
                TrieNode* next = curr->children[ch-'a'];
                
                if(next!=NULL){
                    prefix.push_back(ch);
                    printSuggestions(next,temp,prefix);
                    prefix.pop_back();
                }
            }
        }
        
        vector<vector<string>> getSuggestions(string str){
            
            TrieNode* prev = root;
            string prefix ="";
            vector<vector<string> > output;
            
            for(int i =0;i<str.length();i++){
                char lastChar = str[i];
                prefix.push_back(lastChar);
                
                TrieNode* curr = prev->children[lastChar-'a'];
                vector<string> temp;
                
                if(curr==NULL) {
                    temp.push_back("0");
                    output.push_back(temp);
                    break;
                }
                
                printSuggestions(curr,temp,prefix);
                    
                if(temp.empty()) temp.push_back("0");
                output.push_back(temp);
                prev = curr;                
            }
            
            while(output.size() < str.length()){
                output.push_back({"0"});
            }
           return output; 
        }
        
        
    };
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie *t = new Trie();
        
        for(int i =0;i<n;i++){
            string str = contact[i];
            t->insertWord(str);
        }
        
        return t->getSuggestions(s);
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends