class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length(), m=t.length();
        if(n!=m) return 0;

        unordered_map<char,char> umap1;
        unordered_map<char,char> umap2;
        int i=0;
        for(int i =0;i<n;i++){

            char c1 = s[i], c2 = t[i];

            if(umap1.find(c1)!= umap1.end()){
                if(umap1[c1] != c2) return false;
            }
            else{
                if(umap2.find(c2)!= umap2.end()) return false;
            }

            umap1[c1]  = c2;
            umap2[c2] = c1;
            
        }

        return 1;
    }
};