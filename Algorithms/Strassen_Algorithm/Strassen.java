import java.util.Random;

public class Strassen
{
    public static void main(String[] args)
    {     
        test(); 
    }
    
    public static void test()
    {
        float[][] A = new float[5][5];
        float[][] B = new float[5][5];
        randomize(A);
        randomize(B);
        
        System.out.println("Matrix A:");
        printMatrix(A);
        System.out.println("Matrix B:");
        printMatrix(B);
        
        float[][] naive = naiveMult(A, B);
        float[][] divideAndConquer = divideAndConquerMult(A, B);
        float[][] strassen = strassenMult(A, B);

        System.out.println("Naive Method Result:");
        printMatrix(naive);
        System.out.println("Divide and Conquer Result:");
        printMatrix(divideAndConquer);
        System.out.println("Strassen's Method Result:");
        printMatrix(strassen);
    }
    
    public static float[][] naiveMult(float[][] M1, float[][] M2)
    {
        float[][] mult = new float[M1.length][M2[0].length];
        
        for(int i = 0; i < M1.length; i++)
        {
            for(int j = 0; j < M2[0].length; j++)
            {
                for(int k = 0; k < M2.length; k++)
                {
                    mult[i][j] += M1[i][k] * M2[k][j];
                }
            }
        }
        
        return mult;
    }
    
    public static float[][] divideAndConquerMult(float[][] m1, float[][] m2)
    {
        // In order to apply this method, matrices should be 2^n x 2^n,
        // if they are not, we need to add padding to fit them into
        // minimum 2^n x 2^n matrices.
        
        int n = getPadSize(m1, m2);
        float[][] M1 = addPadding(m1, n);
        float[][] M2 = addPadding(m2, n);
        float[][] R = new float[n][n];
        
        if(n == 1)
        {
            R[0][0] = M1[0][0] * M2[0][0];
            return R;
        }
        
        // nd2 => n divided by 2
        int nd2 = n / 2;
        
        float[][] A = new float[nd2][nd2];
        float[][] B = new float[nd2][nd2];
        float[][] C = new float[nd2][nd2];
        float[][] D = new float[nd2][nd2];
        float[][] E = new float[nd2][nd2];
        float[][] F = new float[nd2][nd2];
        float[][] G = new float[nd2][nd2];
        float[][] H = new float[nd2][nd2];

        // Split first matrix
        split(M1, A, 0, 0);
        split(M1, B, 0, nd2);
        split(M1, C, nd2, 0);
        split(M1, D, nd2, nd2);
        
        // Split second matrix
        split(M2, E, 0, 0);
        split(M2, F, 0, nd2);
        split(M2, G, nd2, 0);
        split(M2, H, nd2, nd2);
        
        /*
            R11 = AE + BG
            R12 = AF + BH
            R21 = CE + DG
            R22 = CF + DH
        */
        
        float[][] R11 = add(divideAndConquerMult(A, E), divideAndConquerMult(B, G));
        float[][] R12 = add(divideAndConquerMult(A, F), divideAndConquerMult(B, H));
        float[][] R21 = add(divideAndConquerMult(C, E), divideAndConquerMult(D, G));
        float[][] R22 = add(divideAndConquerMult(C, F), divideAndConquerMult(D, H));

        // Merge submatrices
        merge(R, R11, 0, 0);
        merge(R, R12, 0, nd2);
        merge(R, R21, nd2, 0);
        merge(R, R22, nd2, nd2);
        
        // We need to remove padding at the end.
        R = removePadding(R, m1.length, m2[0].length);

        return R;
    }
    
