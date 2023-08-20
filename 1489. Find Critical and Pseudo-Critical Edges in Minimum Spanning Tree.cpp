class Solution {
public:
    int n;
    void makeset(vector<int> &parent, vector<int> &rank, int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findParent(vector<int> &parent, int node)
    {
        if (parent[node] == node)
            return node;
        
        return parent[node] = findParent(parent, parent[node]);
    }

    void unionset(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        u = findParent(parent, u);
        v = findParent(parent, v);

        if (rank[u] < rank[v])
            parent[u] = v;
        
        else if (rank[u] > rank[v])
            parent[v] = u;
        else
            parent[u] = v;
            rank[v]++;
    }


    int kruskal(vector<vector<int>>& edges, int exclude, int include){
        // int n = edges.size();
        vector<int> parent(n);
        vector<int> rank(n);
        makeset(parent, rank, n);

        int maxweight = 0;

        if(include != -1){
            int u = findParent(parent, edges[include][0]);
            int v = findParent(parent, edges[include][1]);
            int w = edges[include][2];

            maxweight += w;
            unionset(u, v, parent, rank);
        }

        for (int i = 0; i < edges.size(); i++)
        {   
            if(i == exclude) 
                continue;

            int u = findParent(parent, edges[i][0]);
            int v = findParent(parent, edges[i][1]);
            int w = edges[i][2];

            if (u != v)
            {
                maxweight += w;
                unionset(u, v, parent, rank);
            }
        }

        // Koi 2 aese component jinke parent hi different ho, means 2 alg alg MST hai yaha, combine nhi
        for(int i=1; i<n; i++){
            if(findParent(parent, i) != findParent(parent, 0))
                return INT_MAX;
        }

        return maxweight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int N, vector<vector<int>>& edges) {
        n = N;
        for(int i=0; i<edges.size(); i++)
            edges[i].push_back(i);
        

        sort(edges.begin(), edges.end(), [&](vector<int>&a, vector<int>&b){
            return a[2]<b[2];
        });

        int mst_weight = kruskal(edges, -1, -1); // (vector, exclude, include)

        vector<int> critical, pseudo_critical;
        for(int i=0; i<edges.size(); i++){

            if(kruskal(edges, i, -1) > mst_weight) // skip i
                critical.push_back(edges[i][3]);
            else if(kruskal(edges, -1, i) == mst_weight) // take i;
                pseudo_critical.push_back(edges[i][3]);
        }

        return {critical, pseudo_critical};
    }   
};