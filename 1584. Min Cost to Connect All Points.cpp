class Solution {
public:
    int Prims(vector<vector<pair<int,int>>>& adj, int n){

        vector<bool> inMST(n ,false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, 0}); // weight, currentNode;
        int mstSum = 0;
        while(!pq.empty()){

            auto top = pq.top();
            pq.pop();
            int weight = top.first;
            int parent =  top.second;

            if(inMST[parent])
                continue;
            
            mstSum += weight;
            inMST[parent] = true;

            for(auto& child: adj[parent]){

                int childWeight = child.second;
                int childNode =  child.first;

                if(inMST[childNode] == false){
                    pq.push({childWeight, childNode});
                }
            }
        }

        return mstSum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){

                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                adj[i].push_back({j, distance});
                adj[j].push_back({i, distance});
            }
        }

        return Prims(adj, n);
    }
};