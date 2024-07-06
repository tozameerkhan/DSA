#include <bits/stdc++.h>
using namespace std;
int ans = INT_MIN;
int diameter(int current,vector<vector<int> >&adj,vector<bool>& visited) {
  if(adj[current].size()==1 && current!=0)
      return 1;
  int firstMax = 0, secondMax = 0;
  for(auto child : adj[current]) {
    if(!visited[child]){
      visited[child] = true;
      int temp = diameter(child,adj,visited);
      if(temp >= firstMax) {
        secondMax = firstMax;
        firstMax = temp;
      }
      else if(temp > secondMax) 
        secondMax = temp;
    }
  }
  ans = max(ans,firstMax+secondMax+1);
  return firstMax+1;
  
}
int main() {
  int n;
  cin>>n;
  vector<vector<int> > adj(n);
  vector<bool> visited(n,false);
  for(int i=0;i<n-1;i++) {
      int a,b;
      cin>>a>>b;
      adj[a-1].push_back(b-1);
      adj[b-1].push_back(a-1);
  }
  visited[0] = true;
  int k =diameter(0,adj,visited);
  cout<<max(k,ans)-1;
  return 0;

}
