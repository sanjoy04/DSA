#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int>res; //Vector for storing result
        list<int>ls;    //list for storing maximum number
        int i=0,j=0;
        while(j<n){
            while(ls.size()>0 && ls.back()<arr[j]){ //if arr[j] is greater then the element present in list then pop
                ls.pop_back();
            }
            ls.push_back(arr[j]);
            if(j-i+1 == k){
                res.push_back(ls.front());
                if(ls.front() == arr[i]){
                    ls.pop_front();
                }
                i++;
            }
            j++;
        }
        return res;
    }
};


int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}