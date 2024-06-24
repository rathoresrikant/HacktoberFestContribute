import java.io.*;

public class Main {

    static int MAX = 999999999;
    static int g[][] = new int [1010][1010];
    static int N;
    static int vertices;

    static int dijkstra(int origem, int destino) {
        int minimo, atual;
        int passou[] = new int [1010];
        int pred[] = new int [1010];
        int custo[] = new int [1010];

        for (int i=1; i<=vertices;i++) {
            pred[i]=-1;
            custo[i]=MAX;
            passou[i]=0;
        }
        custo[origem] = 0;
        atual = origem;
        while (atual != destino) {
            for (int i=1; i<=vertices;  i++) {
                if (custo[i] > custo[atual] + g[atual][i]) {
                    custo[i] = custo[atual] + g[atual][i];
                }
            }
            minimo = MAX;
            passou[atual]=1;
            for (int i=1; i<=vertices; i++) {
                if ((custo[i]<minimo) && (passou[i]!=1)) {
                    minimo = custo[i];
                    atual = i;
                }
            }
            if (minimo == MAX) {
                return MAX;
            }
        }
        return custo[destino];
    }

    public static void main(String[] args) throws IOException {
        int arestas, origem, destino, peso,consultas;

        Reader input = new Reader();

        vertices = input.nextInt();
        arestas = input.nextInt();

        while (vertices!=0 || arestas!=0) {

            for (int i=1; i<=vertices; i++) {
                for (int j=1;j<=vertices;j++) {
                    g[i][j]=MAX;
                }
            }
            for (int i=1; i<=arestas; i++) {
                origem = input.nextInt();
                destino = input.nextInt();
                peso = input.nextInt();
                g[origem][destino]=peso;
                if (g[destino][origem]!=MAX) {
                    g[origem][destino] = 0;
                    g[destino][origem] = 0;
                }
            }
            consultas = input.nextInt();
            for (int i=1; i<=consultas;i++) {
                origem = input.nextInt();
                destino = input.nextInt();
                if (dijkstra(origem,destino)== MAX) {
                    System.out.println("Nao e possivel entregar a carta");
                } else {
                    System.out.println(dijkstra(origem,destino));
                }
            }
            vertices = input.nextInt();
            arestas = input.nextInt();
            System.out.println("");

        }
    }

     static class Reader
    {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader()
        {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException
        {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException
        {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1)
            {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do
            {
                ret = ret * 10 + c - '0';
            }  while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException
        {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException
        {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');

            if (c == '.')
            {
                while ((c = read()) >= '0' && c <= '9')
                {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException
        {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException
        {
            if (din == null)
                return;
            din.close();
        }
    }


}
