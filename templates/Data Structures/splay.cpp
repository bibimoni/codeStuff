#include<bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define fr front()
#define pb push_back

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)

#define ll long long
#define oo INT_MAX

struct node
{
    node *child[2] , *p;
    int sz , v , sum , add = 0 , mini = 0 , maxi = 0; // mini = 0
    bool rev = false;
};

node *nil , *root;

void down(node *p)
{
    if(p -> child[1] != nil)
    {
        p -> child[1] -> add += p -> add;
        p -> child[1] -> v += p -> add;
        p -> child[1] -> maxi += p -> add;
        p -> child[1] -> mini += p -> add;
        p -> child[1] -> sum += p -> add * p -> child[1] -> sz;
    }
    if(p -> child[0] != nil)
    {
        p -> child[0] -> add += p -> add;
        p -> child[0] -> v += p -> add;
        p -> child[0] -> maxi += p -> add;
        p -> child[0] -> mini += p -> add;
        p -> child[0] -> sum += p -> add * p -> child[0] -> sz;
    }
    //cout << p -> add <<  " " << p -> sum << " " << p -> child[0] -> add << " " << p -> child[0] -> v << "\n";
    p -> add = 0;
}

void up(node *p)
{
    p -> sz = p -> child[0] -> sz + p -> child[1] -> sz + 1;
    p -> sum = p -> v + p -> child[0] -> sum + p -> child[1] -> sum;
    p -> mini = min(p -> child[0] -> mini , min(p -> child[1] -> mini , p -> v));
    p -> maxi = max(p -> child[0] -> maxi , max(p -> child[1] -> maxi , p -> v));
}

void init()
{
    nil = new node;
    nil -> p = nil -> child[1] = nil -> child[0] = nil;
    nil -> v = nil -> sz = nil -> rev = nil -> sum = nil -> add = 0;
    nil -> mini = oo;
    nil -> maxi = -oo;
}

void setlink(node *x , node *y , int d)
{
    x -> child[d] = y;
    y -> p = x;
}

int getson(node *x , node *y)
{
    return x -> child[0] == y ? 0 : 1;
}

void rotate(node *x , int d)
{
    node *y = x -> child[d] , *p = x -> p;
    setlink(x , y -> child[d ^ 1], d);
    setlink(y , x , d ^ 1);
    setlink(p , y , getson(p , x));
    up(x);up(y);
}

void splay(node *x)
{
    while(x -> p != nil)
    {
        node *p = x -> p, *pp = p -> p;
        int dp = getson(p , x) , dpp = getson(pp , p);
        if(pp == nil) rotate(p , dp);
        else if(dp == dpp) rotate(pp , dpp) , rotate(p , dp);
        else rotate(p , dp) , rotate(pp , dpp);
    }
    root = x;
}

void push(node *x)
{
    if(x -> rev)
    {
        x -> rev = false;
        swap(x -> child[0] , x -> child[1]);
        x -> child[0] -> rev = !x -> child[0] -> rev;
        x -> child[1] -> rev = !x -> child[1] -> rev;
    }
}

node *findkth(node *x , int pos)
{
    while(push(x) , down(x) , x -> child[0] -> sz + 1 != pos)
    {
        if(pos < x -> child[0] -> sz + 1) x = x -> child[0];
        else pos -= (x -> child[0] -> sz + 1) , x = x -> child[1];
    }
    splay(x);
    return x;
}

void split(node *t , int pos , node * &t1 , node * &t2)
{
    if(pos == 0) t2 = t , t1 = nil;
    else
    {
        t1 = findkth(root , pos);
        t2 = t1 -> child[1];
        t1 -> child[1] = t2 -> p = nil;
        up(t1);
    }
}

node *join(node *t1 , node *t2)
{
    if(t1 == nil) return root = t2;
    t1 = findkth(t1 , t1 -> sz);
    setlink(t1 , t2 , 1);
    up(t1);
    return t1;
}

void Insert(int pos , int v)
{
    node *t1 , *t2 , *t3;
    t2 = new node;
    t2 -> p = t2 -> child[0] = t2 -> child[1] = nil;
    t2 -> sum = v ;  t2 -> sz = 1; t2 -> v = v ;
    split(root , pos - 1 , t1 , t3);
    join(join(t1 , t2) , t3);
}

void Erase(int pos)
{
    node *t1 , *t2 , *t3;
    split(root , pos  , t1 , t3);
    split(t1 , pos - 1 , t1 , t2);
    join(t1 , t3);
}

