class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        if(m==n){
            return (1ll*(m-1)*(n-1));
        }

        vector<int> h(hFences.begin(),hFences.end());
        vector<int> v(vFences.begin(),vFences.end());

        h.push_back(1);h.push_back(m);
        v.push_back(1);v.push_back(n);

        sort(h.begin(),h.end());
        sort(v.begin(),v.end());

        unordered_set<int> set;
        for(int i=0;i<hFences.size()+2;i++){
            for(int j=i+1;j<hFences.size()+2;j++){
                set.insert(abs(h[i]-h[j]));
            }
        }

        int maxi = INT_MIN;
        for(int i=0;i<vFences.size()+2;i++){
            for(int j=i+1;j<vFences.size()+2;j++){
                if(set.count(abs(v[i]-v[j]))){
                    maxi = max(maxi,abs(v[i]-v[j]));
                }
            }
        }

        return (maxi==INT_MIN)? -1: (1ll*(maxi)*(maxi));
    }
};