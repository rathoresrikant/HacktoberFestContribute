/*https://www.spoj.com/problems/TOPOSORT*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	long int i,n,m,x,y;
	cin>>n>>m;
	vector < int >v[n+1];
	long ind[n+1];
	memset(ind,0,sizeof(ind));
	for(i=0;i<m;i++)
	  {
	  	 cin>>x>>y;
	  	 v[x].push_back(y);
	  	 ind[y]+=1;
	  }
	multiset < long > mu;
	for(i=1;i<n+1;i++)
	  {
	  	 if(ind[i]==0)
	  	   mu.insert(i);
	  }
	  vector <long >v1;
	while(mu.size()!=0)
	  {	 x = *mu.begin();
	  	  v1.push_back(x);
	  	  mu.erase(mu.begin());
	  	  for(i=0;i<v[x].size();i++)
	  	    {
	  	    	--ind[v[x][i]];
	  	    	if(ind[v[x][i]]==0)
	  	    	  mu.insert(v[x][i]);
	  	    }
	  }
	for(i=0;i<v1.size();i++)
	  {
	  	 cout<<v1[i]<<" ";
	  }
	return 0;
}
