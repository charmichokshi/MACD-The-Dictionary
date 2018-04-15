#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>
#include<conio.h>
#include "trieNode.h"
#include "transNode.h"
#include "historyFunctions.h"
#include "transFunction.h"
#include "insertFunctions.h"
#include "searchSimilarFunction.h"
#include "WODFunction.h"
#include "searchFunction.h"

/**
THIS CODE CONTAINS THE MAIN FUNCTION OF OUR PROJECT.
*/


//Main function of our code
void main()
{
    //Variable declaration

    FILE *fptr,*fp,*fr,*frand;         //Declaration of file pointers
    char c[15],newWord[15],wordSearch[15],a[15],wor[256],cc[12],ch[15],ra[2],ra1[2];     //Declaration of character arrays
    int choice,i=0,f=0,password,cnt=0,key,checkPassword = 12345,j,r;        //Declaration of integers
    node *root=getnode();       // The root of the trie is made

    /*
      In the code given below we insert all the words present in words.txt file in the TRIE data structure and if their is
       some problem in opening the file then an appropriate message is printed.

    */

    if((fptr=fopen("words.txt","r"))==NULL) //Checks if it is possible to open the file in read mode if the file cannot be opened in read mode then the following message is printed.
    {
        printf("***ERROR OPENING FILE\n");  //This message is printed if words.txt file cannot be opened in read mode
    }
    else        //If it is possible to open the file words.txt in read mode then the following code is executed
    {
        while(fscanf(fptr,"%s",c)!=EOF)       //Reads each word from the file while the pointer does not reach the end of the file and stores each word in c
        {
            insert(root,c);     //insert function is called which stores each word stored in variable c in TRIE data structure
        }
        fclose(fptr);   //Closing the file
    }

    /*
        In the following code we generate word of the day

    */

    if((fptr=fopen("t_date.txt","r"))==NULL)    //Checks if it is possible to open the file in read mode if the file cannot be opened in read mode then the following message is printed.
    {
        printf("******ERROR OPENING FILE\n");   //This message is printed if words.txt file cannot be opened in read mode
    }
    else        //If it is possible to open the file t_date.txt in read mode then the following code is executed
    {
        time_t t;
        time(&t);
        fr=fopen("t_date.txt","r");

        for(i=0;i<10;i++)   //The first 12 characters of ctime contain today's date and day so we store the first 11 characters in cc(character array)
        {
            cc[i]=ctime(&t)[i];
        }

        fgets(ch,11,fr);    //From the file "t_date.txt" first 12 characters are read
        fclose(fr);

        for(i=0;i<10;i++)       //Here we check if the first 12 characters of cc and ch are equal or not
        {
            if(cc[i]!=ch[i])    //Even if one of the character is different then f is assigned 1(which signifies that the date in the file and the present date are not equal)
            {
                f=1;
            }
        }


        if(f==1)    //If the present date and the date in the file are different then the following code is executed
        {
        fptr=fopen("t_date.txt","w");   //"t_date.txt" is opened in write mode in order to change the date and word present in the file
        fprintf(fptr,"%s",ctime(&t));   //The present date and time is written in "t_date.txt" file

        frand = fopen("random.txt","r");    //The random.txt file is opened in read mode
        fscanf(frand,"%s",ra);      //the string is read from file
        r=atoi(ra);     //the string fetched from file is converted into integer
        fclose(frand);

        frand = fopen("random.txt","w");    //The random.txt file is opened in write mode
        itoa((r+1),ra1,10);     //The integer(r+1) is converted into character
        fprintf(frand,"%s",ra1);    //The string is written back into file
        fclose(frand);

        if((fp=fopen("words.txt","r"))==NULL)
        {
            printf("ERROR OPENING FILE\n");
        }
        else
        {
            i=0;
            while(fscanf(fp,"%s",c)!=EOF && i<r)    //The words are read till the position r is not reached.The last word that will be stored in c will be in position r
            {
                i++;
            }
            fprintf(fptr, "%s", c);     //The word stored in c is stored in the file "t_date.txt" which becomes the word of the day
            fclose(fptr);
            fclose(fp);
         }
    }
 }


    printf("\n\t***WELCOME TO THE 'MACD' DICTIONARY***\n");

    do
    {
        //MENU
        printf("\n~~~MENU~~~\n");
        printf("\n1. Search Meaning");
        printf("\n2. Add new Word in the Dictionary");
        printf("\n3. View Search History");
        printf("\n4. Word of the day");
        printf("\n5. Translation of word");
        printf("\n0. Exit");

        printf("\n\nEnter your Choice: ");
        scanf("%d", &choice);   //choice is stored in choice variable

        switch(choice)
        {
            case 1:     //If choice is 1 then the following code is executed
                cnt = 0;    //cnt variable is used to check if the word is present in history file

                printf("\n\tENTER THE WORD YOU WANT TO SEARCH: ");
                scanf("%s", wordSearch);

                if((fp = fopen("history.txt","r"))==NULL)
                {
                    printf("***ERROR OPENING FILE\n");
                }

                else
                {
                    while(fscanf(fp,"%s",c) != EOF)     //The history file is read line by line and each word is stored in variable c
                    {
                        if(strcmp(wordSearch, c) == 0)  //if the word present in the history file matches with c then the contents of the meaning of the file is printed directly
                        {
                            printData(wordSearch);  //prints the data present in wordSearch file
                            cnt++;
                        }
                    }
                    fclose(fp);
                }

                if(cnt == 0)    //cnt is 0 if the word is not found in history file
                {
                    if(search(root, wordSearch))    //The word is searched from TRIE
                    {
                        addHistory(wordSearch);     //If the word is present in TRIE then the word is added to history file
                        printData(wordSearch);      //The description of the word is printed
                    }

                    else
                    {
                            printf("\n\t***WORD NOT FOUND***\n");   //If the word is not found then the following statement is printed

                            search_similar(root, wordSearch);   //some suggestions for similar words are provided by calling the search_similar function
                    }

                }
            break;

            case 2:
                printf("\n\tEnter Password to add New Word into Dictionary: ");
                scanf("%d", &password);

                if(password == checkPassword)       //If the entered password and the stored actual password match then the user can enter a new word
                {
                    printf("\n\tEnter a new Word:");
                    scanf("\n");
                    gets(newWord);

                    insert(root, newWord);  //The new word is inserted in TRIE
                    insert_word(newWord);   //insert_word function is called to enter the description of the word.
                }

                else
                    printf("\nINVALID PASSWORD!!\n");

            break;

            case 3:

                printf("\n\nSEARCH HISTORY\n\n");
                printHistory(); //This function prints the words in the history file

            break;
            case 4:

                wordOfTheDay(root); //The word of the day is printed

            break;

            case 5:

                printf("\nChoice Menu: \n1. French Transaltion \n2. Spanish Translation");
                printf("\n\nEnter Your choice: ");
                scanf("%d", &key);

                wordRead("translation.dat", key);   //The french translation and apanish translation of key can be accessed by callinf wordRead function
                break;

            case 0:
            break;

            default:
                printf("\nINVALID CHOICE!!\n");
            break;
        }
    }while(choice != 0);

    printf("\n\t***THANK YOU FOR USING 'MACD' DICTIONARY***\n\n\n");
}