void qrev(int l , int r)
{
    node *t1 , *t2 , *t3;
    split(root , r , t1 , t3);
    split(t1 , l - 1 , t1 , t2);
    t2 -> rev = !t2 -> rev;
    join(join(t1 , t2) , t3);
}

void sum(int l , int r)
{
    node *t1 , *t2 , *t3;
    split(root , r , t1 , t3);
    split(t1 , l - 1 , t1 , t2);
    cout << t2 -> sum << "\n";
    join(join(t1 , t2) , t3);
}

void add(int l , int r , int val)
{
    node *t1 , *t2 , *t3;
    split(root , r , t1 , t3);
    split(t1 , l - 1 , t1 , t2);
    t2 -> v += val;
    t2 -> sum += val * t2 -> sz;
    t2 -> mini += val;
    t2 -> maxi += val;
    t2 -> add += val;
    join(join(t1 , t2) , t3);
}

void getmax(int l , int r)
{
    node *t1 , *t2 , *t3;
    split(root , r , t1 , t3);
    split(t1 , l - 1 , t1 , t2);
    cout << t2 -> maxi << "\n";
    join(join(t1 , t2) , t3);
}

void getmin(int l , int r)
{
    node *t1 , *t2 , *t3;
    split(root , r , t1 , t3);
    split(t1 , l - 1 , t1 , t2);
    cout << t2 -> mini << "\n";
    join(join(t1 , t2) , t3);
}

const int N = 2e5 + 5;
int n , q , pos , k , type , m , l , r;
int a[N];

node* buildtree(int l , int r)
{
    if(l == r) return nil;
    int mid = (l + r) / 2;
    node *x = new node;
    x -> v = a[mid];
    x -> sum = x -> sz = x -> rev = 0;
    x -> p = nil;
    setlink(x , buildtree(l , mid) , 0);
    setlink(x , buildtree(mid + 1 , r) , 1);
    up(x);
    return x;
}

void debug()
{
    FOR(i , 1 , n)
    {
        findkth(root , i);
        cout << "a[" << i << "]: "  << root -> v << "\n";
    }
}

int main()
{
    freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;/// nhập số phần tử và truy vấn.
    /*FOR(i , 1 , n)
        cin >> a[i];*/
    /// xóa dòng trên nếu ms vào phải nhập giá trị các phần tử.
    /// nếu không các phần tử khởi đầu đều là 0.
    init();
    root = buildtree(1 , n + 1);
    FOR(i , 1 , q)
    {
        cin >> type;
        if(type == 0)
        {
            int val;
            cin >> l >> r >> val; /// cập nhật [l,r] thêm x đơn vị.
            add(l , r , val);
        }
        else if(type == 1)
        {
            cin >> l >> r;
            getmax(l , r);/// in ra max trong đoạn [l , r];
        }
        else if(type == 2)
        {
            cin >> l >> r;
            getmin(l , r); /// in ra min trong đoạn [l , r];
        }
        else if(type == 3)
        {
            cin >> l >> r;
            qrev(l , r); /// đảo ngược các phần tử trong đoạn [l , r].
        }
        else if(type == 4)
        {
            cin >> l >> r;
            sum(l , r); /// in ra tổng các phần tử trong đoạn [l , r].
        }
        else if(type == 5)
        {
            n++;
            int pos , val;
            cin >> pos >> val;
            Insert(pos , val); /// chèn phần tử vị trí pos với giá trị là val và mở rộng pos -> pos + 1 , pos + 1 -> pos + 2 , ... , n -> n + 1.
        }
        else if(type == 6)
        {
            n--;
            int pos;
            cin >> pos;
            Erase(pos); /// xóa phần tử ở vị trí pos và thu hẹp pos + 1 -> pos , pos + 2 -> pos + 1 , ... , n  -> n - 1.
        }
    }
    ///debug();
    /// xóa 3 dấu /// để in ra giá trị hiện tại các phần tử a1 ,a2 , ... an.
    /*
6 20
5 2 57
0 5 7 19
4 2 2
1 1 2
0 5 6 32
6 1
6 2
3 3 4
4 2 2
3 5 5
6 3
1 3 3
3 4 4
3 4 4
1 1 4
6 4
2 3 3
1 3 3
4 3 3
4 3 3
*/
    /// test chạy thử.
}

