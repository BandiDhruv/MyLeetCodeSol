class DisjointSet
{
public:
    vector<int> parent,size;
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int findUpar(int node)
    {
        if(parent[node]==node)return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionBySize(int u,int v)
    {
        int pu=findUpar(u);
        int pv=findUpar(v);
        if(pu==pv)return ;
        if(size[pu]<size[pv])
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution {
private:
    bool isValid(int r,int c,int n,int m)
    {
        return (r<n && c<m && r>=0 && c>=0);
    }
public:

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        DisjointSet ds(n*m);
        // vector<vector<int>> vis(n,vector<int>(m,0));
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)continue;
                for(int k=0;k<4;k++)
                {
                    int nr=i+dx[k];
                    int nc=j+dy[k];
                    if(isValid(nr,nc,n,m) && grid[nr][nc]==1)
                    {
                        int nodenum=i*n+j;
                        int adjnodenum=nr*n+nc;
                        ds.unionBySize(nodenum,adjnodenum);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)continue;
                set<int> temp;
                for(int k=0;k<4;k++)
                {
                    int nr=i+dx[k];
                    int nc=j+dy[k];
                    if(isValid(nr,nc,n,m) && grid[nr][nc]==1)
                    {
                        temp.insert(ds.findUpar(nr*n+nc));
                    }
                }
                int size=0;
                for(auto it:temp)
                {
                    size+=ds.size[it];
                }
                ans=max(ans,size+1);
            }
        }
        for(int i=0;i<n*n;i++)
        {
            ans=max(ans,ds.size[ds.findUpar(i)]);
        }
        return ans;
    }
};