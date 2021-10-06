// shellSort in Java
import java.util.Scanner;

public class shellSort {
    public static void main(String[] args) {
        // taking user input array
        Scanner sc = new Scanner(System.in);
        System.out.print("Number of Elements = ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        for(int j = 0; j<n; j++){
            arr[j] = sc.nextInt();
        }
        // shellSort Algorithm
        for (int gap = arr.length/2; gap > 0; gap =  gap/2){

            for(int i = gap; i<arr.length; i++){
                int newElement = arr[i];

                int j = i;
                while(j >= gap && arr[j-1]>newElement){
                    arr[j] = arr[j-gap];
                    j-=gap;
                }
                arr[j] = newElement;
            }

            }
        //Printing Array
        for(int i = 0; i<arr.length; i++){
            System.out.println(arr[i]);
        }

    }
}
