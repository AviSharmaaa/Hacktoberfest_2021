// Program to multiply two matrices using Strassen Algorithm

#include <iostream>
using namespace std;

// Function to create a matrix
int **initialize(int n)
{
    int **temp = new int *[n];
    for (int i = 0; i < n; i++)
        temp[i] = new int[n];
    return temp;
}

// Function to take input of a matrix
void input(int **M, int n, int m)
{
    cout << "\nEnter matrix " << m << ":\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> M[i][j];
}

// Function to display a matrix
void display(int **M, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << M[i][j] << " ";
        cout << "\n";
    }
}

// Function to add two matrices
int **add(int **M1, int **M2, int n)
{
    int **temp = initialize(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = M1[i][j] + M2[i][j];
    return temp;
}

// Function to subtract two matrices
int **sub(int **M1, int **M2, int n)
{
    int **temp = initialize(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = M1[i][j] - M2[i][j];
    return temp;
}

// Function to perform Strassen Multiplication
int **Strassen(int **A, int **B, int n)
{
    if (n == 1)
    {
        int **C = initialize(1);
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int **C = initialize(n);
    int k = n / 2;

    int **A11 = initialize(k);
    int **A12 = initialize(k);
    int **A21 = initialize(k);
    int **A22 = initialize(k);
    int **B11 = initialize(k);
    int **B12 = initialize(k);
    int **B21 = initialize(k);
    int **B22 = initialize(k);

    // Partitioning A and B into 4 sub matrices
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][k + j];
            A21[i][j] = A[k + i][j];
            A22[i][j] = A[k + i][k + j];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][k + j];
            B21[i][j] = B[k + i][j];
            B22[i][j] = B[k + i][k + j];
        }

    // Recursive calls
    int **P1 = Strassen(A11, sub(B12, B22, k), k);
    int **P2 = Strassen(add(A11, A12, k), B22, k);
    int **P3 = Strassen(add(A21, A22, k), B11, k);
    int **P4 = Strassen(A22, sub(B21, B11, k), k);
    int **P5 = Strassen(add(A11, A22, k), add(B11, B22, k), k);
    int **P6 = Strassen(sub(A12, A22, k), add(B21, B22, k), k);
    int **P7 = Strassen(sub(A11, A21, k), add(B11, B12, k), k);

    // Calculating sub matrices of final ouput matrix
    int **C11 = sub(add(add(P5, P4, k), P6, k), P2, k);
    int **C12 = add(P1, P2, k);
    int **C21 = add(P3, P4, k);
    int **C22 = sub(sub(add(P5, P1, k), P3, k), P7, k);

    // Copying values into final matrix C
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[k + i][j] = C21[i][j];
            C[k + i][k + j] = C22[i][j];
        }

    return C;
}

// Driver code
int main()
{

    int n, i = 1;

    cout << "\n[20BCE0514]";
    // Enter the size of matrices
    cout << "\nEnter the size of the matrices (should be a multiple of 2): ";
    cin >> n;

    // Input both matrices
    int **A = initialize(n);
    int **B = initialize(n);
    input(A, n, i);
    input(B, n, i + 1);

    // Display both matrices
    cout << "\nMatrix A:\n";
    display(A, n);
    cout << "\nMatrix B:\n";
    display(B, n);

    // Function call for Strassen Multiplication
    int **C = initialize(n);
    C = Strassen(A, B, n);

    // Display product
    cout << "\nMultiplication result:\n";
    display(C, n);

    return 0;
}