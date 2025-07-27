class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        unordered_map<int,int> fruitType;
        int l =0, maxLen=0;

        for(int r = 0;r<n;r++){
            fruitType[fruits[r]]++;

            if(fruitType.size()>2){
                fruitType[fruits[l]]--;
                if(fruitType[fruits[l]]==0) fruitType.erase(fruits[l]);
                l++;
            }

            if(fruitType.size()<=2) maxLen = max(maxLen,r-l+1);
        }
        return maxLen;
    }
};