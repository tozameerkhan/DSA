#include <bits/stdc++.h>
using namespace std;

bool DFS(int cur,vector<vector<int>>& adjL,vector<int>& status) {
    status[cur] = 0;
    bool ans = true;
    for(auto child : adjL[cur]) {
          if(status[child]==0)
              return false;
          if(status[child]==-1) {
            ans = ans && DFS(child,adjL,status);
            if(!ans)
              return false;
          }
    }
    status[cur] = 1;
    return ans;
}
int main() {
  int n,m;
  cin>>n>>m;
  vector<vector<int> > adjL(n);
  for(int i=0;i<m;i++) {
      int a,b;
      cin>>a>>b;
      adjL[a].push_back(b);
  }
  vector<int> status(n,-1);
  bool ans = true;
  for(int i=0;i<n;i++) {
    if(status[i] == -1) 
        ans = ans && DFS(i,adjL,status);
  }
  if(ans)
    cout<<"YES";
  else
    cout<<"NO";
  return 0;
}
