#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randData(double *,int,int);

void findColSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,result,N,M); 
	showData(result,1,M);
}

//Write definition of randData(), showData() and findColSum()

void randData(double *x,int y,int z){
	for(int i=0; i<y*z; i++){
		*x=(rand()%101)/100.00;
		x++;
	}
}

void findColSum(const double *x,double *r,int y,int z){
	double sum=0;
	for(int i=0; i<y*z; i++){
		sum+=*x;
		if((i+1)%y==0){
			*r=sum;
			sum=0;
			r++;
			x-=z*(y-1)-1;
		}else{
			x+=z;
		}
	}
}

void showData(double *r,int y,int z){
	for(int i=0; i<y; i++){
		for(int j=0; j<z; j++){
			cout<< *r <<" ";
			r++;
		}
		cout<<"\n";
	}
}