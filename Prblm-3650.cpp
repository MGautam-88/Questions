class Solution {
public:
    vector<vector<pair<int,int>>> e;
    int djk(int n){
        vector<bool> vis(n,false);
        vector<int> dist(n,1e9);

        priority_queue<pair<int,int>> q;
        q.push({0,0});
        dist[0]=0;//distance of starting node
        while(!q.empty()){
            int u = q.top().second;
            q.pop();
            if(vis[u])continue;
            vis[u]=true;

            for(auto [v,w]:e[u]){
                if(dist[u]+w < dist[v]){
                    dist[v]=dist[u]+w;
                    q.push({-dist[v],v});
                }
            }
        }
        if(dist[n-1]==1e9)return -1;//not possible to reach
        return dist[n-1];
    }

    int minCost(int n, vector<vector<int>>& edges) {
        e.resize(n);

        for(auto ed : edges){
            int u= ed[0];
            int v= ed[1];
            int w= ed[2];
            e[u].push_back({v,w});
            e[v].push_back({u,2*w});
        }

        return djk(n);
    }
};
