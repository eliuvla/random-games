#include <time.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include "matrix.h"

int main(){
	srand (time(NULL));
	int m = 2; int n = 2; int sample = 10000; int success = 0;
	matrix juego(m,n);
	for(int i=0; i<sample; i++){
		juego.ReInit(m,n);
		if(juego.SaddlePoint()){
			success +=1;
		} 
	}
	printf("%f \n", (float)success/sample);
	printf("%d \n", success); 
	system("pause"); return 0;
}