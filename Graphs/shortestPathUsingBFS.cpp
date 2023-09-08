#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

//this BFS algorithm assumes that , the graph-
// 01.unweighted graph
//02.undirected graph


//as we are trying to print the path , we need to modify the BFS algorithm 
void modBFS(int n , vector<vector<int>> &adjL , int s , int d ){

    vector<int> visited(n+1,0) ; 
    vector<int> dist(n+1 , INT_MAX) ;
    vector<int> parent(n+1 , -1) ;
    queue<int> q ; 
    visited[s] = 1 ; 
    dist[s] = 0 ; 
    q.push(s) ; 
    int flag = 0 ; 
    while(!q.empty()){
        int u = q.front() ; 
        q.pop() ; 
        for(auto v : adjL[u]){
            if(visited[v] ==0){
                visited[v]=1 ;
                dist[v] = dist[u]+1 ; 
                parent[v] = u ; 
                q.push(v) ;
            }
           
        }
    }
    if(dist[d] == INT_MAX) cout<<"it is not possible to go from "<<s<<" to "<<d<<"\n" ; 
    else {
        cout<<"Total distance from "<<s<<" to "<<d<<" is "<<dist[d]<<endl;
        vector<int>path ; 
        int bt = d ; 
        path.push_back(bt); 
        while(parent[bt]!=-1){
            path.push_back(parent[bt]) ;
            bt = parent[bt] ; 
        }
        reverse(path.begin(), path.end()) ; 
        for(auto it: path) cout<<it<<" " ;

    }

}

int32_t main(){

    

    int nodes , edges ; cin>>nodes>>edges ; 
    vector<vector<int>> adjL(100) ;
    for(int i =0 ; i < edges ; i++){
        int u , v ; cin>>u>>v ; 
        adjL[u].push_back(v) ;
         adjL[v].push_back(u) ;
    }
    //"Enter source: ";   
    int s ; cin>>s; 
    //"Enter Destination: " ; 
    int d ; cin>>d ; 
    modBFS(nodes , adjL , s , d) ;
}


// input:
// 8 10
// 2 3
// 2 1
// 1 4
// 4 8
// 4 5
// 8 7
// 8 5
// 5 7
// 5 6
// 6 7
// 1 8
// Total distance from 1 to 8 is 2
// 1 4 8