#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
bool intersecting(array<int,3>&c1,array<int,3>&c2) {
    return (c1[2] + c2[2]) * (c1[2] + c2[2]) >= (c1[0] - c2[0]) * (c1[0] - c2[0]) + (c1[1] - c2[1]) * (c1[1] - c2[1]);
}

vector<int> bfs(int src,vector<int>* graph,int N) {
    vector<int> visited(N,0);
    queue<int> Q;
    Q.push(src);
    visited[src] = 1;
    while(!Q.empty()) {
        int current = Q.front();
        Q.pop();
        
        for(auto& child : graph[current]) {
            if(!visited[child]) {
              visited[child] = 1;
              Q.push(child);
            }
        }
    }
    return visited;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--) {
      int N,M,circleCount;
      cin>>N>>M>>circleCount;
      vector<int> graph[circleCount+5];
      vector<array<int, 3>> circle(circleCount+1);
      for(int i=1;i<=circleCount;i++) {
        cin>>circle[i][0]>>circle[i][1]>>circle[i][2];
        }
        
      for(int i=1;i<=circleCount;i++) {
          for(int j=i-1;j>0;j--) {
              if(intersecting(circle[i],circle[j])) {
                  graph[i].push_back(j);
                  graph[j].push_back(i);
              }
          }
          
          if(circle[i][1] + circle[i][2] >= M) {
              graph[i].push_back(circleCount+1);
              graph[circleCount+1].push_back(i);
          }
          if(circle[i][0] + circle[i][2] >= N) {
              graph[i].push_back(circleCount+2);
              graph[circleCount+2].push_back(i);
          }
          if(circle[i][1] <= circle[i][2]) {
              graph[i].push_back(circleCount+3);
              graph[circleCount+3].push_back(i);
          }
          if(circle[i][0] <= circle[i][2]) {
              graph[i].push_back(circleCount+4);
              graph[circleCount+4].push_back(i);
          }
      }
      
      vector<int> visited1 = bfs(circleCount+1,graph,circleCount+5); //top
      vector<int> visited2 = bfs(circleCount+2,graph,circleCount+5); //right
      
      if(visited1[circleCount+3] || visited1[circleCount+4] || visited2[circleCount+3] || visited2[circleCount+4]) {
          cout<<"NO"<<endl;
      }
      else {
          cout<<"YES"<<endl;
      }
    
  }
  return 0;

}
