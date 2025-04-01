class Solution {
    private:
    void merge(vector<int>&nums,int s,int mid,int e){
        vector<int>temp;
        int index1 =s;
        int index2 = mid+1;

        while(index1<=mid && index2<=e){
            if(nums[index1]<nums[index2]){
                temp.push_back(nums[index1++]);
            }
            else{
                temp.push_back(nums[index2++]);
            }
        }
        while(index1<=mid){
            temp.push_back(nums[index1++]);
        }
        while(index2<=e){
            temp.push_back(nums[index2++]);
        }

        for(int i=s;i<=e;i++){
            nums[i] = temp[i-s];
        }

    }

    int countPairs(vector<int>& nums,int s,int mid,int e){
        int cnt = 0;

        int right =mid+1;
        for(int left = s;left<=mid;left++){
            while(right<=e && ((long long)nums[left] > (long long)2* nums[right])) right++;
            cnt += (right - (mid+1));
        }
        return cnt;

    }
    int mergeSort(vector<int>& nums,int s,int e){
        int cnt =0;
        if(s>=e) return cnt;
        int mid = s + (e-s)/2;
        cnt += mergeSort(nums,s,mid);
        cnt += mergeSort(nums,mid+1,e);
        cnt += countPairs(nums,s,mid,e);
        merge(nums,s,mid,e);

        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
        
    }
};