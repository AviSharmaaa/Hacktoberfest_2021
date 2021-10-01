import java.util.Scanner;
class insertionSort{
	static void sort(int arr[])  // method to sort the array
	{
		int n = arr.length;
		for (int i = 1; i < n; ++i) {
			int key = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}
	}

	
	static void printArray(int arr[]) // method to print the array
	{
		int n = arr.length;
		for (int i = 0; i < n; ++i)
			System.out.print(arr[i] + " ");

		System.out.println();
	}

	
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter array size: ");
		int n=sc.nextInt();
		int arr[]=new int[n];
		System.out.println("Enter array elements: ");
		for(int i=0;i<n;i++){
			arr[i]=sc.nextInt();
		}
		sort(arr);
		System.out.println("Sorted array: ");
		printArray(arr);
	}
}

/*
Example Output:
Enter array size: 
5
Enter array elements: 
123 45 76 87 94
Sorted array: 
45 76 87 94 123 

*/
