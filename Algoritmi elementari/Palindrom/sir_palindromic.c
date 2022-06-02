#include <stdio.h>
#include <stdlib.h>

int strlength(char sir[]){
      
      int i;
      for(i=0 ; sir[i]!='\0';i++);
      
      return i;
}

int is_equal(char c , char b){
      
      if(c==b)
      return 1;
      else if((c+32)==b)
      return 1;
      else if((c-32)==b)
      return 1;
      else return 0;

}

void is_palindrom(char sir[]){
      
      int n=strlength(sir);
      int flag=0;
      
      for(int i=0 ; i<n/2 ; i++){
            
            if(is_equal(sir[0+i], sir[n-i-1])==0)
            flag=1;    
      }
      
      if(flag==0)
      printf("Este palindromic!");
      else
      printf("Nu este palindromic!");
          
}

// O(n/2)=O(n)


int main(){
      
      char sir[25];
      scanf("%s" , sir);
      
      is_palindrom(sir);
      
      return 0;
}