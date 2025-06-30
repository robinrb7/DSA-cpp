class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();
        long long xr =-1,xm =-1;
        
        long long sn = (n * (n+1))/2;
        long long s2n = (n*(n+1)*(2*n +1))/6;
        
        long long s1=0,s2=0;
        for(int i =0;i<n;i++){
            s1 += arr[i];
            s2 +=(long long)arr[i]*(long long)arr[i];
        }
        
        xm = ((s2n-s2)/(sn-s1) + sn-s1)/2;
        xr = xm - (sn-s1);
        
        return {(int) xr,(int) xm};
    }
};