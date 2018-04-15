#define CHAR_TO_INDEX(c) ((int)c-(int)'a')
#include "getNodeFunction.h"

void insert(node* root,char* key)	//This function inserts a word in the dictionary.
{
    int level;
    int length =strlen(key);	//The length of the string is stored in length.
    int index;

    node *temp=root;

    for(level=0; level<length ; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if(!temp->alphabets[index])
        {
            temp->alphabets[index] = getnode();	//Each alphabet node is alloted memory.
        }
        temp=temp->alphabets[index];
    }

    temp->fname= key;		//The filename is stored in fname field.
}

void insert_word(char key[10])	//This function inserts a new word in the dictionary.
{
    char ext[5];
    struct meaning record;
    FILE* fptr=NULL;
    FILE* fp = NULL;
    FILE* file = NULL;

    fp=fopen("words.txt","a");

    if(fp==NULL)
    {
        printf("An error occoured!");
    }
    else
    {
        fprintf(fp, "\n%s", key);
    }
    fclose(fp);

    strcpy(record.word, key);	//stores the key in record.word
    strcpy(ext, ".txt");		//stores ".txt" in ext
    strcat(key, ext);			//concates key and ext

    char meaning[100];
    char partOfSpeech[20];
    char definition[500];
    char example[100];
    char synonyms[50];
    char antonyms[50];

    fptr=fopen(key,"w");
    file= fopen("translation.dat", "ab");

    if(fptr==NULL || file==NULL)
    {
        printf("An error occoured!");
    }

    else	//The description of the new word is stored in their respective variables
    {
        printf("\n\tEnter Meaning of the Word: ");
        scanf("\n");
        gets(meaning);

        printf("\n\tEnter which Part of Speech it belongs to: ");
        scanf("\n");
        gets(partOfSpeech);

        printf("\n\tEnter Full Definition of the Word: ");
        scanf("\n");
        gets(definition);

        printf("\n\tEnter Example of the Word: ");
        scanf("\n");
        gets(example);

        printf("\n\tEnter Synonyms of the Word: ");
        scanf("\n");
        gets(synonyms);

        printf("\n\tEnter Antonyms of the Word: ");
        scanf("\n");
        gets(antonyms);

        printf("\n\tEnter French Translation of Word: ");
        scanf("%s", record.french);

        printf("\n\tEnter Spanish Translation of Word: ");
        scanf("%s", record.spanish);

	  //the content is stored in file
        fprintf(fptr, "MEANING:\n%s", meaning);
        fprintf(fptr, "\nThis is %s.\n", partOfSpeech);
        fprintf(fptr, "\nFULL DEFINITION:\n%s\n", definition);
        fprintf(fptr, "\nEXAMPLE:\n%s\n", example);
        fprintf(fptr, "\nSYNONYMS:\n%s\n", synonyms);
        fprintf(fptr, "\nANTONYMS:\n%s", antonyms);

        fwrite(&record, sizeof(struct meaning), 1, file);	//The record is stored in file
        fclose(file);
        fclose(fptr);
    }
}

