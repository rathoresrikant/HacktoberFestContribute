
//e is the number of eggs and f is the number of floors
int solve(int e,int f){
	if(f==0||f==1||e==1)
	return f;
	int mn=INT_MAX;
	for(int k=1;k<=f;k++){
		int temp=1+max(solve(e-1,k-1),solve(e,f-k));
		int mn=min(mn,temp);
	}
	return mn;
}
