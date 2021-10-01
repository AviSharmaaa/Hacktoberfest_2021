import java.util.Scanner;

public class selection_sort
{
    static void selectionSort(int arr[], int n)
    {
        int i,j,temp,min;
        for(i=0;i<n;i++)
        {
            min = i;
            for(j=i+1;j<n;j++)
            {
                if(arr[j] < arr[min])  /* Finding minimum element from i+1 to n */
                {
                    min = j;
                }
            }
            temp = arr[i];   /* Swapping the minimum element with arr[i] (present array element) */
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    public static void main(String[] args)
    {
        int size,i;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array : ");
        size = sc.nextInt();
        int arr[] = new int[size];
        System.out.println("Enter "+size+" elements : ");
        for(i=0;i<size;i++)
        {
            arr[i] = sc.nextInt();
        }
        System.out.println("Before sorting : ");
        for(i=0;i<size;i++)
        {
            System.out.print(arr[i]+" ");
        }
        selectionSort(arr,size);
        System.out.println("\nAfter sorting in ascending order : ");
        for(i=0;i<size;i++)
        {
            System.out.print(arr[i]+" ");
        }
    }
}
