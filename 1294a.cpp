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
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if((a+b+c+d)%3==0)
        {     
            int e=(a+b+c+d)/3;
            if(a<=e&&b<=e&&c<=e)
            cout<<"YES";
            else 
            cout<<"NO";
        }
        else 
        cout<<"NO";
        cout<<endl;
    }
     return 0;
}