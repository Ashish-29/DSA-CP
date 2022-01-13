#include <bits/stdc++.h>
#define N 4

int ld[30] = { 0 };
int rd[30] = { 0 };
int cl[30] = { 0 };

bool solveNQUtil(int board[N][N], int col){
	if (col >= N) return true;

	for (int i = 0; i < N; i++) {
        if ((ld[i - col + N - 1] != 1 && rd[i + col] != 1) && cl[i] != 1) {
			board[i][col] = 1;
			ld[i - col + N - 1] = rd[i + col] = cl[i] = 1;

			if (solveNQUtil(board, col + 1)) return true;

			board[i][col] = 0; 
			ld[i - col + N - 1] =rd[i + col] = cl[i] = 0;
		}
	}
	return false;
}

int main(){
	int board[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };

	if (solveNQUtil(board, 0)){
        for (int i = 0; i < N; i++) {
		    for (int j = 0; j < N; j++)
		    	printf(" %d ", board[i][j]);
		    printf("\n");
        }
	}
    else printf("Solution does not exist");

	return 0;
}

