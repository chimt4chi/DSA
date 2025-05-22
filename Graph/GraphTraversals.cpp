#include<bits/stdc++.h>
using namespace std;
/**
 * DFS traversal on the Graph Rescursively
 * Inputs : Graph, Current/Source node/visited array
 */
void dfs(vector<int> graph[],int verticeSize,int currNode,bool visited[])
{
    if(visited[currNode])
        return;

    cout<<currNode<<" ";
    visited[currNode]=true;
    //Fetching neighbours of currNode
    for(int i=0;i<graph[currNode].size();i++)
    {
        int neighbor = graph[currNode][i];
        if(!visited[neighbor])
            dfs(graph,verticeSize,neighbor,visited);
    }
}

void dfsIterative(vector<int> graph[],int verticeSize,int source)
{
    stack<int> dfsStk;
    bool visited[verticeSize]={false};
    dfsStk.push(source);
    
    while(!dfsStk.empty())
    {
        int curr = dfsStk.top();//Fetching the first entered node from Stack
        dfsStk.pop();
        
        if(visited[curr]) continue;

        visited[curr]=true;
        cout<<curr<<" ";

        for(auto neighbor : graph[curr])
        {
            dfsStk.push(neighbor);            
        }
        
    }
    cout<<endl;
}

/**
 * BFS traversal on the Graph Iteratively
 * Inputs : Graph, Current/Source node/visited array
 */
void bfs(vector<int> graph[],int verticeSize,int source)
{
    queue<int> bfsQ;
    bool visited[verticeSize]={false};
    bfsQ.push(source);

    while(!bfsQ.empty())
    {
        int curr = bfsQ.front();//Fetching the first entered node from Queue
        bfsQ.pop();

        if(visited[curr]) continue;        

        visited[curr]=true;
            cout<<curr<<" ";
        
        for(auto neighbor : graph[curr])
        {
            bfsQ.push(neighbor);            
        }
    }
    cout<<endl;
}

int main()
{
    int V=5;
    vector<int> graph[V];//This is a Non-Weighted Graph

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(0);
    graph[2].push_back(1);
    graph[2].push_back(4);
    graph[3].push_back(1);
    graph[4].push_back(2);

    bool visited[V]={false};
    //cout<<endl;//To help observe output in debug mode(Uncomment)


    cout<<"DFS Traversal "<<endl;
    dfs(graph,V,0,visited);
    cout<<endl;
    cout<<"BFS Traversal "<<endl;
    bfs(graph,V,0);
    cout<<"DFS Traversal(Iterative) "<<endl;
    dfsIterative(graph,V,0);
    cout<<endl;
    
    return 0;
}