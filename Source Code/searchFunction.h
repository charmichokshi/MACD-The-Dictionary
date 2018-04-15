#include<stdbool.h>

bool search(node *root,char* key)	//this function searches for a word in TRIE and if the word is found then TRUE is returned.
{
    int level,index;
    int length=strlen(key);		//The length of the key is stored in length variable
    node* temp=root;
    for(level=0;level<length;level++)	//The loop works till the length of the word.
    {
            index = CHAR_TO_INDEX(key[level]);
            if(!temp->alphabets[index])	//While accessing the TRIE even if one of the variable does not exist then the following code is executed.
            {
                return false;	//false is returned which shows that the word is not found.
            }
            temp=temp->alphabets[index];	//temp becomes temp->alphabets[index]
    }
    return (temp!=NULL && temp->fname!=NULL);
}

void printData(char key[10])	//This function prints the data present in the file(the name of the file is stored in variable key)
{
    FILE *fptr = NULL;
    char ch;
    char ext[5];

    strcpy(ext, ".txt");	//the string ".txt" is stored in ext
    strcat(key, ext);		//concating key and ext

    if((fptr=fopen(key,"r")) == NULL)
    {
        printf("\nERROR OPENING %s FILE!!\n", key);
    }

    else
    {
        printf("\n");
        ch = fgetc(fptr);	//the first character is read from the file
        while (ch != EOF)	//this loop iterates till the end of the file is not reached
        {
            printf ("%c", ch);	//printing each character from the file 
            ch = fgetc(fptr);	//the next character is fetched from the file
        }
        fclose(fptr);
        printf("\n\n");
    }
}
