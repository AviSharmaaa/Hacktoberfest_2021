import java.util.Scanner;

public class JavaProgram
{
   public static void main(String args[])
   {
       int size, i, j, temp;
       int arr[] = new int[50];
       Scanner scan = new Scanner(System.in);
      
       System.out.print("Enter Array Size : ");
       size = scan.nextInt();
      
       System.out.print("Enter Array Elements : ");
       for(i=0; i<size; i++)
       {
           arr[i] = scan.nextInt();
       }
      
       j = i - 1;     // now j will point to the last element
       i = 0;         // and i will point to the first element
      
       while(i<j)
       {
           temp = arr[i];
           arr[i] = arr[j];
           arr[j] = temp;
           i++;
           j--;
       }
      
       System.out.print("Now the Reverse of Array is : \n");
       for(i=0; i<size; i++)
       {
           System.out.print(arr[i]+ "  ");
       }       
   }
}
