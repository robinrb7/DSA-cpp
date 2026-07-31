class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        if(n<=8) return n;

        vector<int> charFreq(26,0);
        for(int i=0;i<n;i++) charFreq[word[i]-'a']++;

        priority_queue<int> maxHeap;
        for(int i=0;i<26;i++){
            if(charFreq[i]==0) continue;

            maxHeap.push(charFreq[i]);
        }

        int minPushes=0;
        int round=0;
        while(!maxHeap.empty()){
            round++;
            for(int i=0;i<8;i++){
                int val = maxHeap.top();
                maxHeap.pop();

                minPushes += (val*round);
                if(maxHeap.empty()) break;
            }
        }

        return minPushes;
    }
};


// time coomplexity -> n + (26 * log(26)) + 26