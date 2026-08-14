class NumArray {
private:
    int n;
    vector<int> segmentArr;


    void buildSegmentTree(vector<int>& nums,vector<int>& segmentArr, int index, int low, int high){
        if(low==high){
            segmentArr[index] = nums[low];
            return;
        } 

        int mid = low + (high-low)/2;
        int left = 2*index+1 , right = 2*index+2;

        buildSegmentTree(nums,segmentArr,left,low,mid);
        buildSegmentTree(nums,segmentArr,right,mid+1,high);

        segmentArr[index] = segmentArr[left] + segmentArr[right];
    }

    void pointUpdate(vector<int> &segmentArr, int arrIndex, int val, int treeIndex, int low, int high){
        if(low==high){
            segmentArr[treeIndex] = val;
            return;
        } 

        int mid = low + (high-low)/2;

        if(arrIndex>=low && arrIndex<=mid) pointUpdate(segmentArr,arrIndex,val,2*treeIndex+1,low,mid);
        else pointUpdate(segmentArr,arrIndex,val,2*treeIndex+2,mid+1,high);

        segmentArr[treeIndex] = segmentArr[2*treeIndex+1] + segmentArr[2*treeIndex+2];
    }

    int rangeSum(vector<int> &segmentArr, int left, int right, int index, int low, int high){

        if(low>=left && high<=right) return segmentArr[index];
        if(high<left || low>right) return 0;
        
        int mid = low + (high-low)/2;
        int leftChild =  rangeSum(segmentArr,left,right,2*index+1,low,mid);
        int rightChild =  rangeSum(segmentArr,left,right,2*index+2,mid+1,high);

        return (leftChild + rightChild);
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentArr.resize(4*n);

        buildSegmentTree(nums,segmentArr,0,0,n-1);
    }
    
    void update(int index, int val) {
        pointUpdate(segmentArr,index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return rangeSum(segmentArr,left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */