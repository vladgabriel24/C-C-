#include <stdio.h>
#include <stdlib.h>

int parte_intreaga(float x){

    if(x<0){
	
	int nr=x-1;
	return (int)nr;
      
    }else
	return (int)x;
}

float parte_fractionara(float x){
      
    float nr= x - parte_intreaga(x);
    return nr;
      
}

int main() {
	
	float nr=0.1;
	
	printf("Partea intreaga este:%d\n" , parte_intreaga(nr));
    printf("Partea fractionara este:%f" , parte_fractionara(nr));
	
	return 0;
}