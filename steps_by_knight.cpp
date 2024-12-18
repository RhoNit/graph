// https://www.geeksforgeeks.org/problems/steps-by-knight5927/1

// we've chosen BFS here, because BFS would get the solution in minimum steps or iterations 

class Solution {
    public:
    // co-ordinates where knight can move from its current position
    vector<vector<int>> graph = {
        {-1, -2},
        {1, -2},
        {-1, 2},
        {1, 2},
        {2, -1},
        {2, 1},
        {-2, -1},
        {-2, 1}
    };
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N) {
	    int init_x = N-KnightPos[1], init_y = KnightPos[0]-1;
	    int target_x = N-TargetPos[1], target_y = TargetPos[0]-1;
	    
	    return solve(init_x, init_y, target_x, target_y, N);
	}
	
	int solve(int x, int y, int target_x, int target_y, int n) {
	    queue<pair<int, int>> q;
	    vector<vector<int>> visited(n, vector<int>(n, 0));
	    
	    q.push({x, y});
	    visited[x][y] = 1;
	    int count = 0;
	    
	    while(q.size() > 0) {
	        int size = q.size();
	        
	        while(size > 0) {
    	        auto front_elem = q.front();
    	        int x = front_elem.first;
    	        int y = front_elem.second;
    	        
    	        q.pop();
    	        
    	        if(x == target_x and y == target_y) return count;
    	        
    	        for(int i = 0; i < graph.size(); i++) {
    	            int new_x = x + graph[i][0];
    	            int new_y = y + graph[i][1];
    	            
                    // extra check: As soon as we find that target spot we will return instantly
                    // no need to store it inside `visited` array
                    // but remember to increment the step `count`
                    // as we are handling it outside the while loop
    	            if(new_x == target_x and new_y == target_y) return count+1;
    	            
    	            if(new_x >= 0 and new_x < n and new_y >= 0 and new_y < n and visited[new_x][new_y] != 1) {
    	                visited[new_x][new_y] = 1;
    	                q.push({new_x, new_y});
    	            }
    	        }
    	        
    	        size--;
	        }

	        count++;
	    }
	    
        // when we can't find the target spot, just return -1
	    return -1;
	}
};