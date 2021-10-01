//Compare the time taken in Quick Sort, Merge Sort, Bubble Sort with huge dataset
import java.util.*;
public class Sort {

	void fillRandomArray(int arr[])
	{
		for(int i=0;i<arr.length;i++)
		{
			arr[i]=(int)(Math.random()*Integer.MAX_VALUE);
		}
	}
	void swap(int arr[], int a, int b)
	{
		int temp=arr[a];
		arr[a]=arr[b];
		arr[b]=temp;
	}
	void bubbleSort(int arr[])
	{
		for(int i=0;i<arr.length;i++)
		{
			for(int j=0;j<arr.length-1;j++)
			{
				if(arr[j]>arr[j+1])
				{
					swap(arr,j,j+1);
				}
			}
		}
	}
	
	void mergeSort(int arr[], int l, int h)
	{
		if(l>=h) return;
		int mid=(l+h)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,h);
		int left[]=new int[mid-l+1];
		int right[]=new int[h-mid];
		for(int i=0;i<left.length;i++)
		{
			left[i]=arr[l+i];
		}
		for(int i=0;i<right.length;i++)
		{
			right[i]=arr[mid+i+1];
		}
		int a=0;
		int b=0;
		int c=l;
		while(a<left.length&&b<right.length)
		{
			if(left[a]<right[b])
			{
				arr[c]=left[a++];
			}
			else
			{
				arr[c]=right[b++];
			}
			c++;
		}
		while(a<left.length)
		{
			arr[c++]=left[a++];
		}
		while(b<right.length)
		{
			arr[c++]=right[b++];
		}
	}
	int part(int arr[], int l, int h, int p)
	{
		int lp=l-1;
		int rp=h;
		while(true)
		{
			while(arr[++lp]<p);
			while(rp>0&&arr[--rp]>p);
			if(lp>=rp)break;
			else
			{
				swap(arr,lp,rp);
			}
		}
		swap(arr,h,lp);
		return lp;
	}
	
	void quickSort(int arr[], int l, int h)
	{
		if(l>=h) return;
		int p=arr[h];
		int lp=part(arr,l,h,p);
		quickSort(arr,l,lp-1);
		quickSort(arr,lp+1,h);
	}
	void show(int arr[])
	{
		for(int i=0;i<arr.length;i++)
		{
			System.out.print(arr[i]+" ");
		}
		System.out.println("\n");
	}
	public static void main(String args[])
	{
		int len=100000;
		int arr[]=new int[len];
		Sort ob=new Sort();
		Scanner sc=new Scanner(System.in);
		boolean chk=true;
		System.out.println("1. Bubble Sort");
		System.out.println("2. Merge Sort");
		System.out.println("3. Quick Sort");
		System.out.println("4. Exit");
		while(chk)
		{
			ob.fillRandomArray(arr);
			System.out.println("Enter choice");
			int ch=sc.nextInt();
			long t1=System.currentTimeMillis();
			switch(ch)
			{
			case 1: ob.bubbleSort(arr); break;
			case 2: ob.mergeSort(arr,0,len-1); break;
			case 3: ob.quickSort(arr,0,len-1); break;
			case 4: chk=false; break;
			default: System.out.println("Wrong choice");
			}
			long t2=System.currentTimeMillis();
			System.out.println("Time = "+(t2-t1)+" ms");
		}
	}
}

