#include<stdio.h>

void wordRead(char *fileName, int choice)	//This function prints the spanish and french translation of a word
{
//variable declaration
    FILE *fptr= NULL;
    int cnt=0;
    char word[20];
    struct meaning record;

    fptr = fopen(fileName, "rb");

    if(fptr==NULL)
        printf("\nFile dosen't exist!");

    else
    {
        printf("\nEnter Word: ");
        scanf("%s", word);		//The word whose french or spanish translation is to be found is stored in word variable

        fread(&record, sizeof(struct meaning), 1, fptr);	//reads the first record from the file

        while(!feof(fptr))		//iterates till end of file is not found
        {
            if((strcmp(record.word, word)==0))	//if the word from record in the file matches with the word entered by the user then the french or spanish translations are printed according to the choices.
            {
                printf("\n\nGiven word: %s", word);
                if(choice == 1)
                    printf("\n\nFrench Meaning: %s\n", record.french);
                else
                printf("\n\nSpanish Meaning: %s\n", record.spanish);

                cnt++;
            }

            fread(&record, sizeof(struct meaning), 1, fptr);
        }

        if(cnt==0)
            printf("\nUnable to find translation!");
    }
}
