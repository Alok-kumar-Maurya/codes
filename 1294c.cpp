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
    int a,b=1,c,n,k=1;
    bool ok=false;
    cin>>n;
    int temp=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {   
                if(k)
                {
                    a=i;
                    k=0;
                    n/=i;
                    continue;
                }
                    n/=i;
                    b*=i;
            
                if(b>a)
                {
                     c=temp/(a*b);
                     if(c!=a&&c!=b&&c>1)
                     {
                       ok=true;
                       break;
                     }
                 }
            }
        }
       if(ok)
       break;

    }
    if(ok) 
    cout<<"YES"<<endl<<a<<" "<<b<<" "<<c<<endl;
    else 
    cout<<"NO"<<endl;
 }
     return 0;
}