//Hard-Problem
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    bool isValid(int arr[], int n, int m, int mx){
        int std = 1;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum>mx){
                std++;
                sum = arr[i];
            }
            if(std>m){
                return false;
            }
        }
        return true;
    }
    
    int findPages(int A[], int N, int M) 
    {
        if(M>N) return -1;
        int start = A[0];
        int end = A[0];
        for(int i=1; i<N; i++){
            start = max(start,A[i]);
            end += A[i];
        }
        int res = -1;
        
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isValid(A,N,M,mid)==true){
                res = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return res;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}