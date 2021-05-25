#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
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
        int n,w,ok=-1,a;
        cin>>n>>w;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {   
            cin>>a;
            if(a>w)
            continue;
            else if(a>=(w+1)/2&&a<=w)
            {
              ok=i+1;
              continue;
            }
            v.push_back({a,i+1});
        }
        if(ok!=-1) 
         {
                  cout<<"1 "<<endl<<ok<<endl;
                  continue;
         }
 
        int sum=0;
        vi final;
        sort(v.begin(),v.end());
        for(auto x:v)
        {
            
            sum+=x.first;
            final.push_back(x.second);
            if((sum>=(w+1)/2)&&(sum<=w))
            break;
        }
   
       if(sum>=(w+1)/2&&sum<=w)
       {  
          cout<<final.size()<<endl;
          for(auto x:final)
          cout<<x<<" ";
          cout<<endl;
       }
       else 
       cout<<"-1"<<endl;
    }
 return 0;
// THINGS TO KEEP IN MIND
//   * int overflow, time and memory limits
//   * Special case (n = 1?)
//   * Do something instead of nothing and stay organized
//   * Don't get stuck in one focus
//   * int l=s.length()-x (s.length()<x) runtime error
// TIME AND MEMORY LIMITS
//   * 1 second is approximately 10^8 operations (c++)
//   * 10^6 Elements of 32 Bit (4 bytes) is equal to 4 MB
//   * 62x10^6 Elements of 32 Bit (4 bytes) is equal to 250 MB
//   * 10^6 Elements of 64 Bits (8 bytes) is equal to 8 MB
//   * 31x10^6 Elements of 64 Bit (8 bytes) is equal to 250 MB
}