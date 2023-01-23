#include<stdio.h>
#include<math.h>
#define MAX 20

//   0 |  1 |  2 | 3 | 4 | 5 |     6       |
//	low|high|freq| x |fx |cf |fi(xi-xbar)2 |


float data[MAX][7];
float N,mean;
int n;

void Mean(){
	int i;
	float sumT=0;

	for(int i=0;i<n;i++){
		data[i][3]=((data[i][0]+data[i][1])/2.0);
		data[i][4]=data[i][3]*data[i][2];
		sumT+=data[i][4];
	}
	mean=sumT/N;
}

void Median(){
	int i;
	float l,cf=0,fm,h,median;

	float hf=N/2;
	data[0][5]=data[0][2];


	for(i=1;i<n;i++){

		data[i][5]=data[i][2]+data[i-1][5];

		if(data[i][5]>hf && cf==0){
			l=data[i][0];
			cf=data[i-1][5];
			fm=data[i][2];
			h=data[i][1]-data[i][0];
		}
	}

	median=l+((hf-cf)*h)/fm;
	printf("Median = %f\n\n",median);
}

void Mode(){
	int i;
	float f0,f1,f2,l,h,mode;

	f1=data[0][2];
	for(i=1;i<n-1;i++){
		if(f1<data[i][2]){
			f0=data[i-1][2];
			f1=data[i][2];
			f2=data[i+1][2];
			l=data[i][0];
			h=data[i][1]-data[i][0];
		}
	}

	mode=l+((f1-f0)/(2*f1-f0-f2))*h;
	printf("Mode = %f\n\n",mode);
}


void SD(){
	int i;
	float sd,sumF=0;

	if(mean==0) Mean();

	for(i=0;i<n;i++){
		data[i][6]=data[i][2]*(data[i][3]-mean)*(data[i][3]-mean);
		sumF+=data[i][6];
	}

	sd=sqrt(sumF/N);
	printf("Standard Deviation = %f\n\n",sd);
}

void stat_memo(){
	int i;
	printf("Enter the number of class intervals = ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter %dth lower range = ",i+1);
		scanf("%f",&data[i][0]);
		printf("Enter %dth higher range = ",i+1);
		scanf("%f",&data[i][1]);
		printf("Enter %dth frequency = ",i+1);
		scanf("%f",&data[i][2]);
		N+=data[i][2];
	}
}

int main(){
	int ch,flag=1;

	stat_memo();
	//dyna_memo();


	while(flag){
		
		printf("1.Mean\n2.Median\n3.Mode\n4.Standard Deviation\n5.Exit\n");
		printf("Enter your choice = ");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				Mean();
				printf("Mean = %f\n\n",mean);
				break;
			case 2:
				Median();
				break;
			case 3:
				Mode();
				break;
			case 4:
				SD();
				break;
			case 5:
				flag=0;
				break;
			default:
				printf("Invalid Input!!\n\n");
				break;
			}
	}
	

}
