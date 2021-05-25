#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define debugxy(x,y) cout<<"[ "<<x<<"  "<<y<<" ]"<< endl
#define debugx(x) cout <<"[ "<< x <<" ]"<<endl
class mycomp
{
  public : 
  bool operator()(string a ,string b) 
   {
       if(a.length() > b.length()) 
       return false; 
       if(a.length() == b.length()) 
       return a < b ;
       return true;
   }
};
set<string , mycomp> ans;
void f(int l , int r ,string a)
{
    if(l > r)
    return ;
    f(l , r - 1 , a) ;
    f(l + 1  ,r , a) ;
    string s = a.substr(l ,  r - l + 1) ;
    ans.insert(s) ;
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
    string s ;
    cin >> s ;
    int n  = s.length();
    f(0 , n - 1 , s) ;
    for(auto x :ans)
    cout << x << " " ;
 return 0;
// THINGS TO KEEP IN MIND
//   * int overflow, time and memory limits
//   * Special case (n = 1?)
//   * Do something instead of nothing and stay organized
//   * Don't get stuck in one focus
//   * int l=s.length()-x (s.length()<x) garbage value
// TIME AND MEMORY LIMITS
//   * 1 second is approximately 10^8 operations (c++)
//   * 10^6 Elements of 32 Bit (4 bytes) is equal to 4 MB
//   * 62x10^6 Elements of 32 Bit (4 bytes) is equal to 250 MB
//   * 10^6 Elements of 64 Bits (8 bytes) is equal to 8 MB
//   * 31x10^6 Elements of 64 Bit (8 bytes) is equal to 250 MB
}