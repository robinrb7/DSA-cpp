//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
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
		
		
		void insertWord(string word){
			TrieNode* curr = root;
			
			for(char ch : word){
			    int index = ch-'a';
			    
			    if(curr->children[index]==NULL){
			        curr->children[index] = new TrieNode(ch);
			    }
			    
			    curr = curr->children[index];
			}
			curr->isTerminal = true;
		}
		
		bool searchWord(string s,int start, int end){
		    
		    TrieNode* curr = root;
		    
		    for(int i = start;i<end;i++){
		        int index = s[i]-'a';
		        
		        if(curr->children[index] == NULL) return false;
		        else{
		            curr = curr->children[index];
		        }
		    }
		    
		    return curr->isTerminal;
		}
		
		
		bool solve(string s, int start){
		    if(start == s.size()) return true;
		    
		    for(int end = start+1;end<=s.size();end++){
		        if(searchWord(s,start,end)){
		            
		            if(solve(s,end)){
		                return true;
		            }
		        }
		    }
		    return false;
		}
   };
    
    int wordBreak(int n, string s, vector<string> &dictionary) {
        Trie *t = new Trie();
        
        for(auto i : dictionary){
            t->insertWord(i);
        }
        
        return t->solve(s,0);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends