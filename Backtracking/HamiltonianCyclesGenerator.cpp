#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("hamCycle.in");
ofstream fout("hamCycle.out");

#define MAX_VERTICES 1001

int matrix[MAX_VERTICES][MAX_VERTICES], numVer;
int path[MAX_VERTICES], usedVertices[MAX_VERTICES];

bool hasHamCycles = false;

void showHamCycle()
{
    hasHamCycles = true;
    fout<<'{';
    for(int i = 1; i <= numVer; i++)
        fout<<path[i]<<' ';
    fout<<path[1]<<"}\n";
}

void hamCycle(int k)
{
    for(int i = 1; i <= numVer; i++)
        if(!usedVertices[i])
            if(matrix[i][path[k-1]] || k == 1)
            {
                path[k] = i;
                usedVertices[i]++;
                if(k == numVer)
                {
                    if(matrix[path[1]][path[numVer]])
                        showHamCycle();
                }
                else
                    hamCycle(k+1);
                usedVertices[i]--;
            }
}

int main()
{
    fin>>numVer;
    int x, y;
    while(fin>>x>>y)
        matrix[x][y] = matrix[y][x] = 1;
    hamCycle(1);
    if(!hasHamCycles)
        fout<<"No hamiltonian cyce could be generated\n";
    return 0;
}
