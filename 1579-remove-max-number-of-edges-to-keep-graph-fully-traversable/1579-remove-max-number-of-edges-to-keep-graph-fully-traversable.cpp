class Union {
private:
    vector<int> parent, size;
public:
    int components;
    Union(int n) {
        components = n;
        parent.resize(n + 1);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        size.resize(n + 1, 1);
    }

    int find(int node) {
        return node == parent[node] ? node : parent[node] = find(parent[node]);
    }

    bool unionBySize(int u, int v) {
        int pu = find(u), pv = find(v);

        if(pu == pv) return false;

        if(size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        
        components--;
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        Union a(n), b(n);
        int unused = 0;

        for(auto i: edges) {
            if(i[0] == 3) {
                bool merged = (a.unionBySize(i[1], i[2]) & b.unionBySize(i[1], i[2]));
                if(!merged) unused++; 
            }
        }

        for(auto i: edges) {
            if(i[0] == 1) {
                bool merged = a.unionBySize(i[1], i[2]);
                if(!merged) unused++;
            } else if(i[0] == 2){
                bool merged = b.unionBySize(i[1], i[2]);
                if(!merged) unused++;
            }
        }


        if(b.components != 1 or a.components != 1) return -1;

        return unused;        
    }
};