//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
    private: 
    
    bool isPossible(int arr[],int k,long long mid,int n){
    int count=1;
    long long sum=0;
    for(int i =0;i<n;i++){
        if(sum+arr[i]<=mid){
            sum+=arr[i];
        }
        else{
            count++;
            if(count>k || arr[i]>mid){
                return false;
            }
            sum = arr[i];
        }
    }
    return true;
}
  public:
    long long minTime(int arr[], int n, int k)
    {
    long long sum =0;
    int maxElement =-1;
    for(int i =0;i<n;i++){
        sum +=arr[i];
        maxElement = max(maxElement,arr[i]);
    }
    long long s=maxElement,e=sum;
    long long ans =-1;

    while(s<=e){
        long long mid = s+(e-s)/2;
        if(isPossible(arr,k,mid,n)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends