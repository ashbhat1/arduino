#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void convert_to_binary(int num,char binstr[9]);

int main(){
 int i = 0;
 char binstr[9]= "00000000";
 int pt1=20;int pt2=33;
 //for(i=0;i<128;i++){
  printf("\n20\n");
  convert_to_binary(pt1,binstr);
  printf("Bin Str: %s\n",binstr);
  printf("\n33\n");
  char binstr1[9]= "00000000";  
  convert_to_binary(pt2,binstr);
  printf("Bin Str: %s\n",binstr);
  printf("\n");
 //}
}

void convert_to_binary(int num, char binstr[9]){
 char temp[9] = "00000000";
 int rem=0;
 int quotient = 0;
 int idx = 7;
 while(num/2!=0){
  rem = num%2;
  num=num/2;
  printf("quotient: %d\n",num);
  printf("rem: %d\n",rem);
  printf("char: %c\n",(char)rem+'0');
  temp[idx] = (char)(rem+'0');
  idx--;
 }
 
 rem = num%2;
 temp[idx] = (char)(rem+'0');
 printf("rem: %d\n",(char)rem);
 printf("char: %c\n",(char)(rem+'0'));
 strncpy(binstr,temp,9);
}
