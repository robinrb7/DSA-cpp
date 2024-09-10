class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int element1 =-1,element2 =-1;
        int count=0;
        int n = nums1.size(),m= nums2.size();
        int N = n+m;
        int indx2 = N/2,indx1 = indx2-1;
        int i=0,j=0;

        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                if(count==indx1) element1= nums1[i];
                if(count==indx2) element2 = nums1[i];
                count++;
                i++;
            }
            else{
                if(count==indx1) element1= nums2[j];
                if(count==indx2) element2 = nums2[j];
                count++;
                j++;
            }
        }
        while(i<n){
             if(count==indx1) element1= nums1[i];
                if(count==indx2) element2 = nums1[i];
                count++;
                i++;
        }
        while(j<m){
            if(count==indx1) element1= nums2[j];
                if(count==indx2) element2 = nums2[j];
                count++;
                j++;
        }

        if(N%2==0){
            return (double)(element1+element2) /2.0;
        }
        else{
            return element2;
        }
    }
};