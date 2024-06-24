
//initialise dp table in main() with -1 
int dp[11][51];
//e is the number of eggs and f is the number of floors
int solve(int e,int f){
	if(f==0||f==1||e==1)
	return f;
	if(dp[e][f]!=-1)
	return dp[e][f];
	int mn=INT_MAX;
	for(int k=1;k<=f;k++){
		int down,up;
		if(dp[e-1][k-1]!=-1)
		down=dp[e-1][k-1];
		else{
			down=solve(e-1,k-1);
			dp[e-1][k-1]=down;
		}
		if(dp[e][f-k]!=-1)
		up=dp[e][f-k];
		else{
			up=solve(e-1,k-1);
			dp[e][f-k]=up;
		}
		int temp=1+max(up,down);
		int mn=min(mn,temp);
	}
	return dp[e][f]=mn;
}
