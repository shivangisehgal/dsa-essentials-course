// Expected Output:
// 1-->0,2,
// 2-->1,3,
// 3-->4,2,5,
// 4-->0,3,5,
// 5-->4,3,

#include<bits/stdc++.h>
using namespace std;


class Graph{

	int V;
	list<int> *l;

public:
	Graph(int v){
		V = v;
		l = new list<int>[V];
	}

	void addEdge(int i,int j,bool undir=false){
		l[i].push_back(j);
		if(undir){
			l[j].push_back(i);
		}
	}

	void printAdjList(){
		//Iterate over all the rows
		for(int i=0;i<V;i++){
			cout<<i<<"-->";
			//every element of ith linked list
			for(auto node:l[i]){
				cout << node <<",";
			}
			cout <<endl;

		}
	}
	
	static bool comparitor(pair<int, int> a, pair<int, int> b)
	{
	    return a.second < b.second;
	}
	
	void topological_sort()
	{
	   //My method:
	   //vector<pair<int, int>> indegree(V);
	   
	   //for(int i = 0; i < V; i++)
	   //{
	   //    indegree[i].first = i;
	   //    indegree[i].second = 0;
	   //}
	   
	   // for(int i = 0; i < V; i++)
	   // {
	   //     for(auto nbr : l[i])
	   //     {
	   //         indegree[nbr].second ++;
	   //     }
	   // }
	    
	   //sort(indegree.begin(), indegree.end(), comparitor);
	    
	   // for(int i = 0; i < V; i++)
	   //{
	   //    cout << indegree[i].first << " ";
	   //}
	   
	   
	    vector<int> indegree(V, 0);
	    
	    for(int i = 0; i < V; i++)
	    {
	        for(auto nbr : l[i])
	        {
	            indegree[nbr]++;
	        }
	    }
	    
	    
	    queue<int> q;
	    
	    for(int i = 0; i < V; i++)
	    {
	        if(indegree[i] == 0)
	               q.push(i);
	    }
	    
	    
	    while(!q.empty())
	    {
	        int front = q.front();
	        
	        cout << front << " ";
	        
	        q.pop();
	        
	        
	        for(auto nbr : l[front])
	        {
	            indegree[nbr]--;
	            
	            if(indegree[nbr] == 0)
	                q.push(nbr);
	        }
	    }
	    
	    return;
	}
	

};

int main(){
	Graph g(6);
	g.addEdge(0,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(4,5);
	g.addEdge(1,4);
	g.addEdge(1,2);
	
// 	g.printAdjList();
// 	cout << endl;
	g.topological_sort();
	
	return 0;
}

