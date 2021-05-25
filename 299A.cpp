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
    int t,a,b;
    cin>>t;
    while(t--)
    {
       cin>>a>>b;
       bool ok=false;
       if(a-b==1) 
         {          
             ok=true;
             for(int i=2;i*i<=(a+b);i++)
             {
                 if((a+b)%i==0)
                 {
                     ok=false;
                     break;
                 }
             }
         }
        if(ok)
        cout<<"YES";
        else
        cout<<"NO";
        cout<<endl;
        
    }
         return 0;
}