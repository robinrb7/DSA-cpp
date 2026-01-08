class Solution {
private:
    int solve(vector<int>& nums1, vector<int>& nums2, int index1,int index2){
        if(index1<0 || index2<0) return INT_MIN;

        int include = (nums1[index1]*nums2[index2]);

        if(index1>0 && index2>0) include += max(0,solve(nums1,nums2,index1-1,index2-1));
        int exclude1 = 0 + solve(nums1,nums2,index1-1,index2);
        int exclude2 = 0 + solve(nums1,nums2,index1,index2-1);

        return max(include,max(exclude1,exclude2));
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m=nums2.size();
        
        return solve(nums1,nums2,n-1,m-1);
    }
};