#include<stdio.h>
#define MAX 20
// This solution is partially  correct
// It is not work if 0 come on the principal diagonal position

float arr[MAX][MAX];
float dat=1;

void Operation(int n,int t){
	int i,j;

	if(t==n-2){
		dat*=(arr[t][t]*arr[t+1][t+1]-arr[t][t+1]*arr[t+1][t]);
		return;
	}

	for(i=t;i<n;i++){
		if(arr[t][i]!=0) dat*=arr[t][i];
		else continue;
		for(j=n-1;j>=t;j--) arr[j][i]/=arr[t][i];
	}

	for(i=n-1;i>t;i--)
		for(j=t;j<n;j++)
			arr[j][i]-=arr[j][i-1];

	t++;
	Operation(n,t);

}

void Print(int n){
	int i,j;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++) printf("%0.2f\t",arr[i][j]);
		printf("\n");
	}
}

int main(){
	int i,j,n;

	printf("Enter the order of matrix = ");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("Enter the %dth row %dth column value = ",i+1,j+1);
			scanf("%f",&arr[i][j]);
		}
	}

	Print(n);

	Operation(n,0);

	printf("After Operation\n");
	Print(n);

	printf("Determinant = %0.2f\n",dat);
}
