#include <bits/stdc++.h>

using namespace std;
 
class Solution{
public:
	int search(string pat, string txt) {
	    vector<int> patCount(26,0);
	    vector<int> txtCount(26,0);
	    int n = txt.length();
	    int k = pat.length();
	    int count = 0;
	    int i=0, j=0;
	    for(int m=0; m<k; m++){
	        patCount[pat[m]-'a']++;
	    }
	    
	    while(j<n){
	        txtCount[txt[j]-'a']++;
	        if(j-i+1 == k){
	            if(patCount == txtCount){
	                count++;
	            }
	            txtCount[txt[i]-'a']--;
	            i++;
	        }
	        j++;
	    }
	    return count;
	}

};


int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
} 