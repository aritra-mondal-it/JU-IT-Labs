#include<stdio.h>
void main(){
    int n,i,j;
    printf("Enter n:");
    scanf("%d",&n);
    int arr[n][n];
    
    printf("The array elements are :\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            	printf("a[%d][%d] = ",i,j);
		scanf("%d",&arr[i][j]); }
    }
    printf("The matrix is:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",arr[i][j]);}
        
        printf("\n");
    }
    //Swapping
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            int x=0;
            x=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=x;
            }
    }
    printf("The transpose matrix is :\n");
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",arr[i][j]); }
            printf("\n");
    }
}
