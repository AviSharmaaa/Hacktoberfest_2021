'''
Inverted hollow full pyramid

Example Input:
6
Output:
* * * * * *
 *       *
  *     *
   *   *
    * *
     *
'''
#Code:
n=int(input())
for i in range(1,n+1):
    print("*",end=" ")
print()
l=2
m=2*n-2
for i in range(2,n+1):
    for j in range(1,2*n):
        if(j==l or j==m):
            print("*",end="")
            continue
        print(" ",end="")
    print()
    l=l+1
    m=m-1