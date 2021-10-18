# Function to do insertion sort
def insertionSort(arr):
	for i in range(1, len(arr)):
		key = arr[i]
		j = i-1
		while j >=0 and key < arr[j] :
				arr[j+1] = arr[j]
				j -= 1
		arr[j+1] = key
		
n=int(input("Enter array size: "))
print("Enter the array elements: ")
arr=list(map(int,input().split()))
insertionSort(arr)
print ("Sorted array is:")
for i in range(len(arr)):
	print(arr[i],end=" ")

'''
Example Output:
Enter array size: 
5
Enter the array elements: 
123 45 76 87 94
Sorted array is: 
45 76 87 94 123 
'''