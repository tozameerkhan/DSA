#include <bits/stdc++.h>
using namespace std;
int DFS(int cur,int par,int k,int cr,vector<int>& colour,vector<vector<int>>& adj) {
  if(colour[cur]==1) 
      cr++;
  else 
      cr=0;
  if(cr>k)
    return 0;
  int sum = 0;
  for(auto child : adj[cur]) {
    if(child!=par)
      sum += DFS(child,cur,k,cr,colour,adj);
  }
  if(adj[cur].size()<=1 && par!=-1)
    sum++;
  return sum;
}
int main() {
  int n,c;
  cin>>n>>c;
  vector<int> colour(n);
  vector<vector<int> > adj(n);
  for(int i=0;i<n;i++)
    cin>>colour[i];
  for(int i=0;i<n-1;i++) {
      int a,b;
      cin>>a>>b;
      adj[a-1].push_back(b-1);
      adj[b-1].push_back(a-1);
  }
  cout<<DFS(0,-1,c,0,colour,adj);
  return 0;

}
