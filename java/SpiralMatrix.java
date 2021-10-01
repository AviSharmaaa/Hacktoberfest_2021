
/*

Problem description

Given an m x n matrix, return all elements of the matrix in spiral order.



*/


import java.util.*;

class SpiralMatrixII {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int result[][] = spiralMatrixII(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }
    }

    static int[][] spiralMatrixII(int n) {

        int dir=1;
        int l=0,t=0;
        int r=n-1;
        int b =n-1;
        int[][] result = new int[n][n];
        int count =1;
        while(l<=r && t<=b) {

            if(dir==1) {

                for(int i=l;i<=r;i++) {
                    result[t][i] = count;
                    count++;
                }
                t++;

            }
            else if(dir==2) {
                for(int i=t;i<=b;i++) {
                    result[i][r] = count;
                    count++;
                }
                r--;
            }
            else if(dir==3) {
                for(int i=r;i>=l;i--) {
                    result[b][i] = count;
                    count++;
                }
                b--;
            }
            else if(dir==4) {
                for(int i=b;i>=t;i--) {
                    result[i][l] = count;
                    count++;
                }
                l++;
            }

            dir = (dir%4) + 1;
            

        }
        return result;
    }
}
