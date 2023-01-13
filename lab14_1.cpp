#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[], int N, double B[]){
    double mean=0,sum=0,sum1=0,sum2=1,sum3=0, max=0 , min=100;
    for(int i=0; i<N; i++){
        sum += A[i];
        mean = sum/N;
        if(max<A[i]) max = A[i];
        if(min>A[i]) min = A[i];
    }
    B[0] = mean; B[4] = max; B[5] = min;
    for(int j=0; j<N; j++){
        sum1 += pow((A[j]-mean),2);
    }  
    double devi = pow((sum1/N),1.0/2);
    B[1] = devi;
    for(int k=0; k<N; k++){
        sum2 = A[k]*sum2;
    }
    double geo = pow(sum2,1.0/N);
    B[2] = geo;
    for(int l=0; l<N; l++){
        sum3 += 1.0/A[l];
    }
    double her = N/sum3;
    B[3] = her;
}