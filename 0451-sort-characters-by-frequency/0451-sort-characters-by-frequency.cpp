class Solution {
    private:
    bool static cmp(pair<char,int>&a, pair<char,int>&b){
        return a.second > b.second;
    }
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char,int> hash;
        priority_queue<pair<int,char>>pq;

        for(int i =0;i<n;i++){
            hash[s[i]]++;
        }

        vector<pair<char,int>> charFreq(hash.begin(),hash.end());
        sort(charFreq.begin(),charFreq.end(),cmp);

        string result = "";
        for(auto it:charFreq){
            result.append(it.second,it.first);
        }

        return result;
    }
};