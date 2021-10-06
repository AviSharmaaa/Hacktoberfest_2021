 #include<stdio.h>  
 #include <time.h> 
int binarySearch(int[], int, int, int);  
void main ()  
{  
    int arr[10] = {16, 19, 20, 23, 45, 56, 78, 90, 96, 100}; 
	 clock_t start,stop;
    double cpu_time_used; 
    int item, location=-1;   
    printf("Enter the item which you want to search ");  
    scanf("%d",&item); 
	start=clock(); 
    location = binarySearch(arr, 0, 9, item);  
    stop=clock();
    if(location != -1)   
    {  
        printf("Item found at location %d",location);  
    }  
    else  
    {  
        printf("Item not found");  
    }  
      cpu_time_used=((double)(stop-start))/CLOCKS_PER_SEC;
    printf("\nRunning time=%f",cpu_time_used);
}   
int binarySearch(int a[], int beg, int end, int item)  
{  
    int mid;  
    if(end >= beg)   
    {     
        mid = (beg + end)/2;  
        if(a[mid] == item)  
        {  
            return mid+1;  
        }  
        else if(a[mid] < item)   
        {  
            return binarySearch(a,mid+1,end,item);  
        }  
        else   
        {  
            return binarySearch(a,beg,mid-1,item);  
        }  
      
    }  
    return -1;   
}  
