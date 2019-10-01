

from collections import defaultdict
graph=defaultdict(list)


def dfs_for_vertice(v,visited):
	visited[v]=True
	#print(str(v)+" ") 	
	print(v,end='->')
    
	for i in graph[v]:
		if visited[i]==False:	
			dfs_for_vertice(i,visited)

def BFS(self, s): 
  
       
        visited = [False] * (len(self.graph)) 
  
        
        queue = [] 
  

        queue.append(s) 
        visited[s] = True
  
        while queue: 
  
            s = queue.pop(0) 
            print (s, end = " ") 
  
            for i in self.graph[s]: 
                if visited[i] == False: 
                    queue.append(i) 
                    visited[i] = True


def dfs(graph,v):
	visited=[False]*(len(graph))
	dfs_for_vertice(v,visited)
	print(end='\b')

	

def addEdge(u,v):
	graph[u].append(v)

addEdge(0,1)
addEdge(0,2)
addEdge(1,2)
addEdge(2,0)
addEdge(2,3)
addEdge(3,3)


for i in range(len(graph)):
	dfs(graph,i)
	print('\b\b')
	print("\n")
