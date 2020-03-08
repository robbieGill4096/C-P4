//	**library defined**
//---------------------------
//---------------------------
#include<stdio.h>
#include<string.h>
#include <errno.h>
#include <unistd.h>
#include<stdlib.h>

//	**User Define**
//---------------------------
//---------------------------
#include "history.h"
//	**Constants**
//---------------------------
//---------------------------
#define MAXLINE 4096
#define PATHLEN 100 // length of the current path to return to the user.

//	**Method Prototypes**
//---------------------------
//---------------------------
void executeCommand(char*);//executes a user command from keyboard input.
int numberOfCommands(char*);//returns the (int) number of commands to the user tokenized by " "
char*getcwd(char*,size_t);// returns the current working directory as a string.
//---------------------------
char bfr[MAXLINE];
//
//printf(" %s:%d\n ",args[1],errno); general error message.
//	**Looping prompt for the Smash SHELL** 
//--------------------------------------------------------------
//--------------------------------------------------------------
int main()
{
// printing current working directory  
fputs("$",stderr); //output the first prompt
//loop until EOF or error
	while (fgets(bfr, MAXLINE,stdin) != NULL) 
	{
		if (strlen(bfr) == MAXLINE-1)//checks for overflow from user input.
		{ 
			return -1;
		}
		else
		{
			bfr[strlen(bfr)-1] = '\0'; //replace newline with null
			executeCommand(bfr);//puts(bfr);
			fputs("$",stderr);
		}
	}
		return 0;
}
//	**parse its single parameter into space-seperated tokens using the strtok**
//--------------------------------------------------------------
//--------------------------------------------------------------
void executeCommand(char *str)
{
	char current_dir_path[PATHLEN]; 
	int command_count = numberOfCommands(bfr);
	char *args[command_count];
	int i =0;
	char *p = strtok (str," ");
	while (p != NULL)
	{
		args[i++] = p;
		p = strtok (NULL, " "); 
	}
//--------------------------------------------------------------
//--------------------------------------------------------------
	if (strcmp(args[0], "exit") == 0) 
	{
	  exit(0);
	} 
//	**CD COMMAND**
//---------------------------------------
//---------------------------------------
	else if (strcmp(args[0], "cd") == 0)
	{
		if(command_count >=2) // makes sure cd also contains a path name.
		{
			if(chdir(args[1]) == 0)//checks that directory user attempted to cd to exists 0 ==true
			{
				printf("%s\n",getcwd(current_dir_path, PATHLEN)); 
			}
			else //if directory is not found prints error message including failed directory name. 
			{
			printf("%s:No such file or directory\n",args[1]);
			}
		}
	}
//---------------------------------------
//---------------------------------------
	else if (strcmp(args[0], "history") == 0)
	{
		//print_history();
	}
	else //command is unrecognized  
	{
		for (int index=0;index < command_count;index++)
		{
			printf("args[%d] %s\n",index,args[index]);		
		}		
	}
}
//	**calculates the number of commands read in from a pointer**
//--------------------------------------------------------------
//--------------------------------------------------------------
int numberOfCommands(char *str1) 
{
	char copy[strlen(str1)];
	strncpy(copy,str1,strlen(str1));
	int command_count = 0;
	char delim[] = " ";
	char* token1;

	for (token1 = strtok(copy, delim); token1; token1 = strtok(NULL, delim)) 
	{
   		command_count+=1;
	}
	return command_count;
}

