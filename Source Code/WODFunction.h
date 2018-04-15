#include<time.h>

void wordOfTheDay(struct node* root)	//This function prints the word of the day.
{
    time_t t;
    time(&t);

    FILE *fptr = NULL;
    FILE *fp=NULL;
    char com[15],c[15],cc[12],con[15],ch[15];
    int flag=0,i;
    fptr=fopen("t_date.txt","r");
    fp=fopen("t_date.txt","r");

    if(fptr==NULL)
    {
        printf("ERROR OPENING FILE\n");
        return;
    }
    else
    {
        fgets(ch,11,fptr);	//the first 12 character(which contain the date and day) are stored in ch
        fclose(fptr);
    }
    for(i=0;i<10;i++)		//the first 12 characters of ctime are stored in cc
    {
        cc[i]=ctime(&t)[i];
    }
    printf("\nToday's Date: ");
    for(i=0;i<10;i++)
    {
        printf("%c",cc[i]);
    }
    printf("\n\n");
    for(i=0;i<10;i++)
    {
        if(ch[i]!=cc[i])	//the corresponding characters of ch and ch are checked and if they differ then that means the date  vary and hence flag is set to 1.
        {
            flag=1;
        }
    }

    if(flag==0)		//if flag=0 then that means that the date is same and hence the word is fetched from the file t_date and printed.
    {
    while(!feof(fp))
    {
    fscanf(fp,"%s",c);	//The word is stored in c
    }
     printf("\nThe word of the day:%s\n",c);	//the word is printed.
    }
    printData(c);	//The description of the word is printed
}

