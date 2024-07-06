#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  vector<vector<int> > adj(n);
  vector<int> dist(n,-1);
  std::queue<int> Q;
  for(int i=0;i<n;i++) {
      int a;
      cin>>a;
      if(a==1) {
        dist[i] = 0;
        Q.push(i);
      }
  }
  for(int i=0;i<m;i++) {
    int a,b;
    cin>>a>>b;
    adj[a-1].push_back(b-1);
    adj[b-1].push_back(a-1);
  }
  while(!Q.empty()) {
    int current = Q.front();
    Q.pop();
    for(int i=0;i<adj[current].size();i++) {
      int next = adj[current][i];
      if(dist[next]==-1) {
        dist[next] = dist[current]+1;
        Q.push(next);
      }
    }
  }
  int ans = 0;
  for(int i=0;i<n;i++) {
    if(dist[i] == -1) {
      ans = -1;
      break;
    }
    ans = max(ans,dist[i]);
  }
  cout<<ans;
  return 0;

}
