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
    int n,a;
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++)
       cin>>v[i];
       
    set<int>color1,color2,color3;
    for(int i=0;i<2*n;i++)
    {
        cin>>a;
        if(a==1)
        color1.insert(v[i%n]);
        else if(a==2)
        color2.insert(v[i%n]);
        else 
        color3.insert(v[i%n]);
    }
    int k;
    cin>>k;
    set<int>price_check;
    for(int i=0;i<k;i++)
    {
        cin>>a;
        int top=-1;
        if(a==1)
        {
                if(!color1.empty())
                top=*color1.begin();
                
        }
        else if(a==2)
        {
                if(!color2.empty())
                top=*color2.begin();
        }
        else
        {
                if(!color3.empty())
                top=*color3.begin();
        }
        color2.erase(top);
        color3.erase(top);
        color1.erase(top);
        cout<<top<<" ";
    }
     return 0;
}