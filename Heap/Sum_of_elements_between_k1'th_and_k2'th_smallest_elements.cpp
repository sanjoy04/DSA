#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long kThSmallest(long long a[],long long n, long long k){
        priority_queue<long long>maxh;
        for(long long i=0; i<n; i++){
            maxh.push(a[i]);
            if(maxh.size()>k) maxh.pop();
        }
        return maxh.top();
    }
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        long long ans = 0;
        long long k1 = kThSmallest(A,N,K1);
        long long k2 = kThSmallest(A,N,K2);
        for(long long i = 0; i < N; i++){
            if(A[i]>k1 && A[i]<k2) ans += A[i];
        }
        return ans;
    }
};

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}