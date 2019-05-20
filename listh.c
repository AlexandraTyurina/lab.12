#include "list3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 60
// -------------------------------------------------------
Node2 *CreateNode3()
{
    Node2 *NewNode=NULL;
    int slen;
    char **s2=NULL;
    char *s1;
    char sep=';';
    NewNode = (Node2*)malloc(sizeof(Node2));
    s1 = (char*)malloc(MAXLEN*sizeof(char));
    if(NewNode&&s1)
    {
        NewNode->id = 1;
        getchar();
        printf ("Enter your data:\n");
        fgets(s1, MAXLEN, stdin);
        slen=strlen(s1);
        s1[slen-1]='\0';
        slen=strlen(s1);
        s2=simple_split(s1,slen,sep);//ïàìÿòü âûäåëÿåòñÿ â ôóíêöèè
        if(s2!=NULL)
        {
            NewNode->comp=struct_fill(s2);
        }
        else puts("Error at data reading!");
        NewNode->comp=struct_fill(s2);
        NewNode->prev = NULL;
        NewNode->next = NULL;
    }
    free(s1);
    s1=NULL;
    return NewNode;
}
// -------------------------------------------------------
void addition_elemF (Head *p0, Node2 *g1,Node2 *g)
{
    Node2 *NewNode=NULL;
    NewNode = CreateNode3();
    g1=p0->last;
    g=g1->prev;
    g1->prev=NewNode;
    NewNode->next=g1;
    g->next=NewNode;
    NewNode->prev=g;
}
// -------------------------------------------------------
void addition_elemN (Head *MyHead)
{
    Node2 *NewNode=NULL;
    NewNode=CreateNode3();
    MyHead->first = NewNode;
    MyHead->last = NewNode;
    NewNode->next=NewNode;
    NewNode->prev=NewNode;
}
