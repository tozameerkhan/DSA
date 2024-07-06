#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n,m;
  cin>>n>>m;
  vector<vector<int> > adj(n);
  for(int i=0;i<m;i++) {
    int a,b;
    cin>>a>>b;
    adj[a-1].push_back(b-1);
    adj[b-1].push_back(a-1);
  }
  int source, target;
  cin>>source>>target;
  source--; target--;
  vector<int> dist(n,-1);
  queue<int> Q;
  dist[source] = 0;
  Q.push(source);
  while(!Q.empty()) {
    int current = Q.front();
    Q.pop();
    for(int i=0;i<adj[current].size();i++) {
      int nbr = adj[current][i];
      if(dist[nbr]==-1) {
        dist[nbr] = dist[current]+1;
        Q.push(nbr);
      }
    }
  }
  if(dist[target]==-1)
    cout<<0;
  else
    cout<<dist[target];
  return 0;

}
