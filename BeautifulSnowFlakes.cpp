#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  vector<vector<int> > adj(n);
  unordered_map<int,int> map;
  for(int i=0;i<m;i++) {
    int a,b;
    cin>>a>>b;
    adj[a-1].push_back(b-1);
    adj[b-1].push_back(a-1);
  }
  long long ans = 0;
  for(int i=0;i<n;i++) {
    if(adj[i].size()==1) continue;
    bool flag = true;
    for(int j=0;j<adj[i].size();j++) {
      if(adj[adj[i][j]].size()!=1) {
        flag = false;
        break;
      }
    }
    if(flag) {
        map[adj[i].size()]++;
    }
  }
  for(auto it : map){
    if(it.second==1)
      ans++;
  }
  cout<<ans;
  return 0;

}
