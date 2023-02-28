#include <stdio.h>
#include<math.h>

#define f(x) (x*x*x+2*x+1)
#define d(x) (3*x*x+2)

float Round(float n){
    return round(n*1000)/1000;
}

void Bisection(float a,float b){


    while(1){
        if(f((a+b)/2)<0) a=(a+b)/2;
        else b=(a+b)/2;
        // printf("%f\t%f\t%f\n",a,b,f((a+b)/2));
        if(Round(a)==Round(b)) break;
    }
    printf("using Bisection Method = %0.3f\n",(a+b)/2);
}

void Regula_Falsi(float a,float b){
    float x;

    while(1){
        x=(a*f(b)-b*f(a))/(f(b)-f(a));
        if(f(x)<0) b=x;
        else a=x;
        // printf("%f\t%f\t%f\n",a,b,f((a+b)/2));
        if(Round(a)==Round(b)) break;
    }

    printf("using Regula-Falsi Method = %0.3f\n",a);
}

void Newton_Raphson(float prev,float curr){

    while(1){
        prev-=f(prev)/d(prev);
        curr=prev;
        curr-=f(curr)/d(curr);
        // printf("%f\n%f\n",prev,curr);
        if(Round(curr)==Round(prev)) break;
        prev=curr;
    }
    printf("using Newton-Raphson Method = %0.3f\n",curr);

}

int main(){
    float x=0;

    while(1){
        if(f(x)>0) break;
        x++;
    }

    Bisection(x-1,x);
    Regula_Falsi(x-1,x);
    Newton_Raphson(x-1,x);
}

