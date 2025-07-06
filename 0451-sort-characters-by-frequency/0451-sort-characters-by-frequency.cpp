class Solution {

public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char,int> hash;

        for(int i =0;i<n;i++){
            hash[s[i]]++;
        }

        vector<vector<char>> bucket(n+1);
        for(auto it :hash){
            char ch = it.first;
            int freq = it.second;
            bucket[freq].push_back(ch);
        }

        string result = "";
        for(int i=n;i>=1;i--){
            for(auto ch: bucket[i]){
                result.append(i,ch);
            }
        }

        return result;
    }
};