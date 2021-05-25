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
        int n,cnt=0;
        cin>>n;
        set<int,greater<int>>s;
        for(int i=0;i<n;i++)
         {
             int a;
             cin>>a;
             if(a%2==0)
             s.insert(a);
         }
         while (s.size())
         {
             int top=*s.begin();
             s.erase(s.begin());
             if(top%2==0)
             {
               cnt++;
               s.insert(top/2);
             }
         }
         cout<<cnt<<endl;
         
         
    }
     return 0;
}