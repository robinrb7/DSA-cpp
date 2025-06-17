class Solution {
  public:
    int nthRoot(int n, int m) {
        
        int s = 1,e = m;
        int mid = -1;
        while(s<=e){
            mid = s + (e-s)/2;
            
            if(pow(mid,n)==m) return mid;
            else if(pow(mid,n)<m) s = mid+1;
            else e=mid-1;
        }
        
        return -1;
    }
};