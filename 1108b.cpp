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
    multiset<int>s;
    cin>>n;
    for(int i=0;i<n;i++)
    {       
        cin>>a;
        s.insert(a);
    }
    int c=*s.rbegin();
    for(int i=1;i<=c;i++)
    {
        if(c%i==0)
        s.erase(s.find(i));
    }
    int d=*s.rbegin();
    cout<<c<<" "<<d;
    return 0;
}