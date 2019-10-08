#include <cstdio>
#include <algorithm>
#define MAXN 510
#define MAXM 100000

using namespace std;

int vertices,arestas;

int pai[MAXN];
int peso[MAXN];

int find(int x){ 
    if( pai[x] == x ) return x;
    return pai[x] = find(pai[x]);
}


int join(int a,int b){ 
    a = find(a);
    b = find(b);
    
    if(peso[a] < peso[b]){ 
		pai[a] = b;
    } else if(peso[b] < peso[a]) { 
		pai[b] = a;
    } else{
        pai[a] = b;
        peso[b]++;
    }
    
}

struct aresta{
    int x;
    int y;
    int peso;
};

bool comp(aresta a, aresta b){ 
	    return a.peso < b.peso;
}

aresta listarestas[MAXM];

int main(){
    
    scanf("%d %d",&vertices, &arestas);
    
    for(int i = 1; i<=vertices; i++) pai[i] = i;
    
    for(int i = 1;i<=arestas;i++){
       
        int origem,destino,peso;
        
        scanf("%d %d %d",&origem,&destino,&peso);
        listarestas[i].x   = origem;
        listarestas[i].y   = destino;
        listarestas[i].peso = peso;
    }
    
    sort(listarestas+1,listarestas+arestas+1,comp); 
    
    int soma = 0;
    
    for(int i = 1; i<=arestas; i++){
        
        if(find(listarestas[i].x) != find(listarestas[i].y)) {
			
            soma += listarestas[i].peso;
            join(listarestas[i].x, listarestas[i].y);
            
        }
        
    }
    
    printf("%d\n",soma);
    
    return 0;
}
