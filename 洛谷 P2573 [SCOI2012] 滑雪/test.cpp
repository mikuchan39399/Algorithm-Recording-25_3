
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;//n个节点，m条边
const int N = 1e5 + 10, M = 2e6 + 10;
typedef pair<int, int> PII;
typedef long long LL;
vector<PII> edges[N];
int high[N];
int fa[N];
bool st[N];
int pos;//通过搜索确定可达到的景点数量
int cnt;//有效边的数量
struct node
{
    int x, y, z, h;
}arr[M];//存有效边的数组

bool cmp(node& a, node& b)//先把通向高位置的边排前面，再考虑权值
{
    if(a.h != b.h) return a.h > b.h;
    else return a.z < b.z;
}

void dfs(int x)//x是当前节点
{
    st[x] = true;
    pos++;
    for(auto& e : edges[x])
    {
        int next = e.first, cost = e.second;
        
        cnt++;
        arr[cnt].x = x; arr[cnt].y = next; arr[cnt].z = cost;
        arr[cnt].h = high[next];
            
        if(!st[next]) dfs(next);
    }
    return;
}

int find(int x)
{
    if(fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}

LL kk()
{
    sort(arr + 1, arr + 1 + cnt, cmp);
    for(int i = 1; i <= n; i++) fa[i] = i;//初始化并查集
    LL sum = 0;
    for(int i = 1; i <= cnt; i++)
    {
        int a = arr[i].x, b = arr[i].y, c = arr[i].z;
        int af = find(a), bf = find(b);
        if(af != bf)
        {
            fa[af] = bf;
            sum += c;
        }
    }
    return sum;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> high[i]; 
    }
    for(int i = 1; i <= m; i++)//存图
    {
        int u, v, k; cin >> u >> v >> k;
        if(high[u] >= high[v])edges[u].push_back({v, k});
        if(high[v] >= high[u])edges[v].push_back({u, k});
    }
    dfs(1);
    
    LL ret = kk();
    cout << pos << " " << ret << endl;
    return 0;
}