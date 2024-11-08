//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    class Node{
      public:
      char ch;
      int freq;
      
      Node(char ch, int freq){
          this->ch = ch;
          this->freq = freq;
      }
    };
    class compare{
      public:
      bool operator()(Node* a,Node* b){
          return a->freq < b->freq;
      }
    };
    string rearrangeString(string str)
    {
        int count[26]={0};
        for(int i =0;i<str.length();i++){
            count[str[i]-'a']++;
        }
        
        priority_queue<Node*,vector<Node*>,compare> maxHeap;
        
        for(int i =0;i<26;i++){
            if(count[i] > 0){
                char ch = i +'a';
                Node* temp = new Node({ch,count[i]});
                maxHeap.push(temp);
            }
        }
        
        Node* prev = new Node({'#',-1});
        string s ="";
        while(!maxHeap.empty()){
          Node* temp = maxHeap.top();
          maxHeap.pop();
          
          s += temp->ch;
          
          if(prev->freq > 0){
              maxHeap.push(prev);
          }
          temp->freq--;
          prev = temp;
        }
        
        if(s.length()!= str.length()){
            s="-1";
        }
         return s;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends