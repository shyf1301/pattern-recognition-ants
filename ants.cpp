#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5+5;
const ll inf = 0x3f3f3f3f3f3f3f3fll;

template <class T>
inline bool read(T &ret) {
   char c; int sgn;
   if(c=getchar(),c==EOF) return 0; //EOF
   while(c!='-'&&(c<'0'||c>'9')) c=getchar();
   sgn=(c=='-')?-1:1;
   ret=(c=='-')?0:(c-'0');
   while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
   ret*=sgn;
   return 1;
}

struct Point
{
    int x[2], id;
    bool operator < (const Point& p) const{
        if(x[0] == p.x[0]) return x[1] < p.x[1];
        return x[0] < p.x[0];
    }
}point[MAXN<<2], node[MAXN<<2];

int cur_d;

bool cmp(const Point a, const Point b) {
    return a.x[cur_d] < b.x[cur_d];
}


void build(int l, int r, int d)
{
    if(l >= r) return;
    int mid = l + r >> 1;
    cur_d = d & 1;
    nth_element(node + l, node + mid, node + r + 1, cmp);
    build(l, mid - 1, d + 1);
    build(mid + 1, r, d + 1);
}

ll dis_sq(Point a, Point b)
{
    return (ll)(a.x[0] - b.x[0]) * (a.x[0] - b.x[0]) + (ll)(a.x[1] - b.x[1]) * (a.x[1] - b.x[1]);
}

ll n_dis;
int n_id;
Point n_point;

void query(int l, int r, int d)
{
    if(l > r) return;
    int mid = l + r >> 1;
    ll d_sq = dis_sq(node[mid], n_point);
    if (d_sq && (d_sq < n_dis || d_sq == n_dis && node[mid] < point[n_id])) {
        n_id = node[mid].id;
        n_dis = d_sq;
    }
    cur_d = d & 1;
    ll radius = (ll)(n_point.x[cur_d] - node[mid].x[cur_d])*(n_point.x[cur_d] - node[mid].x[cur_d]);
    if (n_point.x[cur_d] < node[mid].x[cur_d]) {
        query(l, mid - 1, d + 1);
        if (radius <= n_dis) {
            query(mid + 1, r, d + 1);
        }
    }
    else {
        query(mid + 1, r, d + 1);
        if (radius <= n_dis) {
            query(l, mid - 1, d + 1);
        }
    }
}

int fa[MAXN];

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int T, cas = 0;
    scanf("%d", &T);
    int n, q;
    while(T--) {
        printf("Case #%d:\n", ++cas);
        read(n), read(q);
        for(int i = 1; i <= n; ++i) {
            read(point[i].x[0]), read(point[i].x[1]);
            point[i].id = i;
            node[i] = point[i];
            fa[i] = i;
        }
        build(1, n, 0);
        for (int i = 1; i <= n; ++i) {
            n_point = point[i];
            n_dis = inf;
            query(1, n, 0);
            int father = find(i);
            fa[father] = find(n_id);
        }
        int u, v;
        while(q--){
            read(u), read(v);
            printf("%s\n", find(u) == find(v) ? "YES" : "NO");
        }
    }
    return 0;
}
