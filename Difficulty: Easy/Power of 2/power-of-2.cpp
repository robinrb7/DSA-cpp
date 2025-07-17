class Solution {
  public:
    bool isPowerofTwo(int n) {
        return !(n & n-1);
    }
};