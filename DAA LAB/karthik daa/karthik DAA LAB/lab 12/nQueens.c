#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Function to check if a queen can be placed on board[row][col]
bool isSafe(int board[], int row, int col)
{
int i;
for (i = 0; i < row; i++)
{
if (board[i] == col || abs(board[i] - col) == abs(i - row))
{
return false;
}
}
return true;
}
// Function to print the solution
void printSolution(int board[], int n)
{
int i,j;
static int solutionNumber = 1;
printf("\nSolution %d:\n", solutionNumber++);
for (i = 0; i < n; i++)
{
for (j = 0; j < n; j++)
{
if (board[i] == j)
{
printf("Q ");
} else
{
printf(". ");
}
}
printf("\n");
}
}
// Recursive function to solve the n-Queens problem using backtracking
bool solveNQueens(int board[], int row, int n)
{
if (row == n)
{
printSolution(board, n);
return true; // Found a solution
}
int col;
bool res = false;
for ( col = 0; col < n; col++)
{
if (isSafe(board, row, col))
{
board[row] = col;
res = solveNQueens(board, row + 1, n) || res; // Check if there are more solutions.
//if you wanted to only find one solution, you could return true here instead.
}
}
return res;
}
int main()
{
int n;
printf("Enter the value of n: ");
scanf("%d", &n);
if (n <= 0)
{
printf("Invalid input. n must be a positive integer.\n");
return 1;
}
int *board = (int *)malloc(n * sizeof(int));
if (board == NULL) {
printf("Memory allocation failed.\n");
return 1;
}
if (!solveNQueens(board, 0, n))
{
printf("No solution exists for n = %d.\n", n);
}
free(board);
return 0;
}
