# Python program for implementation of Quicksort

'''This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot '''

def partition(arr, low, high):
	i = (low-1)		 # index of smaller element
	pivot = arr[high]	 # pivot
	for j in range(low, high):
		# If current element is smaller than or
		# equal to pivot
		if arr[j] <= pivot:
			# increment index of smaller element
			i = i+1
			arr[i], arr[j] = arr[j], arr[i]
	arr[i+1], arr[high] = arr[high], arr[i+1]
	return (i+1)

# The main function that implements QuickSort
# arr[] --> Array to be sorted,
# low --> Starting index,
# high --> Ending index

# Function to do Quick sort
def quickSort(arr, low, high):
	if len(arr) == 1:
		return arr
	if low < high:

		# pi is partitioning index, arr[p] is now
		# at right place
		pi = partition(arr, low, high)

		# Separately sort elements before
		# partition and after partition
		quickSort(arr, low, pi-1)
		quickSort(arr, pi+1, high)

# driver code
n=int(input("Enter array size: "))
print("Enter the array elements: ")
arr=list(map(int,input().split()))
quickSort(arr,0,n-1)
print ("Sorted array is:")
for i in range(len(arr)):
	print(arr[i],end=" ")
	
	
'''
Example Output:

Enter array size: 5
Enter the array elements: 
123 45 32 67 54
Sorted array is:
32 45 54 67 123 
'''