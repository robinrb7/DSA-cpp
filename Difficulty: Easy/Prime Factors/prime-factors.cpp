class Solution {
    private:
    bool prime(int n){
        if(n==1) return 0;
        int cnt=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                cnt++;
                if(n/i != i) cnt++;
            }
            if(cnt>2) return 0;
        }
        if(cnt==2) return 1;
        return 0;
    }
  public:
    vector<int> primeFac(int n) {
        vector<int>temp;
        
        for(int i =1;i*i<=n;i++){
            if(n%i==0){
                if(prime(i)) temp.push_back(i);
                if(n/i !=i){
                    if(prime(n/i)) temp.push_back(n/i);
                }
            }
        }
        
        return temp;
        
    }
};