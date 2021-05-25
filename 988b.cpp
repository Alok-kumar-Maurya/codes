#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
class my
{   
    public:
    string s;
    bool operator<(my s)const
    {
         if(this->s.length()<s.s.length())
         return  true ;
         if(this->s.length()==s.s.length()) 
         return this->s<s.s;
         return false;

    }

};
bool checker(string a,string b)
{   
    for(int i=0;i<=b.length()-a.length();i++)
    {
       string c=b.substr(i,a.length());
       if(c==a)
       return true;
    }
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    multiset<my>seet;
    int n;
    cin>>n;
    while (n --)
    {
        my o;
        cin>>o.s;
        seet.insert(o);   
    }
    bool ok=true;
    for(auto it=seet.begin();it!=seet.end();it++)
    {
        auto it2=it;
        it2++;
        if(it2==seet.end())
        continue;
        if(!checker((*it).s,(*it2).s))
        ok=false;
        
    }
    if(ok)
    {
        cout<<"YES"<<endl;
        for(auto x:seet)
        cout<<x.s<<endl;
    }
    else 
    cout<<"NO"<<endl;
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