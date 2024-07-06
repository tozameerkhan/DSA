#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int costMale,costFemale,costCouple,numCities,m;
vector<int> bfs(int src,vector<vector<int> >& adj) {
    vector<int> dist(numCities+1,-1);
    dist[src] = 0;
    queue<int> Q;
    Q.push(src);
    while(!Q.empty()) {
        int current = Q.front();
        Q.pop();
        for(auto child : adj[current]) {
            if(dist[child]==-1) {
                dist[child] = dist[current]+1;
                Q.push(child);
            }
        }
    }
    return dist;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin>>costMale>>costFemale>>costCouple>>numCities>>m;
  vector<vector<int> > adj(numCities+1);
  for(int i=0; i<m; i++) {
      int a,b;
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
  }
  vector<int> distanceFromCity1 = bfs(1,adj);
  vector<int> distanceFromCity2 = bfs(2,adj);
  vector<int> distanceFromCityN = bfs(numCities,adj);
  
  int ans = (distanceFromCity1[numCities] * costMale) + 
            (distanceFromCity2[numCities] * costFemale);
            
  for(int i=1;i<=numCities;i++) {
      if(distanceFromCity1[i]!=-1 && distanceFromCity2[i]!=-1 && distanceFromCityN[i]!=-1) {
          int temp = distanceFromCity1[i] * costMale + 
                     distanceFromCity2[i] * costFemale +
                     distanceFromCityN[i] * costCouple;
          ans = min(ans,temp);
      }
  }
  cout<<ans;
  return 0;

}
