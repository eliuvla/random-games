#include <iostream>
#include <time.h>
#include <stdlib.h> 
#include <stdio.h>

#include "matrix.h"

int main(){
	
	srand (time(NULL));

	//tamaño de la matriz
	int m = 3;
	int n = 3 ;
	
	int ratio = 0;
	int sample = 10000;
	
	matrix juego(m,n);
	
	juego.Print();
	
	
	printf("%d \n", juego.SaddlePoint());
	
	
	for(int i=0; i<sample; i++){
		
		
		juego.ReInit(m,n);
		if(juego.SaddlePoint()){
			
			ratio +=1;
			
		}
		
	}
	
	
	printf("%f \n", (float)ratio/sample);
	printf("%d \n", ratio);
	
	system("pause");

	
	
	
	
}