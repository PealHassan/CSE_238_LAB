#include<bits/stdc++.h>
using namespace std;
vector<int>g[1010];
int n,m;
vector<int>taken(1010,0);
stack<int>order;
void HamiltonPath(int u) {
    if(order.size() == n) {
        vector<int>a;
        stack<int>order2 = order;
        while(order2.size()) {
            a.push_back(order2.top());
            order2.pop();
        }

        for(int i = n-1; i>=0; i--) cout << a[i] << " ";
        cout << endl;
        return;
    }
    for(int j = 0; j<g[u].size(); j++) {
        int v = g[u][j];
        if(!taken[v]) {
            taken[v] = 1;
            order.push(v);
            HamiltonPath(v);
            taken[v] = 0;
            order.pop();
        }
    }
    return;
}
void Hamilton() {
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    for(int i  = 0; i<m; i++) {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 1; i<=n; i++) {
        taken[i] = 1;
        order.push(i);
        HamiltonPath(i);
        order.pop();
        taken[i] = 0;
    }
}
int main() {
    Hamilton();
    return 0;
}

