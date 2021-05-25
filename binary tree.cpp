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
struct node 
{
    int data ;
    node *left , *right ;
    node(int a) 
    {
        data = a ;
        left = right = NULL;
    }
} ;
class B_tree
{
        public :
        node *root ;
        int dia = 0 ,ans = 0;
        vi path ;
        map<int,int> m;
        void Preorder(node *) ;
        void Levelorder_with_sum(node *);
        int height(node *) ;
        void diameter(node *) ;
        void root_to_leaf(node *);
        void left_right_view(node * ) ;
        void top_view(node * , int) ;
        void bottom_view(node * ,int);
        void spiral_lev_order(node *);
};
void B_tree ::Preorder(node *cur)
{ 
    if(cur == NULL) 
    return ;
    cout << cur->data <<" --> " ;
    Preorder(cur->left) ;
    Preorder(cur->right) ;
}
int B_tree ::height(node *cur) 
{
    if(cur == NULL )
    return 0;
    int h = max ( height(cur->left) , height(cur->right) );
    return h + 1 ;
}
void B_tree::Levelorder_with_sum(node * cur) 
{  
    if(cur == NULL)
       return ;
    queue<node *> pq ;
    pq.push(cur) ;
    while(!pq.empty()) 
    {
       int cnt = pq.size() ;
       int sum = 0 ;
       for(int i = 0 ; i < cnt ; i++) 
       {    
             auto top =  pq.front() ;
             pq.pop() ;
             cout << top->data <<" --> ";
             sum += top->data ;
           
             if(top->left != NULL) 
                 pq.push(top->left) ;
             if(top->right != NULL ) 
                 pq.push(top->right);
       }
       cout <<"level sum  : " << sum << endl;
    }
}
void B_tree ::spiral_lev_order(node *cur)
{
    if(cur == NULL)
    return ;
    queue<node *> pq ;
    pq.push(cur) ;
    int lev = 0;
    while(!pq.empty()) 
    {
       int cnt = pq.size() ;
       for(int i = 0 ; i < cnt ; i++) 
       {    
             auto top =  pq.front() ;
             pq.pop() ;   
             path.push_back(top->data) ;        
             if(top->left != NULL) 
                 pq.push(top->left) ;
             if(top->right != NULL ) 
                 pq.push(top->right);
       }
       if(lev % 2 == 0 ) 
       reverse(path.begin() , path.end()) ;
       for(auto x :path) 
       cout << x <<" ----> " ;
       path.clear() ;
       lev ++ ;


    }
}
void B_tree ::left_right_view(node *cur )  
{   
    queue<node *> pq ;
    pq.push(cur) ;
    while(!pq.empty()) 
    {
       int cnt = pq.size() ;
       for(int i = 1 ; i <= cnt ; i++) 
       {    
             auto top =  pq.front() ;
             pq.pop() ;
             if(i == 1)
             cout << top->data <<" --> ";             /// for left view
             if(i == cnt ) 
             cout << top->data <<" --> ";             //// for right view
             if(top->left != NULL) 
                 pq.push(top->left) ;
             if(top->right != NULL ) 
                 pq.push(top->right);
       }
    }
}
void B_tree ::top_view(node * cur , int cnt)
{
     if(cur == NULL)
     return ;
     if(m[cnt] == 0) 
     m[cnt] = cur-> data ;
     top_view(cur -> left , cnt - 1) ;
     top_view(cur -> right , cnt + 1) ;
}
void B_tree ::bottom_view(node * cur , int cnt)
{
     if(cur == NULL)
     return ;
     m[cnt] = cur-> data ;
     bottom_view(cur -> left , cnt - 1) ;
     bottom_view(cur -> right , cnt + 1) ;
}
void B_tree ::diameter(node *cur)
{
    if(cur == NULL)
    return  ;
    int le = height(cur -> left) ;
    int ri = height(cur -> right); 
    dia = max(le+ri , dia);
}
void B_tree ::root_to_leaf(node *cur)
{
       if(cur == NULL) 
       return ;
       path.push_back(cur->data) ;
       if(cur ->left == NULL && cur ->right == NULL )
       {   
           int sum = 0 ;
           for(auto x : path) 
           {  
               cout <<x<<" ---> " ;
               sum += x ;
           }
            cout << "sum is : " << sum <<" "<<endl;
            ans = max(sum , ans) ;
       }
       root_to_leaf(cur ->left) ;
       root_to_leaf(cur->right);
       path.pop_back();

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

    B_tree t ;
    t.root = new node(10);
    t.root->left = new node(20);
    t.root->right = new node(30);
    t.root->left->left =new node(40);
    t.root->left->right = new node (50) ;
    t.root->right->left = new node(60) ;
    t.root->right->right = new node(70);
    // t.Preorder(t.root);
    // t.Levelorder_with_sum(t.root);
    //cout << t.height(t.root);
    // t.diameter(t.root) ;
    // cout << t.dia ;
    // t.root_to_leaf(t.root);
    // t.top_view(t.root , 0); 
    // for(auto x :t.m)
    // cout << x.second <<" ---> " ;
    // cout << endl;
    // t.m.clear();
    // t.bottom_view(t.root , 0); 
    // for(auto x :t.m)
    // cout << x.second <<" ---> " ;
    t.spiral_lev_order(t.root); 
   
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