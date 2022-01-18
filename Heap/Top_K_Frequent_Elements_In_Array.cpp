#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>m;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>minh;
        vector<int>ans;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        
        for(auto i=m.begin(); i!=m.end(); i++){
            minh.push({i->second,i->first});
            if(minh.size()>k) minh.pop();
        }
        while(minh.size()>0){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}