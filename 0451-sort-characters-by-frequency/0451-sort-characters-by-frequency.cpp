class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char,int> hash;
        priority_queue<pair<int,char>>pq;

        for(int i =0;i<n;i++){
            hash[s[i]]++;
        }

        for(auto it:hash){
            pq.push({it.second,it.first});
        }

        string result = "";
        while(!pq.empty()){
            pair<int,char> top = pq.top();
            pq.pop();
            result.append(top.first,top.second);
        }

        return result;
    }
};