#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
const int N = 110;
queue<int> q;
vector<int> edges[N];
int in[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        while(cin >> x, x)
        {
            edges[i].push_back(x);
            in[x]++;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(in[i] == 0)
        {
            q.push(i);
        }
    }

    while(q.size())
    {
        int x = q.front(); q.pop();
        cout << x << " ";
        for(auto& e : edges[x])
        {
            in[e]--;
            if(in[e] == 0)
            {
                q.push(e);
            }
        }
    }

    return 0;
}