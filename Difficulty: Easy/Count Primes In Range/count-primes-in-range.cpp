// User function Template for C++

class Solution {
private:
    vector<int> seive(int n){
        vector<int> prime(n+1,1);
        prime[0]=prime[1]=0;
        for(int i=2;i*i<=n;i++){
            if(prime[i]==1){
                for(int j=i*i;j<=n;j=j+i) prime[j]=0;
            }
        }
        
        return prime;
    }
  public:
    int countPrimes(int L, int R) {
        vector<int> primeArray = seive(1e6);
        int cnt=0;
        for(int i=0;i<=1e6;i++){
            primeArray[i] += cnt;
            cnt = primeArray[i];
        }
        
        return primeArray[R] - primeArray[L-1];
    }
};