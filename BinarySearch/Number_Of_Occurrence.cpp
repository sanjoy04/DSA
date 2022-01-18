#include<bits/stdc++.h>

using namespace std;

class Solution{
public:	
	int count(int arr[], int n, int x) {
	    int fo=-1,lo=-1;
	    int start = 0, end=n-1;
	    while(start<=end){
	        int mid = start+(end-start)/2;
	        if(arr[mid]==x){
	            fo=mid;
	            end = mid-1;
	        }
	        else if(arr[mid]>x){
	            end = mid-1;
	        }
	        else start = mid+1;
	    }
	    
	    start = 0, end = n-1;
	    
	    while(start<=end){
	        int mid = start+(end-start)/2;
	        if(arr[mid]==x){
	            lo=mid;
	            start = mid+1;
	        }
	        else if(arr[mid]>x){
	            end = mid-1;
	        }
	        else start = mid+1;
	    }
	    if(fo>=0 && lo>=0)
	        return (lo-fo+1);
	    else return 0;
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}