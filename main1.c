#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

// void editMessageSent(char* message){
// 	int size = strlen(message);
// 	char newMessage[] = "Hello ";
// 	printf("message %d\n", size);
// 	if(size > sizeof(newMessage)){
// 		strcpy(message , newMessage);
// 	}else{
// 		printf("New Message is to big %s\n");
// 	}
// }
//
// void concat(char* all , int times){
// 	char name[] = " \n ofir";
//
// 	for(int index = 0; index < times; index++){
// 		strcat(all, name);
// 	}
// 	printf("%d\n", times);
// }
void printfile(char* fn){
	FILE *file = fopen(fn,"r");
	if(file ==NULL){
		printf("Failed to load. %s\n",fn);
		return;
	}else{
		printf("Success. %s\n",fn);
	}

	char c;
	for(fscanf(file , "%c" ,&c) ; !feof(file)/*condition*/;fscanf(file , "%c" ,&c) /*increment*/)
	{
		printf("% c",c);
	}

	fclose(file);
}

void writefile(char* fn){
	FILE *file = fopen(fn,"w");
	if(file == NULL){
		printf("Failed to write.%s\n", fn);
	}else{
		printf("Success.%s\n", fn);
	}
	char c;

	for(fscanf(stdin , "%c",&c) ; c != 'o' ; fscanf(stdin , "%c" ,  &c)){
		fprintf(file, "%c",c);
	}
	fclose(file);
}
void append(char* fn, char* ar){
	FILE *file = fopen(fn, "a");
	fprintf(file, "%s\n",ar);
	fclose(file);
}

void copyfile(char* name1 , char* name2){
	FILE *file1 = fopen(name1,"r");
	FILE *file2 = fopen(name2, "w");

	char c;
	for(fscanf(file1 , "%c" ,&c) ; !feof(file1)/*condition*/;fscanf(file1 , "%c" ,&c) /*increment*/)
	{
		fprintf(file2,"%c", c);
	}


	fclose(file1);
	fclose(file2);
}

main(void){
	int size =4;
char fn[] = "r.txt";
printfile(fn);
// writefile(fn);
append(fn,"Hello");
// append(fn,"oooo");
// append(fn,"lkj");
// append(fn,"ppp");
copyfile(fn,"e.txt");
printfile("e.txt");
printfile("r.txt");
	// int array[size] = {2,5,9,66};
	// int index = 0;
	// while(index < size){
	// 	printf("%d\n", array[index++]);
	// }




	// char randomMessage[100] = "Fuction Fucker";
	// printf("Old Message: %s\n",randomMessage);
	// editMessageSent(randomMessage);
	// printf("New Message: %s\n",randomMessage);
// system("COLOR 9C");
	// printf("Old message : %s\n",randomMessage);
	// concat(randomMessage,5);
	// printf("New message : %s\n",randomMessage);
	// typedef union{
	// 	short inda;
	// 	float pound;
	// 	float oncea;
	// } amount;

	// 	amount oraAmt = {.oncea = 16};
	// printf("union:%d\n",sizeof(amount) );
	// 	oraAmt.inda = 4;
	// printf("Orange Juice Amount: %.2f : Size: %d\n",oraAmt.oncea,sizeof(oraAmt.oncea));
	// printf("Number of fucks: %d : Size: %d\n",oraAmt.inda,sizeof(oraAmt.inda));
	// int i = 0;

	// while(i < sizeof(randomMessage) ){
	// 	printf("%c",randomMessage[i++]);
	// }
	// for(i = 0; i < sizeof(randomMessage);i++){
	// 	printf("%c\n", randomMessage[i]);
	// }
	// printf("%s\n",randomMessage);
	getch();
		return 0;
}
