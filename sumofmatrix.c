main()
{
    int i,j,A[3][3],B[3][3],C[3][3];
    printf("enter 9 elements of 1st matrices");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("your first matrix is    \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }

    printf("enter 9 elements of 2nd matrices");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }
    printf("your 2nd matrix is     \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    printf("THE SUM OF THE TWO MATRICES IS \n");
            for(i=0;i<3;i++)
                    {
                        for(j=0;j<3;j++)
                            {
                                printf("%d ",A[i][j]+B[i][j]);
                            }
                        printf("\n");
                   }
                        getch();
}

