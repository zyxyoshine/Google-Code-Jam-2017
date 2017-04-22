#include <bits/stdc++.h>
using namespace std;

long long d[123][123];

int t,n,qq,u,k;
int e[123],v[123];

vector<pair<int,double> > g[123];
queue<int> q;
double f[123];
bool vis[123];

void work(int ca) {
    scanf("%d %d",&n,&qq);
    for (int i = 1;i <= n;i++)
        scanf("%d %d",&e[i],&v[i]);
    int r;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) {
            scanf("%d",&r);
            if (r == -1)
                d[i][j] = 123456789123456789ll;
            else
                d[i][j] = r;
        }
    for (int kk = 1;kk <= n;kk++)
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                d[i][j] = min(d[i][j],d[i][kk] + d[kk][j]);
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++)
            if(d[i][j] <= e[i]) {
                g[i].push_back(make_pair(j,(double)(d[i][j]) / (double)v[i]));
            }
    }
    printf("Case #%d:",ca);
    while (qq--) {
        scanf("%d %d",&u,&k);
        while(!q.empty())
            q.pop();
        for (int i = 1;i <= n;i++) {
            f[i] = 1e13;
            vis[i] = 0;
        }
        q.push(u);
        vis[u] = 1;
        f[u] = 0;
        while (!q.empty()) {
            int uu = q.front();
            q.pop();
            vis[uu] = 0;
            for (int kk = 0;kk < g[uu].size();kk++) {
                int v = g[uu][kk].first;
                double w = g[uu][kk].second;
                //cout << u << ' ' << v <<' ' <<w <<endl;
                if (f[v] > f[uu] + w) {
                    f[v] = f[uu] + w;
                    //cout << u << ' ' << v << ' ' << f[v] << endl;
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
        }
        printf(" %.7lf",(double)f[k]);
    }
    printf("\n");
    for (int i = 1;i <= n;i++)
        g[i].clear();
}

int main() {
    cin >> t;
    for (int _=1;_ <= t;_++)
        work(_);
    return 0;
}
