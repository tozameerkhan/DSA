#include <bits/stdc++.h>
using namespace std;
int DFS(int cur,int par,vector<int>& ans,vector<vector<int>>& adj) {
  int sum = 1;
  for(auto nbr : adj[cur]) {
    if(nbr!=par) {
      sum += DFS(nbr,cur,ans,adj);
    }
  }
  return ans[cur] = sum;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<vector<int> > adj(n);
  for(int i=1;i<n;i++) {
    int a;
    cin>>a;
    adj[a-1].push_back(i);
    adj[i].push_back(a-1);
  }
  vector<int> ans(n,0);
  DFS(0,-1,ans,adj);
  for(int i=0;i<n;i++)
    cout<<ans[i]-1<<" ";
  return 0;

}
