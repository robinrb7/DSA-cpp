class Solution {
private:
    int seive(int n){
        int cntPrime=0;
        vector<int> prime(n+1,1);
        for(int i=2;i*i<=n;i++){
            if(prime[i]==1){
                for(int j=i*i;j<=n;j=j+i) prime[j]=0;
            }
        }

        for(int i=2;i<n;i++){
            if(prime[i]) cntPrime++;
        }

        return cntPrime;
    }
public:
    int countPrimes(int n) {
        return seive(n);
    }
};