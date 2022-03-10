#include<bits/stdc++.h>
using namespace std;
vector<int>g[1010],deg(1010,0);
vector< pair<int,int> >path;
int n,m,src = 1;
int vis[1010][1010];
bool isBridge(int u, int v) {
    queue<int>q;
    q.push(u);
    int cnt = 1;
    vector<int>vis2(1010,0);
    vis2[u] = 1;
    while(!q.empty()) {
        int l = q.front();
        q.pop();
        for(int j = 0; j<g[l].size(); j++) {
            int temp = g[l][j];
            if(u == l && v == temp) continue;
            if(u == temp && v == l) continue;
            if(!vis[l][temp] && !vis2[temp]) {
                vis2[temp] = 1;
                cnt++;
                q.push(temp);
            }

        }
    }
    if(cnt == n) return false;
    return true;
}
void EulerTraverse(int u) {
    if(path.size() == m) return;
    vector<int>bridge;
    for(int i = 0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(isBridge(u,v)) bridge.push_back(v);
        else if(!vis[u][v]){
            vis[u][v] = vis[v][u] = 1;
            path.push_back({u,v});
            deg[u]--;
            deg[v]--;
            if(!deg[u]) n--;
            if(!deg[v]) n--;
            EulerTraverse(v);
            return;
        }
    }
    if(bridge.size()) {
            vis[u][bridge[0]] = vis[bridge[0]][u] = 1;
            deg[u]--;
            deg[bridge[0]]--;
            if(!deg[u]) n--;
            if(!deg[bridge[0]]) n--;
            path.push_back({u,bridge[0]});
            EulerTraverse(bridge[0]);
    }
    return;
}

void Euler() {
    cin >> n >> m;
    for(int i = 0; i<m; i++) {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    int cnt = 0;
    for(int i = 1; i<=n; i++) {
        if(deg[i]%2) {
            cnt++;
            src = i;
        }
    }
    if(cnt == 0 || cnt == 2) {
        EulerTraverse(src);
        cout << "Euler Path :\n";
        for(int i = 0; i<path.size(); i++) {
                if(i>0) cout << ",";
                cout << path[i].first << "->" << path[i].second;
        }
        cout <<endl;
        return ;
    }
    cout << "Euler Path doesn't exist." << endl;
}

int main() {
    Euler();
    return 0;
}
/*
4 4
1 2
2 3
2 4
3 4

5 8
1 5
1 4
1 2
5 2
5 4
4 2
2 3
3 4
*/
