#include <bits/stdc++.h>
using namespace std;
pair<int,int> shop,home;
vector<int> dx = {1,-1,0,0};
vector<int> dy = {0,0,1,-1};
int n,m,k;
vector<string> grid;

bool check(int x,int y,vector<vector<int>>& dist) {
    if(x<0 || x>=n || y<0 || y>=m || dist[x][y]!=-1)
        return false;
    if(grid[x][y] == '#')
      return false;
    return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin>>n>>m>>k;
  for(int i=0;i<n;i++) {
    string s;
    cin>>s;
    grid.push_back(s);
    for(int j=0;j<m;j++) {
      if(s[j] == 'i')
          shop = {i,j};
      if(s[j] == 'h')
          home = {i,j};
    }
  }
  vector<vector<int> > dist(n,vector<int>(m,-1));
  queue<pair<int,int>> Q;
  Q.push(shop);
  dist[shop.first][shop.second] = 0;
  while(!Q.empty()) {
      auto current = Q.front();
      Q.pop();
      for(int i=0;i<4;i++) {
        int x = current.first+dx[i];
        int y = current.second+dy[i];
        if(check(x,y,dist)) {
          dist[x][y] = dist[current.first][current.second]+1;
          Q.push({x,y});
          if(grid[x][y] == 'h' && dist[x][y] <= k) {
              cout<<"YES";
              return 0;
          }
        }
      }
  }
  cout<<"NO";
  return 0;

}
