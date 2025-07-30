class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n= hand.size();
        if(n%groupSize!=0) return 0;

        map<int,int> freqMap;
        for(int i=0;i<n;i++) freqMap[hand[i]]++;

        while(!freqMap.empty()){
            int first = freqMap.begin()->first;

            for(int i = 0;i<groupSize;i++){
                int current  = first+i;
                if(!freqMap.count(current) && current!= first) return false;
                freqMap[current]--;
                if(freqMap[current]==0) freqMap.erase(current);
            }
            
        }

        return true;
    }
};