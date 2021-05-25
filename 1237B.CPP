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
    queue<int>before,after;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        before.push(a);
    }
    for(int i=0;i<n;i++)
    {
        cin>>a;
        after.push(a);
    }
    int fine=0;
    vector<bool>vis(n+1,false);
    for(int i=0;i<n;i++)
    {    

        if(vis[before.front()])
        {  
          before.pop();
          continue;
        }        
        if(before.front()==after.front())
        {        
            vis[before.front()]=true;
            before.pop();
            after.pop();
          
        }
        else 
        {   
            vis[after.front()]=true;
            fine++;
            after.pop();
        }

    }
    cout<<fine;
     return 0;
}