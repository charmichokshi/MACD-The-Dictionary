node* getnode()
{
    node* temp=NULL;
    temp=(node *)malloc(sizeof(node));

    if(temp)
    {
        int i;
        temp->fname=NULL;
        for(i=0;i<26;i++)
        {
            temp->alphabets[i]=NULL;
        }
    }
return temp;
}


