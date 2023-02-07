#include<stdio.h>
#define MAX 10


int fact(int n){
	int i,temp=1;
	for(i=2;i<=n;i++) temp*=i;
	return temp;
}

float calc(float p,int k){
	int i;
	float f=p;
	for(i=1;i<k;i++)
		f*=p-i;
	return f;
}

int main(){
	int i,j,n,f=1;
	float h,x,p,sum,data[MAX][10];
	printf("Enter the number of terms = ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		printf("Enter %d x value = ",i+1);
		scanf("%f",&data[i][0]);
		printf("Enter %d f(x) = ",i+1);
		scanf("%f",&data[i][1]);
		
		if(i==1) h=data[1][0]-data[0][0];
		
		if(i>1 && data[i][0]!=data[i-1][0]+h){
			printf("Not equispaced inputs for x value!!");
			f=0;
			break;
		}
		
	}
	
	if(f){

		//To calculate the interpolation
		printf("Enter the interpolated value = ");
		scanf("%f",&x);
		
		//Calculate the table
		for(i=1;i<n;i++){
			for(j=2;j<i+2;j++){
				data[i][j]=data[i][j-1]-data[i-1][j-1];
				
			}
		}
		
		//Print the table
		for(i=0;i<n;i++){
			for(j=0;j<i+2;j++)
				printf("%0.2f ",data[i][j]);
			printf("\n");
		}
		
		//Calculate the final interpolated value
		p=(x-data[0][0])/h;		
		sum=data[0][1];
		
		for(i=1;i<n;i++){
			sum+=((calc(p,i)*data[i][i+1])/fact(i));
		}
		printf("Required Solution f(%0.1f)=%0.3f",x,sum);

	}
}
