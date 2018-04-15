#include<stdio.h>

void printHistory()	//this function prints the contents of history file.
{
    FILE *fptr = NULL;
    char ch;
    char ext[5];
    char fn[10] = "history";

    strcpy(ext, ".txt");	// ".txt" is stored in ext
    strcat(fn, ext);		// concating fn and ext

    if((fptr=fopen(fn,"r")) == NULL)
    {
        printf("\nERROR OPENING %s FILE!!\n", fn);
    }
    else
    {
        printf("\n");
        ch = fgetc(fptr);	//The first character of file is stored in ch.
        while (ch != EOF)	//Iterates while the end of the file is not found.
        {
            printf ("%c", ch);
            ch = fgetc(fptr);	//The next character is stored in ch.
        }
        fclose(fptr);
        printf("\n\n");
    }
}

void addHistory(char key[10])	//This function adds a word in history file.
{
    FILE* fp = NULL;

    fp=fopen("history.txt","a");

    if(fp==NULL)
    {
        printf("An error occoured!");
    }
    else
    {
        fprintf(fp, "%s\n", key);	//Adding key in history file.
    }
    fclose(fp);
}
