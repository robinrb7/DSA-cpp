class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord) return 0;

        unordered_set<string> s;
        bool foundEndWord=0;
        for(auto it: wordList){
            if(it==endWord) foundEndWord=1;
            s.insert(it);
        }
        if(!foundEndWord) return 0;

        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto[word,depth] = q.front();
            q.pop();
            if(word==endWord) return depth;

            for(int i=0;i<word.length();i++){
                string temp = word;
                for(char ch='a';ch<='z';ch++){
                    if(ch==temp[i]) continue;
                    temp[i] = ch;
                    if(s.find(temp) != s.end()){
                        q.push({temp,depth+1});
                        s.erase(temp);
                    } 
                }
            }
        }

        return 0;
    }
};