#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t,n;
    cin>>t;
    while(t--)
    {         
       
       int n,k=1;
       cin>>n;
       vi a(n);
       for(int i=0;i<n;i++)
       {     
           cin>>a[i];
       }
       for(int i=0;i<n;i+=2)
       {
           if(a[i]*a[i+1]<0)
           cout<<abs(a[i+1])<<" "<<abs(a[i])<<" ";
           else
           {
               cout<<-abs(a[i+1])<<" "<<abs(a[i])<<" ";
           }
           
       }
      cout<<endl;
    }
        return 0;

}