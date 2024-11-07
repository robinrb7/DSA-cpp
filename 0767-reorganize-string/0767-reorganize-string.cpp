class Solution {
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
    bool operator()(Node* a, Node* b){
    return a->freq < b->freq;
 }
};

    string reorganizeString(string s) {
        string str="";
        priority_queue<Node*,vector<Node*>,compare> maxHeap;

        int count[26]= {0};

        for(int i =0;i<s.length();i++){
            count[s[i]-'a']++;
        }

        for(char ch = 'a';ch <='z';ch++){
            if(count[ch-'a']){
                Node* temp = new Node({ch,count[ch-'a']});
                maxHeap.push(temp);
            }
        }

        Node* prev = new Node({'#',-1});
        while(!maxHeap.empty()){
            Node* temp = maxHeap.top();
            maxHeap.pop();

            str = str + temp->ch;

            if(prev->freq >0) maxHeap.push(prev); 

            temp->freq--;
            prev = temp;
        }
        
        if(str.length() != s.length()) str ="";
        return str;
    }
};