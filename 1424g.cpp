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
//#include<ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree <int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update > ordered_set; 
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
    map<int , int> m ;
    for(int i = 0 ; i < n ; i ++ ) 
    {
        int b ,d ;
        cin >> b >> d ;
        m[b] ++ ;
        m[d] -- ;
    }
   
    pii ans ;
    auto it = m.begin() ;
    int sum = it -> second ;
    ans  = { it ->first , sum} ;
    it ++ ;
    while(it != m.end())
    {
        sum += (*it).second ;

        if(ans.second < sum) 
        {
            ans.first = (*it).first ;
            ans.second = sum ;
        }

        it ++ ;
    }
    cout << ans.first << " "<< ans.second << endl;
 return 0;

}