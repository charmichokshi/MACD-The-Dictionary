#define CHAR_TO_INDEX(c) ((int)c-(int)'a')

void search_similar(node* root,char* key)	//This function searches for similar words corresponding word stored in variable key.
{
//variable declaration
    int level;
    int length=strlen(key);
    int index;
    int i,j,flag=0,len;
    node *temp=root;
    node *temp1=root;
    node *free=root;
    char c;
    int cnt=0;

    if(length==1)	//if the length is 1 then no similar words are found
    {
        printf("NO SIMILAR WORDS FOUND\n");
        return;
    }

     for(level=0;level<length-2;level++)
    {
            index = CHAR_TO_INDEX(key[level]);
            if(temp->alphabets[index])
            temp=temp->alphabets[index];
            else
            flag=1;
    }
     index = CHAR_TO_INDEX(key[level]);
     if(temp->alphabets[index])
     temp = temp->alphabets[index];
     else
        flag=1;

    if(flag!=1)	//if the flag is not 1 that means the nodes above it exists.
    {
        printf("\nSuggested Words are...\n");
     for(i=0;i<26;i++) 	//loop checks which of the 26 characters exists.
     {
        if(temp->alphabets[i])	//if temp->alphabets[i] exists then the variables following it are printed.
         {
             for(len=0;len<=length-2;len++)	//This loop prints the characters common to all the similar words
         {
             printf("%c",key[len]);
         }
             c = i+'a';	//the ASCII value of character at i is stored in c.
             printf("%c",c);
             free=temp->alphabets[i];
             while(free && cnt==0)	//this prints the letters which exists and which are below i in terms of level
             {
                 for(j=0;j<26;j++)
                 {
                     if(free->alphabets[j])
                     {
                         printf("%c",j+'a');
                     }
                     if(free->alphabets[j])
                     {
                        free=free->alphabets[j];
                      }
                     else if(!free->alphabets[j])
                     {
                         cnt=1;
                     }
                 }
             }
             printf("\n");
         }
         cnt=0;
     }
    }
     if(flag==1)
     {
         printf("SIMILAR WORDS NOT FOUND\n");
     }
}
