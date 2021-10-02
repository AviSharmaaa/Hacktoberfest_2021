#include <stdio.h>
void printspiral (int m , int n , int ar [][n ])
{
    printf("The array in spiral order : ");
    int t =0, b =m -1,l =0, r =n -1;
    int dir =0;
    while(t <=b  && l <=r )
    {
        if(dir ==0)
        {
            for(int k =l ;k <=r ;k ++)
            printf("%d ",ar [t ][k ]);
            t ++; 
        }
        else if(dir ==1)
        {
            for(int k =t ;k <=b ;k ++)
            printf("%d ",ar [k ][r ]);
            r --; 
        }
        else if(dir ==2)
        {
            for(int k =r ;k >=l ;k --)
            printf("%d ",ar [b ][k ]);
            b --; 
        }
        else if(dir ==3)
        {
            for(int k =b ;k >=t ;k --)
            printf("%d ",ar [k ][l ]);
            l ++; 
        }
        dir  = (dir +1)%4;
    }
}
void main()
{
    int r ,c ;
    printf("Enetr the dimmensions of the array: ");
    scanf("%d %d", &r , &c );
    int a [r ][c ];
    printf("Enter the elements of the array: ");
    for(int i =0;i <r ;i ++)
    {
        for(int j =0;j <c ;j ++)
        {
            scanf("%d", &a [i ][j ]);
        }
    }
    printf("The array:\n");
    for(int i =0;i <r ;i ++)
    {
        for(int j =0;j <c ;j ++)
        {
            if(a [i ][j ] < 10)
                printf("%d   ", a [i ][j ]);
            else
                printf("%d  ", a [i ][j ]);

        }
        printf("\n");
    }
    printspiral (r ,c ,a );
    printf("\n");
}