const int MOD = (int)(1e9 +7);
class Solution {
private:
    void getPse(vector<int>& arr,vector<int>& pse, int n){
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]) st.pop();
            if(st.empty()){
                pse[i]=-1;
            } 
            else pse[i] = st.top();

            st.push(i);
        }
    }

    void getNse(vector<int>& arr,vector<int>& nse, int n){
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]) st.pop();
            if(st.empty()) nse[i]= n;
            else nse[i] = st.top();

            st.push(i);
        }
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>pse(n,-1);
        vector<int>nse(n,-1);

        getPse(arr,pse,n);
        getNse(arr,nse,n);

        long long total = 0;
        for(int i=0;i<n;i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            int totalSubarrays = (left*right) %MOD;
            int indvContri = (1ll*totalSubarrays * arr[i]) %MOD;
            total = (total + indvContri)%MOD;
        }

        return total;
    }
};