#include<stdio.h>
#include<string.h>
#include <errno.h>
#include <unistd.h>
#include<stdlib.h>
#include "smash.h"
void init_history(void); //builds data structures for recording cmd history
void add_history(char *cmd, int exitStatus); //Adds an entry to the history
void clear_history(void); //Frees all malloc'd memory in the history
void print_history(int firstSequenceNumber); //Prints the history to stdout

void executeCommand(char *str)
{
	
	char current_dir_path[100]; 
	char *args[1000];
	int i =0;
	
	char *p = strtok (str," ");
	while (p != NULL)
	{
		args[i++] = p;
		p = strtok (NULL, " "); 
	}
	int command_count =i;
//--------------------------------------------------------------
//--------------------------------------------------------------
	

	if (strcmp(args[0], "exit") == 0) 
	{
	  
	  clear_history();
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
				add_history(*str,1);
				printf("%s\n",getcwd(current_dir_path, 100)); 
				
				
			}
			else //if directory is not found prints error message including failed directory name. 
			{
				printf("the value of str is %s\n",str); 
			add_history("cd",127);
			printf("%s:No such file or directory\n",args[1]);
			}
		}
	}
//---------------------------------------
//---------------------------------------
	else if (strcmp(args[0], "history") == 0)
	{
		if(command_count == 1)
		{
			add_history(str,1);
			printf("the value of str is %s\n",str); 
			print_history(0);
		}
		else if(command_count > 1)
		{
			//if user specifies how much of the sequence.
		}
	}
	else //command is unrecognized  
	{	
		add_history(str,127);
		for (int index=0;index < command_count;index++)
		{
			
			printf("[%d] %s\n",index,args[index]);		
		}		
	}
}
//	**calculates the number of commands read in from a pointer**
//--------------------------------------------------------------
//--------------------------------------------------------------