    public static float[][] strassenMult(float[][] m1, float[][] m2)
    {
        // In order to apply strassen's method, matrices should be 2^n x 2^n,
        // if they are not, we need to add padding to fit them into
        // minimum 2^n x 2^n matrices.
        
        int n = getPadSize(m1, m2);
        float[][] M1 = addPadding(m1, n);
        float[][] M2 = addPadding(m2, n);
        float[][] R = new float[n][n];
        
        if(n == 1)
        {
            R[0][0] = M1[0][0] * M2[0][0];
            return R;
        }
        
        // nd2 => n divided by 2
        int nd2 = n / 2;
        
        float[][] A = new float[nd2][nd2];
        float[][] B = new float[nd2][nd2];
        float[][] C = new float[nd2][nd2];
        float[][] D = new float[nd2][nd2];
        float[][] E = new float[nd2][nd2];
        float[][] F = new float[nd2][nd2];
        float[][] G = new float[nd2][nd2];
        float[][] H = new float[nd2][nd2];

        // Split first matrix
        split(M1, A, 0, 0);
        split(M1, B, 0, nd2);
        split(M1, C, nd2, 0);
        split(M1, D, nd2, nd2);
        
        // Split second matrix
        split(M2, E, 0, 0);
        split(M2, F, 0, nd2);
        split(M2, G, nd2, 0);
        split(M2, H, nd2, nd2);
        
        /*  Strassen's formula
            P1 = A * (F - H)
            P2 = (A + B) * H
            P3 = (C + D) * E
            P4 = D * (G - E)
            P5 = (A + D) * (E + H)
            P6 = (B - D) * (G + H)
            P7 = (A - C) * (E + F)
        */
        
        float[][] P1 = strassenMult(A, sub(F, H));
        float[][] P2 = strassenMult(add(A, B), H);
        float[][] P3 = strassenMult(add(C, D), E);
        float[][] P4 = strassenMult(D, sub(G, E));
        float[][] P5 = strassenMult(add(A, D), add(E, H));
        float[][] P6 = strassenMult(sub(B, D), add(G, H));
        float[][] P7 = strassenMult(sub(A, C), add(E, F));
        
        /*
            Strassen's formula
            R11 = P5 + P4 - P2 + P6
            R12 = P1 + P2
            R21 = P3 + P4
            R22 = P1 + P5 - P3 - P7
        */
        
        float[][] R11 = add(sub(add(P5, P4), P2), P6);
        float[][] R12 = add(P1, P2);
        float[][] R21 = add(P3, P4);
        float[][] R22 = sub(sub(add(P1, P5), P3), P7);

        // Merge submatrices
        merge(R, R11, 0, 0);
        merge(R, R12, 0, nd2);
        merge(R, R21, nd2, 0);
        merge(R, R22, nd2, nd2);
        
        // We need to remove padding at the end.
        R = removePadding(R, m1.length, m2[0].length);

        return R;
    }
    
    private static int getPadSize(float[][] M1, float[][] M2)
    {
        // In order to add padding, we need to know which is maximum.
        int max = Math.max(Math.max(M1.length, M1[0].length), M2[0].length);
        
        // Find minimum matrix that fits which should be 2^n.
        // Because we can only apply to 2^n sized matrices.
        int n = 0;
        while((1 << n) < max)
        {      
            n++;
        }
        
        n = 1 << n;
        return n;
    }
    
    private static float[][] addPadding(float[][] M, int n)
    {
        // Padding size and the matrix size are equal.
        // Don't need to add padding.
        if(M.length == n && M[0].length == n)
        {
            return M;
        }
                
        float[][] p = new float[n][n];
        for(int i = 0; i < M.length; i++)
        {
            for(int j = 0; j < M[0].length; j++)
            {
                p[i][j] = M[i][j];
            }
        }
        
        return p;
    }
    
    private static float[][] removePadding(float[][] M, int r, int c)
    {
        // There is no padding to remove.
        if(M.length == r && M[0].length == c)
        {
            return M;
        }

        float[][] rem = new float[r][c];
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                rem[i][j] = M[i][j];
            }
        }
        
        return rem;
    }
    
    private static void split(float[][] P, float[][] C, int i, int j)
    {
        for(int k = 0; k < C.length; k++)
        {
            for(int l = 0; l < C.length; l++)
            {
                C[k][l] = P[k + i][l + j];
            }
        }
    }
    
    private static void merge(float[][] P, float[][] C, int i, int j)
    {
        for(int k = 0; k < C.length; k++)
        {
            for(int l = 0; l < C.length; l++)
            {
                P[k + i][l + j] = C[k][l];
            }
        }
    }
    
    public static float[][] add(float[][] M1, float[][] M2)
    {
        float[][] sum = new float[M1.length][M1[0].length];
        
        for(int i = 0; i < M1.length; i++)
        {
            for(int j = 0; j < M1[0].length; j++)
            {
                sum[i][j] = M1[i][j] + M2[i][j];
            }
        }
        
        return sum;
    }
    
    public static float[][] sub(float[][] M1, float[][] M2)
    {
        float[][] sub = new float[M1.length][M1[0].length];
        
        for(int i = 0; i < M1.length; i++)
        {
            for(int j = 0; j < M1[0].length; j++)
            {
                sub[i][j] = M1[i][j] - M2[i][j];
            }
        }
        
        return sub;
    }
    
    public static void randomize(float[][] M)
    {
        Random rnd = new Random();
        
        for(int i = 0; i < M.length; i++)
        {
            for(int j = 0; j < M[0].length; j++)
            {
                M[i][j] = rnd.nextFloat() * 10f;
            }
        }
    }
    
    public static void printMatrix(float[][] M)
    {
        String res = "";
        
        for(int i = 0; i < M.length; i++)
        {
            res += "[";
            for(int j = 0; j < M[0].length; j++)
            {    
                res += String.format("%.1f,\t", M[i][j]);
            }
            res = res.substring(0, res.length() - 2);
            res += "]\n";
        }
        
        System.out.println(res);
    }
}

