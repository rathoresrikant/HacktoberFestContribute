int modpow(int a, int b, int c)
{
    int ans = 1;
    while(b)
    {
        if(b & 1)
            ans = ((long long) ans * a) % c;

        a = ((long long) a * a) % c;
        b /= 2;
    }
    return ans;
}
