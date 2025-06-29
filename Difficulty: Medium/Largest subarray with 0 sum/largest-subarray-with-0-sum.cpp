class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        
        int maxi = 0;
        unordered_map<int,int> hash;
        int sum = 0;
        
        for(int i =0;i<n;i++){
            sum += arr[i]; 
            
            if(sum == 0) maxi  =  max(maxi,i+1);
            
            if(hash.find(sum) != hash.end()){
                int len = i - hash[sum] ;
                maxi = max(maxi,len);
            }
            
            
            if(hash.find(sum)==hash.end()){
                hash[sum]=i;
            }
        }
         return maxi;
       
    }
};