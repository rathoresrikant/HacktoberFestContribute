// <preprocessing, query>
// <O(n^2), O(1)>

void rmq_preprocessing(int *a, int **M, int n)
{
    for(int i = 0; i < n; i++)
        M[i][i] = i;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[M[i][j - 1]] < a[j])
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = j;
        }
    }
}

int rmq_query(int l, int r, int *a, int **m)
{
	return a[m[l][r]];
}




// <O(n), O(sqrt(n))>

int block_size;
int* rmq_preprocessing(int *a, int n)
{
    int block_index = -1;
    block_size = sqrt(n);

    int *m = new int[block_size + 1];
    for(int i = 0; i < n; i++)
    {
        if(i % block_size == 0)
            m[++block_index] = i;

        if(a[i] < a[m[block_index]])
            m[block_index] = i;
    }

    return m;
}

int rmq_query(int a[N], vector<int> m, int l, int r)
{
    int min_index = l;
    while(l <= r && l % block_size != 0)
    {
        if(a[l] < a[min_index])
            min_index = l;
        l++;
    }

    while(l + block_size <= r)
    {
        if(a[m[l / block_size]] < a[min_index])
            min_index = m[l / block_size];
        l += block_size;
    }

    while(l <= r)
    {
        if(a[l] < a[min_index])
            min_index = l;
        l++;
    }

    return min_index;
}




// <O(nlog(n)), O(1)>

void rmq_preprocessing(int *a, int **m, int n)
{
    for(int i = 0; i < n; i++)
        m[i][0] = i;

    for(int j = 1; 1 << j <= n; j++)
        for(int i = 0; i + (1 << j) - 1 < n; i++)
            if(a[m[i][j - 1]] < a[m[i + (1 << (j - 1))][j - 1]])
                m[i][j] = m[i][j - 1];
            else
                m[i][j] = m[i + (1 << (j - 1))][j - 1];
}

int rmq_query(int *a, int **m, int l, int r)
{
    int k = log2(r - l + 1);
    if(a[m[l][k]] < a[m[r - (1 << k) + 1][k]])
        return m[l][k];
    else
        return m[r - (1 << k) + 1][k];
}


