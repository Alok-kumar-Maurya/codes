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
    int n,cntL=0,cntR=0,maxL=-1,maxR=-1,indexL=0,indexR=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        if(l>r)
        {
            if(maxL<l)
            {
             maxL=l;
             indexL=i;
            }
        }
        else if(r>l)
        {
           if(maxR<r)
           {
             maxR=r;
             indexR=i;
           }
        }
        cntL+=l;
        cntR+=r;
    
    }
    if(cntL>cntR)
    {
        if(maxR!=-1)
        cout<<indexR;
        else 
        cout<<"0";
    }
    else if(cntR>cntL)
    {
       if(maxL!=-1)
       cout<<indexL;
       else 
       cout<<"0";
    }
    else 
    {    

        if(maxL>=maxR)
        cout<<indexL;
        else 
        cout<<indexR;
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