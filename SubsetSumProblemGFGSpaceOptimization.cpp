//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<bool> prev(sum+1,0),curr(sum+1,0);
        prev[0]=curr[0]=1;
        
        prev[arr[0]]=true;
        
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<sum+1;target++){
                bool exc=prev[target];
                bool inc=false;
                if(target>=arr[ind])
                inc=prev[target-arr[ind]];
                curr[target]=inc||exc;
            }
            prev=curr;
        }
        return prev[sum];
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
