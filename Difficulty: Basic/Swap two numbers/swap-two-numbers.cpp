class Solution {
  public:
    pair<int, int> get(int a, int b) {
        // code here
        a = a^b;
        b = a ^ b;     // a^(b ^b) -> a^0 ->a
        a = a ^b;      // a^b ^ a -> a^a ^b -> 0^b->b
        
        return {a,b};
        
    }
};