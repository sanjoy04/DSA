#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        vector<int>res;
        int fo=-1, lo=-1, first=0, last=n-1;
        while(first<=last){
            int mid = first+(last-first)/2;
            if(arr[mid]==x){
                fo = mid;
                last = mid-1;
            }
            else if(arr[mid]>x){
                last = mid-1;
            }
            else{
                first = mid+1;
            }
        }
        
        first=0, last=n-1;
        while(first<=last){
            int mid = first+(last-first)/2;
            if(arr[mid]==x){
                lo = mid;
                first = mid+1;
            }
            else if(arr[mid]>x){
                last = mid-1;
            }
            else{
                first = mid+1;
            }
        }
        
        if(fo==-1 && lo==-1){
            res.push_back(-1);
        }
        else{
            res.push_back(fo);
            res.push_back(lo);
        }
        return res;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}