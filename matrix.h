#pragma once


#include <stdlib.h> 

class matrix{
	
	private:
		int m;
		int n;
		float** data;
		float* min;
		float* max;
		bool saddle;
		float saddle_value; 
	
	public:
		
		matrix(int m_i, int n_i);
		void ReInit(int m_i, int n_i);
		void SaddleSearch();
		void Print();
		bool SaddlePoint();
		
	
};



matrix::matrix(int m_i, int n_i){
	
	ReInit(m_i,n_i);
	
	
}

void matrix::ReInit(int m_i, int n_i){
	
	saddle = false;
	m = m_i;
	n = n_i;
	
	min = new float[m];
	max = new float[n];
	
	data = new float*[m];
	
	for(int i=0; i<m; i++){
		
		data[i] = new float[n];
		
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			
			data[i][j] = (float) rand()/RAND_MAX;
			
		}
		
		
	}
	
	SaddleSearch();
	
	
}

void matrix::SaddleSearch(){
	
	
	//min part
	for(int i=0; i<m; i++){
		
		min[i] = data[i][0];
		
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			
			if(data[i][j]<min[i]){
				
				min[i] = data[i][j];
				
			}
			
		}
		
		
	}
	
	//max part
	for(int j=0; j<n; j++){
		
		max[j] = data[0][j];
		
	}
	
	for(int j=0; j<n; j++){
		for(int i=0; i<m; i++){
			
			if(data[i][j]>max[j]){
				
				max[j]= data[i][j];
				
			}
			
			
		}
		
		
	}
	
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			
			if(max[j]==min[i]){
				
				saddle = true;
				saddle_value = max[j];
				
			}
			
		}
		
		
		
		
	}
	
	
	
	
	
}

void matrix::Print(){
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			
			
			//std::cout<<data[i][j]<<" ";
			printf("%f ", data[i][j]);
			
		}
		
		//std::cout<<min[i];
		//std::cout<<"\n";
		printf("| %f \n", min[i]);
		
	}
	
	for(int j=0; j<n; j++){
		
		printf("---------");
		
	}
	
	printf("\n");
	
	for(int j=0; j<n; j++){
		
		//std::cout<<max[j]<<" ";
		printf("%f ", max[j]);
		
	}
	
	printf("\n");
	
	if(saddle){
		
		printf("punto silla es: %f \n", saddle_value);
		
	}
	
	
}


bool matrix::SaddlePoint(){
	
	return saddle;
	
}