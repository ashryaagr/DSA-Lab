#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int calculateHash(char * str,int baseNum,int tableSize){
   int len = strlen(str); 
   int hashVal = 0;
   for(int i=0;i<len;i++){
	hashVal = hashVal + str[i];
    }
    hashVal = hashVal % baseNum;
    hashVal = hashVal % tableSize;
    return hashVal;	
}

int countCollision(char* strArr[],int validStrings,int baseNum,int tableSize){
	int countCollision[tableSize];
	
	for(int i=0;i<tableSize;i++){
	 countCollision[i]= -1;
	}

	for(int i=0;i<validStrings;i++){
		int hashVal = calculateHash(strArr[i],baseNum,tableSize);
		countCollision[hashVal]++;
	}
	
	int totalCollisions = 0;
	for(int i=0;i<tableSize;i++){
		if(countCollision[i]>0)
		   totalCollisions = totalCollisions + countCollision[i];	
	}
	return totalCollisions;
}

char** parse(int* l){

	FILE *fptr = fopen("aliceinwonderland.txt","r");
	
	if(fptr == NULL){
		printf("FILE NOT FOUND!!\n");
		exit(1);
	}	
	
	
	int validStrings = 0;
	int noOfStrings = 100;
	char** strArr = (char**)malloc(sizeof(char*)*noOfStrings);
	//Initially allocating memory for 100 char pointers.
	
	
	char str[100];
	//Assuming word size would not exceed 100 characters
	
	while(!feof(fptr)){		
		fscanf(fptr,"%s",str);
		int len = strlen(str);
		strArr[validStrings] = (char *) malloc(sizeof(char)*(len+1));
		strcpy(strArr[validStrings],str); 
		validStrings++;
		if(validStrings >= noOfStrings){
			noOfStrings = noOfStrings*2;
			strArr = (char**)realloc(strArr,sizeof(char*)*noOfStrings);		
		}
	}		
	printf("Total number of Valid Strings: %d\n",validStrings);
	*l = validStrings;
	return strArr;
}

void profiling(){
	int validStrings;
	char** strArr = parse(&validStrings);	
	
	int tableSize[3] = {5000,50000,500000};
	int baseNum[3][6] = {{5003,5009,5011,5000011,5000077,5000081},{50021,50023,50033,50000017,50000021,50000047},{500009,500029,500041,500000003,500000009,500000041}};
	int collisions[18];

	
	for(int i=0;i<3;i++){
		for(int j=0;j<6;j++){
			collisions[6*i+j] = countCollision(strArr,validStrings,baseNum[i][j],tableSize[i]);	
			printf("Table Size:%d \t Base Num:%d   	\t Collision Count:%d\n",tableSize[i],baseNum[i][j],collisions[6*i+j]);
		}	
	}

	int min = collisions[0];

	for(int i=0;i<18;i++){
		if(collisions[i]<min){
			min = collisions[i];		
		}
	}

	for(int i=0;i<18;i++){
		if(collisions[i] == min)
		printf("Minimum collisions occur for TableSize: %d and Base Number: %d  %d\n",
			tableSize[i/6],baseNum[i/6][i%6],i);		
	}
}

int main(){
	profiling();
	return 0;	
}