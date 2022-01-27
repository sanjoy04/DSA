#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int mxLen = 0, sum = 0;
        unordered_map<int,int>mp;
        for(int i=0; i<N; i++){
            sum += A[i];
            
            if(sum == K){
                mxLen = i+1;
            }
            
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
            
            if(mp.find(sum-K) != mp.end()){
                mxLen = max(mxLen,i-mp[sum-K]);
            }
        }
        return mxLen;
    } 

};

int main() {
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}