#include <iostream>
#include <algorithm>
using namespace std;
int n, m;//n个交叉路口,m条道路
const int N = 310, M = 8010;
int fa[N];
struct node
{
    int x, y, z;
}arr[M];

bool cmp(node& a, node& b)
{
    return a.z < b.z;
}

int find(int x)
{
    if(fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}
int cnt;
int ret;
void kk()
{
    for(int i = 1; i <= m; i++)
    {
        int a = arr[i].x, b = arr[i].y, c = arr[i].z;
        int af = find(a), bf = find(b);
        if(af != bf)
        {
            cnt++;
            fa[af] = bf;
            ret = max(ret, c);
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) fa[i] = i;

    for(int i = 1; i <= m; i++)
    {
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
    }

    sort(arr + 1, arr + 1 + m, cmp);
    kk();
    cout << cnt << " " << ret << endl;
    return 0;
}

