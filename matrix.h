#pragma once
#include <stdlib.h> 

class matrix{
	private:
		int m; int n; float** data; float* min; float* max; bool saddle; float saddle_value; 
	public:
		matrix(int m_i, int n_i);
		void Clean();
		void Init(int m_i, int n_i);
		void ReInit(int m_i, int n_i);
		void SaddleSearch();
		bool SaddlePoint();
};

matrix::matrix(int m_i, int n_i){
	Init(m_i,n_i);
}

void matrix::Clean(){
	delete min; min = NULL;
	delete max; max = NULL;
	for(int i=0; i<m; i++){
		delete data[i]; data[i] = NULL;
	}
	delete data; data = NULL;
}

void matrix::Init(int m_i, int n_i){
	saddle = false; m = m_i; n = n_i;
	min = new float[m]; max = new float[n]; data = new float*[m];
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

void matrix::ReInit(int m_i, int n_i){
	Clean();
	Init(m_i,n_i);
}

void matrix::SaddleSearch(){
	//parte min
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
	//parte max
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
	//compara la max y min
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(max[j]==min[i]){
				saddle = true;
				saddle_value = max[j];
			}
		}
	}
}

bool matrix::SaddlePoint(){
	return saddle;
}