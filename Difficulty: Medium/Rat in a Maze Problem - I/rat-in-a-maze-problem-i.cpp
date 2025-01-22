//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    private:
    bool isSafe(int newx,int newy,vector <vector<bool> >&visited,vector<vector<int>> &mat,int n){
        if((newx>=0 && newx<n) && (newy>=0 && newy<n) && visited[newx][newy]!=1 
            && mat[newx][newy]!=0){
                return true;
            }
        else return false;    
    }
    
    void solve(int x,int y,vector<vector<int>> &mat,vector<string>&ans,
               string path,vector<vector<bool> >&visited,int n)
    {
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        
        //DLRU
        visited[x][y]=1;
        //Down
        if(isSafe(x+1,y,visited,mat,n)){
            solve(x+1,y,mat,ans,path+"D",visited,n);
        }
        
        //Left
        if(isSafe(x,y-1,visited,mat,n)){
            solve(x,y-1,mat,ans,path+"L",visited,n);
        }
        
        //Right
        if(isSafe(x,y+1,visited,mat,n)){
            solve(x,y+1,mat,ans,path+"R",visited,n);
        }
        
        //Up
        if(isSafe(x-1,y,visited,mat,n)){
            solve(x-1,y,mat,ans,path+"U",visited,n);
        }
        
        visited[x][y]=0;
    }
    
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans;
        if(mat[0][0]!=1) return ans;
        
        string path="";
        int rows  = mat.size();
        int cols = mat[0].size();
        
        vector<vector<bool> > visited(rows,vector<bool>(cols,0));
        
        solve(0,0,mat,ans,path,visited,rows);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends