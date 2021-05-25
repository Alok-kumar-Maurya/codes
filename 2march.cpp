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
#define endl  "\n" 
bool is(string s) 
{   
    int cnt = 0;
    for(int i = 0 ; i < s.length() ; i++) 
    {
        if(s[i] == ')') 
        {  
            if(cnt)
            cnt -- ;
            else 
            return false;

        }
        if(s[i] == '(') 
        cnt ++ ;
    }
    return true ;
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
    int t ;
    cin >> t ;
    while(t -- ) 
    {
       string s ;
       cin >> s;
       int n = s.length() ;
       int cnt1 = 0 , cnt2 = 0 ,cnt3 =0 ;
       for(int i = 0 ; i < s.length() ; i ++) 
       {
           if(s[i] == 'A') 
           cnt1 ++ ;
           if(s[i] == 'B') 
           cnt2 ++ ;
           if(s[i] == 'C') 
           cnt3 ++ ;
       }
       string a = s , b = s;
       bool ok = true ;
       if(cnt1 + cnt2 == (n + 1 ) / 2 ) 
       {
              for(int i = 0 ; i < n ; i ++) 
              {
                  if(s[i] == 'A' || s[i] == 'B') 
                  {
                    a[i] = '(' ;
                    b[i] = ')' ;
                  }
                  else 
                  {
                     a[i] = ')' ;
                     b[i] = '(' ;
                  }
              }
       }
       else if(cnt1 + cnt3 == (n + 1 )/ 2) 
       {
              for(int i = 0 ; i < n ; i ++) 
              {
                  if(s[i] == 'A' || s[i] == 'C') 
                  {
                    a[i] = '(' ;
                    b[i] = ')' ;
                  }
                  else 
                  {
                     a[i] = ')' ;
                     b[i] = '(' ;
                  }
              }
    
       }
       else if(cnt2 + cnt3 == (n + 1) / 2) 
       {
              for(int i = 0 ; i < n ; i ++) 
              {
                  if(s[i] == 'B' || s[i] == 'C') 
                  {
                    a[i] = '(' ;
                    b[i] = ')' ;
                  }
                  else 
                  {
                     a[i] = ')' ;
                     b[i] = '(' ;
                  }
              }
              
       }
       else 
       ok = false ;
       if(ok && (is(a) || is(b)))
       cout <<"YES"<<endl;
       else 
       cout <<"NO" << endl;
    }
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