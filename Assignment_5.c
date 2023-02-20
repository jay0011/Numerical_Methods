#include <stdio.h>
#include<math.h>

#define f(x) (x*x*x+2*x+1)
#define d(x) (3*x*x+2)

float Round(float n){
    return round(n*1000)/1000;
}

void Bisection(){
    float a,b,x=0;

    while(1){
        if(f(x)>0) break;
        x++;
    }
    a=x-1;
    b=x;

    while(1){
        if(f((a+b)/2)<0) a=(a+b)/2;
        else b=(a+b)/2;
        // printf("%f\t%f\t%f\n",a,b,f((a+b)/2));
        if(Round(a)==Round(b)) break;
    }
    printf("Bisection = %0.3f\n",(a+b)/2);
}

void Regula_Falsi(){
    float a,b,x=0;

    while(1){
        if(f(x)>0) break;
        x++;
    }
    a=x-1;
    b=x;

    while(1){
        x=(a*f(b)-b*f(a))/(f(b)-f(a));
        if(f(x)<0) b=x;
        else a=x;
        // printf("%f\t%f\t%f\n",a,b,f((a+b)/2));
        if(Round(a)==Round(b)) break;
    }

    printf("Regula_Falsi = %0.3f\n",a);
}

void Newton_Raphson(){
    float prev,curr,x=0;

    while(1){
        if(f(x)>0) break;
        x++;
    }
    prev=x-1;
    curr=x;

    while(1){
        prev-=f(prev)/d(prev);
        curr=prev;
        curr-=f(curr)/d(curr);
        // printf("%f\n%f\n",prev,curr);
        if(Round(curr)==Round(prev)) break;
        prev=curr;
    }
    printf("Newton-Raphson = %0.3f\n",curr);

}

int main(){
    
    Regula_Falsi();
    Bisection();
    Newton_Raphson();
}

