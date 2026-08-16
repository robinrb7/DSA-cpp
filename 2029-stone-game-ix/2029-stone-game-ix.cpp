class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> a(3, 0);
        for (auto &x : stones)
            a[x % 3]++;
        bool flip = (a[0] % 2 > 0);
        //         less than 3 remainder-1 stones → Alice loses
// otherwise result depends on the 0 stones parity
        if (!a[1]) return (a[2] < 3 ? false : flip);

           
        if (!a[2])
            return (a[1] < 3 ? false : flip);
        if (abs(a[1] - a[2]) > 2)
            return true;
        return !flip;
    }
};