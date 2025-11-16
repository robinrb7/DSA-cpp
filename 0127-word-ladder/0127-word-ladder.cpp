class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord) == st.end()) return 0;

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            auto[str, steps] = q.front();
            q.pop();

            if(str == endWord) return steps;

            for(int i=0;i<str.length();i++){
                char original = str[i];
                for(char ch ='a';ch<='z'; ch++){
                    if(ch==original) continue;
                    str[i] = ch;

                    if(st.find(str) != st.end()){
                        st.erase(str);
                        q.push({str,steps+1});

                    }
                }
                str[i]=original;
                
            }
        }

        return 0;
    }
};