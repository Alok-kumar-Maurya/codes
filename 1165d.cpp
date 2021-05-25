#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
vi compare;
void find_divisor(int a)
{
           for(int i=2;i*i<=a;i++)
            {
                if(a%i==0) 
                {
                    compare.push_back(i);
                    if(i!=a/i)
                    compare.push_back(a/i);

                }
            }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans=0;
        cin>>n;
        vi a(n);
        compare.clear();
        for(int j=0;j<n;j++)
        {
           cin>>a[j];
        }
        sort(a.begin(),a.end());
        
            
        ans=a[0]*a[n-1];
        find_divisor(ans);
        
        if(a.size()!=compare.size())
        {
            cout<<"-1"<<endl;
            continue;
        }
        sort(compare.begin(),compare.end());
        for(int i=0;i<n;i++)
        {
            if(a[i]!=compare[i])
            ans=-1;
        }
        cout<<ans<<endl;
    }
 return 0;
 // THINGS TO KEEP IN MIND
//   * int overflow, time and memory limits
//   * Special case (n = 1?)
//   * Do something instead of nothing and stay organized
//   * Don't get stuck in one focus
//   * int l=s.length()-x (s.length()<x) grabage value
// TIME AND MEMORY LIMITS
//   * 1 second is approximately 10^8 operations (c++)
//   * 10^6 Elements of 32 Bit (4 bytes) is equal to 4 MB
//   * 62x10^6 Elements of 32 Bit (4 bytes) is equal to 250 MB
//   * 10^6 Elements of 64 Bits (8 bytes) is equal to 8 MB
//   * 31x10^6 Elements of 64 Bit (8 bytes) is equal to 250 MB
}