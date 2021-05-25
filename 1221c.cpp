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
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
        vector<int> row_sum;
        int n ;
        cin >> n ;
        int list[n] ;
        for(int i = 0 ; i < n ; i ++)
        {
            cin >> list[i];
        }
        int row = sqrt(n);
        int sum = 0 ;
        for(int i = 0 ; i < n ; i ++)
        {
            if( i % row == row -1)         /// means one row complete
            {    
                 sum += list[i] ;
                 row_sum.push_back(sum);
                 sum = 0 ;
                 
            }
            else 
            {
                sum += list[i];
            }
        }
        vi colom( row, 0) ;          /////row  == coloum 
        for(int i = 0 ; i < n ; i ++)
        {
              colom[i % row] += list[i] ;
        } 
        int target = 0 , target2 = row - 1, d2 = 0, d1= 0 ,cnt = 0;
        for(int i = 0 ; i < n ; i ++)
        {
            if(target == i ) 
            {
               d1 += list[i];            
               target += row + 1;     
            }
            if(target2 == i && cnt < row) 
            {
                d2 += list[i] ;
                target2 += row - 1 ;
                cnt ++ ;
            }
        }

        cout << d1 <<" "<< d2 << endl;
        cout << "rom sum "<<endl;
        for(auto x : row_sum) 
        cout << x << " ";
        cout <<endl<<"coloum sum" << endl;
        for(auto x : colom) 
        cout << x << " ";
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