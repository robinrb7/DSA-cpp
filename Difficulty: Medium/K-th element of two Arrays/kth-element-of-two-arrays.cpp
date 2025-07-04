class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size(), m= b.size();
        if(m<n) return kthElement(b,a,k);
        
        int low = max(0,k-m), high=min(k,n);
        while(low<=high){
            int mid1 = low +(high-low)/2;
            int mid2 = k - mid1;
            
            int l1 = INT_MIN, l2=INT_MIN;
            int r1 = INT_MAX, r2=INT_MAX;
            
            if(mid1 < n) r1 = a[mid1];
            if(mid2 < m) r2 = b[mid2];
            if(mid1 >0) l1 = a[mid1-1];
            if(mid2 >0) l2 = b[mid2-1];
            
            if(l1<=r2 && l2<=r1) return max(l1,l2);
            else if(l1>r2) high = mid1-1;
            else low = mid1+1;
        }
        
        return -1;
        
    }
};