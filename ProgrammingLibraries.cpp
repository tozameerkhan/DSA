#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n,m;
  cin>>n>>m;
  vector<vector<int> > adj(n);
  vector<int> degree(n,0);
  vector<int> ans;

  for(int i=0;i<m;i++) {
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    degree[b]++;
  }
  queue<int> Q;
  for(int i=0;i<n;i++) {
    if(degree[i]==0) {
      Q.push(i);
    }
  }
  
  while(!Q.empty()) {
    int current = Q.front();
    ans.push_back(current);
    Q.pop();
    for(auto child : adj[current]) {
      degree[child]--;
      if(degree[child]==0) {
        Q.push(child);
      }
    }
  }
  for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";
  return 0;

}
