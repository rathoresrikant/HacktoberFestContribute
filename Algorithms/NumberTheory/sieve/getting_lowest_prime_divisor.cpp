int isPrime[n];

for ( int j = 2; j < n; j++ )
	isPrime[j] = j;
for ( int j = 2; j * j < n; j++ )
	if ( isPrime[j] == j )
		for ( int i = j * j; i < n; i += j )
        	isPrime[i] = min( j, isPrime[i] );
