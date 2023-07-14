#include <stdio.h>
#include <math.h>

typedef struct {
	int exponent;
	int coefficient;
} polyterm;

double eval(polyterm[], int, int);
void input_poly(polyterm[], int);

int main(){
	//Input the polynomial
	int n_terms;
	printf("\nEnter the number of terms of polynomial : ");
	scanf("%d",&n_terms);
	
	polyterm poly[n_terms];
	input_poly(poly, n_terms);
	
	int x;
	printf("\nEnter the parameter X : ");
	scanf("%d",&x);
	
	double res = eval(poly, n_terms, x);
	
	printf("Result: %0.4f", res);
	
	return 0;
}

void input_poly(polyterm arr[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("\nEnter the term %d: ", i+1);
		printf("\nExponent : ");
		scanf("%d", &arr[i].exponent);
		printf("Coefficient : ");
		scanf("%d", &arr[i].coefficient);
	}
	
	return ;
}

double eval(polyterm arr[], int n, int x){
	int i;
	double res;
	
	for(i = 0; i < n; i++){
	    res += arr[i].coefficient * pow(x, arr[i].exponent);
	}
	
	return res;
}
