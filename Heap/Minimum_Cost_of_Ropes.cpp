#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> minh;
        long long ans=0;
        for(long long i=0; i<n; i++){
            minh.push(arr[i]);
        }
        
        while(minh.size()>=2){
            long long top1 = minh.top();
            minh.pop();
            long long top2 = minh.top();
            minh.pop();
            long long sum = top1+top2;
            ans += sum;
            minh.push(sum);
        }
        
        return ans;
    }
};

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}