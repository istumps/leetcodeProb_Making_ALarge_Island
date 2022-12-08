
class Solution {
public:
	 
    bool isSafe(int i, int j, vector<vector<bool> >&visited, vector<vector<int> >&grid){
        int n=grid.size();
        
        if(i>=0 && i<n && j>=0 && j<n && (grid[i][j]==1) && (!visited[i][j]) )return true;
        return false;
    }
	    int dfs( int i, int j, vector<vector<bool> >&visited, vector<vector<int> >&grid
             , vector<vector<int> >&indices, int islandNumber){
        if(isSafe(i,j,visited, grid)){
		
            visited[i][j]=true;
			
            indices[i][j]=islandNumber;
            
            int ans=1;
          
            ans+=dfs(i-1,j,visited,grid,indices,islandNumber); 
            ans+=dfs(i+1,j,visited,grid,indices,islandNumber); 
            ans+=dfs(i,j-1,visited,grid,indices,islandNumber); 
            ans+=dfs(i,j+1,visited,grid,indices,islandNumber); 
            return ans;
        }
        return 0;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool> >visited(n, vector<bool>(n,false));
        vector<vector<int> >indices(n, vector<int>(n,-1));
        unordered_map<int,int> um;
        int islandNumber=0, countOfZeroes=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( (grid[i][j]==1) && (!visited[i][j]) ){
                    int tmp=dfs(i,j,visited,grid,indices,islandNumber);
                    um[islandNumber]=tmp;
                    islandNumber++;
                }
                else if(grid[i][j]==0)countOfZeroes++;
            }
        }
        if(countOfZeroes==0)return n*n;
		        int ii[4]={-1,+1,0,0};
        int ij[4]={0,0,-1,+1};
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int tmp=1;
                    unordered_set<int> st;
                    
                    for(int k=0;k<4;k++){
                        int ci=i+ii[k], cj=j+ij[k];
                        
                        if(ci>=0 && ci<n && cj>=0 && cj<n){
                            if(grid[ci][cj]==1){
                                int indx=indices[ci][cj];
                                if(st.find(indx)==st.end()){
                                    tmp+=um[indx];
                                    st.insert(indx);
                                }
                            }
                        }
                    }
        
                    if(tmp>ans)ans=tmp;
                }
            }
        }
        return ans;
    }
};