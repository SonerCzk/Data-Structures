#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXCHAR 10050
struct node
{
	int letter[1001];
	int digit[1001];
	int lenght[1001];
	int strength[1001];
	char array2[1001][25];
	struct node *next;
};
int main() {
    FILE *fp;
    int i,j,t;
    int count=0;
    char array1[100001][25];
    char array3[10001][25];
    char str[MAXCHAR];
    char* filename ="100000.txt";
    char* filename2 ="10000.txt";
    char* filename3 ="1000.txt";
    char search[25];

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    for(i=0;i<100001;i++){
    	if(fgets(str, MAXCHAR, fp) != NULL){
    		strcpy(array1[i],str);
		}
	}
	fp = fopen(filename2, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    for(i=0;i<10001;i++){
    	if(fgets(str, MAXCHAR, fp) != NULL){
    		strcpy(array3[i],str);
		}
	}
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	 for(i=0;i<1001;i++){
    	strcpy(ptr->array2[i],array1[i]);
	}
	char option[15];
	for(t=0;t<10;t++){
	printf("\n1-) Enter PassWord\n2-) Sort Passwords\n3-) Check Strong and Weak Passwords\n4-) Exit\n");
	scanf(" %s",&option);
	int x = atoi(option);
	switch(x){
		case 1:{
	printf("Enter The Password Please!\n");
	scanf("%s",&search);
		int x;
	for(i=0;i<=100001;i++){
			if(strncmp(array1[i],search,strlen(search)) == 0) {
      printf("Password Accepted!\n");
      break;
		}
	}
	if(i==100002){
	printf("Wrong Password\n");}
     break;}
     case 2:{
     	char temp[25];
     	int i,j;
     	for(i=0;i<=10000;i++){
      for(j=i+1;j<=10000;j++){
         if(strncmp(array3[i],array3[j],strlen(array3[i]))>0){
            strcpy(temp,array3[i]);
            strcpy(array3[i],array3[j]);
            strcpy(array3[j],temp);
         }}}
     	printf("\nTop 10 Password in ascending order :\n");
     	for(i=0;i<10;i++){
     		printf(" %s ",array3[i]);
		 }
         printf("\nTop 10 Password in descending order :\n");
		for(i=0;i<10;i++){
     		printf(" %s ",array3[10000-i]);
		 }
		 break;}
		 case 3:{
		 	for(i=0;i<1000;i++){
		 		ptr->strength[i]=0;
		 		ptr->lenght[i]=0;
		 		ptr->letter[i]=0;
		 		ptr->digit[i]=0;
			 }
			 
		 	int i,j;
			for(i=0;i<1000;i++){
				for(j=0;ptr->array2[i][j]!='\0';j++){
					ptr->lenght[i]++;
				}
			}
		 	for(i=0;i<1000;i++){
		 		for(j=0;ptr->array2[i][j]!='\0';j++){
		if (ptr->array2[i][j]<123 && ptr->array2[i][j]>60){ 
            ptr->letter[i]=1;}
        if (ptr->array2[i][j]<58 && ptr->array2[i][j]>47){ 
            ptr->digit[i]=1;}
				 }
			 }
			 for(i=0;i<1000;i++){
			 	if (ptr->lenght[i]>8){
			 		ptr->strength[i]+=10;}
			 	if(ptr->letter[i]==1){
			 		ptr->strength[i]+=4;
			 	if(ptr->digit[i]==1){
			 		ptr->strength[i]+=6;
				 }
				 }	 
			 }  
			 printf("\n10 Strong Password\n");
			 for(i=0;i<1000;i++){
			  	if(ptr->strength[i]>19 && count<10){
			  	printf("\n%s\n",&ptr->array2[i]);
			  	count++;
				  }
			  }
			  count=0;
			  for(i=0;i<1000;i++){
		 		ptr->strength[i]=0;
		 		ptr->lenght[i]=0;
		 		ptr->letter[i]=0;
		 		ptr->digit[i]=0;
			 }
			 	for(i=0;i<1000;i++){
				for(j=0;ptr->array2[i][j]!='\0';j++){
					ptr->lenght[i]++;
				}
			}
		 	for(i=0;i<1000;i++){
		 		for(j=0;ptr->array2[i][j]!='\0';j++){
		if (ptr->array2[i][j]<123 && ptr->array2[i][j]>60){ 
            ptr->letter[i]=1;}
        if (ptr->array2[i][j]<58 && ptr->array2[i][j]>47){ 
            ptr->digit[i]=1;}
				 }
			 }
			   for(i=0;i<1000;i++){
			  	if (ptr->lenght[i]<6){
			 		ptr->strength[i]-=30;}
			 	if(ptr->letter[i]==1){
			 		ptr->strength[i]-=4;}
			 	if(ptr->digit[i]==1){
			 		ptr->strength[i]-=20;}
			  }	 
			  printf("\n10 Weak Password \n");
			  for(i=0;i<1000;i++){
			  	if(ptr->strength[i]<-40 && count<10){
			  	printf("\n%s\n",&ptr->array2[i]);
			  	count++;
				  }
			  }
			 
			break;
		 }
    case 4:{
    	printf("\nThanks For Using!");
    	return 0;
		break;}	
		default: {
			printf("\nPlease Enter between 1-4\n");
			break;}
			}
		
		}
    fclose(fp);
    return 0;
}

