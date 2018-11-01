#include <iostream>
#include <cmath>
using namespace std;


void print(int q[]){

	static int solutionNum = 1;
	cout<<"\n"<<"Solution # "<< solutionNum<<endl;

	int i,j,k,l;
	typedef char box [10][14];
	box bb, wb, bq, wq, *board[8][8];

	for(i = 0; i < 10 ; i++){
		for(j = 0; j < 14; j++){

			//Black board or white queen
			bb[i][j] = char(219);
			if( (i==1 && (j==6 || j==7)) ||
				(i==2 && (j==5 || j==8)) ||
				(i==3 && (j==5 || j==6 || j==7 || j==8)) ||
				(i==4 && (j==6 || j==7)) ||
				(i==5 && (j==6 || j==7)) ||
				(i==6 && (j==5 || j==6 || j==7 || j==8)) ||
				(i==7 && (j==4 || j==5 || j==6 || j==7 || j==8 || j==9)) ||
				(i==8 && (j==4 || j==5 || j==6 || j==7 || j==8 || j==9))

			) 	wq[i][j] = ' ';
			else
				wq[i][j] = char(219);

			//White board or black queen
			wb[i][j] = ' ';
			if( (i==1 && (j==6 || j==7)) ||
				(i==2 && (j==5 || j==8)) ||
				(i==3 && (j==5 || j==6 || j==7 || j==8)) ||
				(i==4 && (j==6 || j==7)) ||
				(i==5 && (j==6 || j==7)) ||
				(i==6 && (j==5 || j==6 || j==7 || j==8)) ||
				(i==7 && (j==4 || j==5 || j==6 || j==7 || j==8 || j==9)) ||
				(i==8 && (j==4 || j==5 || j==6 || j==7 || j==8 || j==9))

			) 	bq[i][j] = char(219);
			else
				bq[i][j] = ' ';
		}
	}

	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			if((i+j) % 2 == 0){
				if(j == q[i])
					board[i][j] = &bq;
				else
					board[i][j] = &wb;
			}
			else
				if(j == q[i])
					board[i][j] = &wq;
				else
				board[i][j] = &bb;
		}
	}

	//Upper border
	cout<<"  ";
	for(i = 0; i < 112 ; i++)
		cout<<'_';
	cout<<endl;

	//Board
	for(i = 0; i < 8; i++){
		for(k = 0; k < 10; k++){
			// left border
			cout<<" "<<char(179);
			for(j = 0; j < 8 ; j++){
				for(l = 0; l < 14; l++){
					//i+j odd/even determines color... k,l print out all elements from 'color' array
					cout<<(*board[i][j])[k][l]; 
				}
			}
			//At the end of ith 'k' row, print a bar then go to next iteration
			cout<<char(179)<<endl;
		}
	}
	cout<<"  ";
	for(i = 0; i < 112 ; i++){
		cout<<char(196);
	}
	cout<<"\n\n\n";

	for(i = 0; i < 112 ; i++){
		cout<<"_";
	}
	solutionNum++;
}

bool ok(int q[], int c) {
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
         return false;
   return true;
}

int main() {
   int q[8] = {};
   int c = 0;
   while (c >= 0) {
      if (c == 7) {
         print(q);
         --c;
      }
      else
         q[++c] = -1;
      while (c >= 0) {
         ++q[c];
         if (q[c] == 8)
            --c;
         else if (ok(q, c))
            break;
      }
   }
   return 0;
}
