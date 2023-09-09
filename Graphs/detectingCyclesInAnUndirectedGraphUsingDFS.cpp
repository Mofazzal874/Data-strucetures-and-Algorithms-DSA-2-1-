#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

//this algorithm finds if is there any cycles in an undirected graph using the DFS algorithm 
// this algorithm assumes that- 
// 01.the graph is undirected
// 02.is not 0 indexed

// IDEA:
// Use DFS from every unvisited node. Depth First Traversal can be used to detect a cycle in a Graph.
//  There is a cycle in a graph only if there is a back edge present in the graph. A back edge is an 
//  edge that is indirectly joining a node to itself (self-loop) or one of its ancestors in the tree
//   produced by DFS. 
// To find the back edge to any of its ancestors keep a visited array and if there is a back edge to 
// any visited node then there is a loop and return true.



// special case: 
//  in case of like u--v  , this can also be treated as a cycle, because you can go from v to u .To avoid this case , 
//  we need to remember the parent of every exploring node. if parent == it , then it is not a cycle , go to another neighbour



bool modDFS(vector<vector<int>> &adjL , vector<int> & vis , int n , int v , int parent){



    vis[v] = 1; 
    for(auto neighbour:adjL[v]){
        if(vis[neighbour]== 0){
            if(modDFS(adjL , vis ,n, neighbour , v)) return true   ;

        } 
        
        else if(neighbour!= parent) return true;  
    }
    return false ; 


}



//this is the starter function , this function will call the modified dfs function for every node
bool anyCycles(vector<vector<int>> &adjL , int n ){

    vector<int> visited(n+1) ; 
    for(int v = 1 ; v<= n ; v++){
        if(visited[v]==0) {
            if(modDFS(adjL , visited , n  , v , -1)) return true ;
        } 
    }
    return false ; 
}



int32_t main(){


    int nodes , edges ; cin>>nodes>>edges ; 
    vector<vector<int>> adjL(100) ;
    for(int i =0 ; i < edges ; i++){
        int u , v ; cin>>u>>v ; 
        adjL[u].push_back(v) ;
         adjL[v].push_back(u) ;
    }
    //enter the source node: 
    int s ; cin>>s ; 
    if(anyCycles(adjL,nodes)) cout<<"Cycle found\n" ;
    else cout<<"No cycle\n" ;

    

 
}