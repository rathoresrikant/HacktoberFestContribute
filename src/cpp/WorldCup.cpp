#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int node[100], lista[100];

int find(int a) {
  if (a == node[a]) return a;
  return node[a] = find(node[a]);
}

bool join(int a, int b) {
  a = find(a), b = find(b);
  
  if (a == b) return false;
  
  if (lista[a] > lista[b]) swap(a,b);
  node[a] = b;
  if (lista[a] == lista[b]) lista[b]++;
  return true;
}

int main() {
  int ncidades, nferrovias, nrodovias;

  scanf("%d %d %d", &ncidades, &nferrovias, &nrodovias);

  vector <pair <int, pair <int, int> > > rodovias;

  for (int k = 0; k < nferrovias + nrodovias; k++) {
	  
	int origem, destino, peso;
	scanf("%d %d %d", &origem, &destino, &peso), origem--, destino--;
	
	rodovias.push_back(make_pair(peso, make_pair(origem, destino)));
  }

  sort(rodovias.begin(), rodovias.begin() + nferrovias);
  sort(rodovias.begin() + nferrovias, rodovias.end());

  for (int i = 0; i < ncidades; i++) {
	node[i] = i;
	lista[i] = 0;
  }

  pair <int, int> soma(0, 0);

  for (int j = 0; j < (int)rodovias.size(); j++) {
	int a = rodovias[j].second.first;
	int b = rodovias[j].second.second;
	int c = rodovias[j].first;
	
	if (join(a, b)) {
	  soma.first++;
	  soma.second += c;
	}
  }

  printf("%d\n", soma.second);

  return 0;
}
