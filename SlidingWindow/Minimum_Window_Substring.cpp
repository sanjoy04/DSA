#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    string smallestWindow (string s, string p)
    {
        unordered_map<char,int>mp;
        int i=0, j=0, start=0, count=0, ans = INT_MAX;
        for(int i=0; i<p.length(); i++){
            if(mp[p[i]]==0)
                count++;
            mp[p[i]]++;
        }
        
        while(j<s.length()){
            mp[s[j]]--;
            if(mp[s[j]]==0)
                count--;
            if(count==0){
                while(count==0){
                    if(ans>j-i+1){
                        ans = min(ans,j-i+1);
                        start=i;
                    }
                    
                    mp[s[i]]++;
                    if(mp[s[i]]>0)
                        count++;
                    i++;
                }
            }
            j++;
        }
        if(ans != INT_MAX){
            return s.substr(start,ans);
        }
        else
            return "-1";
    }
};

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}