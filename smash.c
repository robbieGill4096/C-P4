#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINE 4096
//**Method Prototypes**
//---------------------------
//---------------------------
void executeCommand(char*);
int numberOfCommands(char*);
int command_selection(char*);
//---------------------------
char bfr[MAXLINE];

//	**Looping prompt for the Smash SHELL** 
//--------------------------------------------------------------
//--------------------------------------------------------------
int main(){
fputs("$",stderr); //output the first prompt

//loop until EOF or error
	while (fgets(bfr, MAXLINE,stdin) != NULL) {

		if (strlen(bfr) == MAXLINE-1){//checks for overflow. 
			return -1;
			}
		else{
			
			bfr[strlen(bfr)-1] = '\0'; //replace newline with null
			executeCommand(bfr);//puts(bfr);
			fputs("$ ",stderr);
			}}
		return 0;
		}

//	**parse its single parameter into space-seperated tokens using the strtok**
//--------------------------------------------------------------
//--------------------------------------------------------------
void executeCommand(char *str){
	int command_count = numberOfCommands(bfr);
	char *args[command_count];
	int i =0;
	char *p = strtok (str," ");
	while (p != NULL)
		{
		args[i++] = p;
		p = strtok (NULL, " "); }

		for (i = 0; i< command_count; ++i)
		{	printf("%s\n",args[i]);
		
		}
	command_selection(args[0]);
}
//	**calculates the number of commands read in from a pointer**
//--------------------------------------------------------------
//--------------------------------------------------------------
int numberOfCommands(char *str1) {
	char copy[strlen(str1)];
	strncpy(copy,str1,strlen(str1));
	int command_count = 0;
	char delim[] = " ";
	char* token1;


	for (token1 = strtok(copy, delim); token1; token1 = strtok(NULL, delim)) {
   	 command_count+=1;
			}

		return command_count;}
//	**Makes a selection based on a Command**
//--------------------------------------------------------------
//--------------------------------------------------------------
int command_selection(char *command){
//---------------------------------------
//---------------------------------------
	if (strcmp(command, "exit") == 0) 
	{
printf("choice of exit is made");
	  exit(0);
	} 
//---------------------------------------
//---------------------------------------
	else if (strcmp(command, "cd") == 0)
	{

	}
//---------------------------------------
//---------------------------------------
	else if (strcmp(command, "") == 0)
	{

	}
//---------------------------------------
//---------------------------------------
	else if (strcmp(command, "") == 0)
	{

	}
//---------------------------------------
//---------------------------------------
	else if (strcmp(command, "") == 0)
	{

	}
	/* more else if clauses */
	else /* default: */
{
}





}
