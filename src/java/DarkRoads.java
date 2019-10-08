import java.util.*;
import java.io.*;


public class Main {
    static int n, m, total;

    static PriorityQueue<Aresta> pq = new PriorityQueue<Aresta>();

    static int[] f;

    static int find( int x ){
        if( f[x] == -1 ) {
            return x;
        }
        return f[x] = find( f[x] );
    }

    static int Kruskals(){
        f = new int[n];

        Arrays.fill( f, -1 );

        while( pq.size() != 0 ){
            Aresta e = pq.poll();
            int a = find( e.i );
            int b = find( e.j );
            if( a != b ){
                f[a] = b;
                total -= e.w;
            }
        }
        return total;
    }

    public static void main( String args[] ) throws IOException {
        BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
        PrintWriter pw = new PrintWriter( new BufferedWriter( new OutputStreamWriter( System.out ) ) );

        String input, listaAuxiliar[];
        int origem, destino, peso;

        while( (input = br.readLine()) != null ){

            if( input.equals("0 0") ) {
                break;
            }

            pq.clear();

            total = 0;
            listaAuxiliar = input.split(" ");
            n = Integer.parseInt( listaAuxiliar[0] );
            m = Integer.parseInt( listaAuxiliar[1] );

            for( int i=0; i<m; ++i ){
                listaAuxiliar = br.readLine().split(" ");

                origem = Integer.parseInt( listaAuxiliar[0] );
                destino = Integer.parseInt( listaAuxiliar[1] );
                peso = Integer.parseInt( listaAuxiliar[2] );

                pq.offer( new Aresta( origem, destino, peso ) );
                total += peso;
            }
            pw.println( Kruskals() );
        }

        pw.close();
    }
}
class Aresta implements Comparable<Aresta> {
    int i, j, w;

    public Aresta(int i, int j, int w ){
        this.i = i;
        this.j = j;
        this.w = w;
    }
    public int compareTo( Aresta outraAresta ){
        return w - outraAresta.w;
    }
}
