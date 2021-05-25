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
    int n ;
    cin >> n ;
    vi v(n + 1) ;
    unordered_set<int> s , fit;
    for(int i = 1 ; i <= n ; i ++)
    {
       cin >> v[i];
        if(v[i] == 0)
          s.insert(i) ;
        else 
          fit.insert(v[i]) ;

    }  
    vi shift ;
    for(auto it = s.begin() ; it != s.end() ; )
    {
        if(fit.find(*it) == fit.end()) 
        {   
            if(v[*it] == 0)
            shift.push_back(*it) ;
            v[*it] = *it ;
            s.erase(it);
        }
        else 
        it ++ ;
    }
    while(fit.size()) 
    {   
        int l = *s.begin();
        int m = *fit.begin();
        s.erase(s.begin());
        fit.erase(fit.begin());
        v[l] = m;
    }
    for(int i = 0; i < shift.size() - 1 ; i++ )
    {
        swap(v[shift[i]]  , v[shift[i + 1]]);
    }
    for(int i = 1 ; i <= n ; i ++)
    cout << v[i] <<" ";
} 