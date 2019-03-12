#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
ifstream f("Date.txt");

struct coada_prioritati
{
    int val,prior;
    struct coada_prioritati *next;
};

void push(struct coada_prioritati *&prim, struct coada_prioritati *&ultim)
{  int x,p;
    cout<<"Da";
   struct coada_prioritati *c=new coada_prioritati;
   f>>x>>p;
   c->val=x; c->prior=p;
   if(prim==NULL)
   {  c->next=NULL;
      prim=ultim=c;
   }
   else
    if(ultim->prior<=p)
   {
       c->next=NULL;
       ultim->next=c;
       ultim=c;
   }
   else
    if(prim->prior>=p)
   {
       c->next=prim;
       prim=c;

   }
   else
    {   struct coada_prioritati *q=prim;
         cout<<"Da";
        while(q->next->prior<=p)
            q=q->next;

        c->next=q->next;
        q->next=c;
         cout<<"Da";
    }

}


int pop( struct coada_prioritati *&prim,  struct coada_prioritati *&ultim)
{  struct coada_prioritati *aux, *c=prim;
 if(prim!=NULL)
   {   int minim=INT_MAX;
          while(c!=NULL)
          {
              if(c->prior<minim)
                minim=c->prior;
              c=c->next;
          }

          if(prim->prior==minim)
        {

        int x=prim->val;
        aux=prim;
        prim=prim->next;
        delete aux;
        return x;
          }
          else
        {
          c=prim;
         while(c->next->prior!=minim)
             c=c->next;

          if(c->next->val==ultim->val)
            ultim=c;
          int x=c->next->val;
          aux=c->next;
          c->next=c->next->next;
          delete aux;

          return x;
        }
    }
  else
    return -1;

}

void afisare (struct coada_prioritati *prim)
{ struct coada_prioritati *c=prim;

 while (c!=NULL)
 {
     cout<<c->val<<"  ";
     c=c->next;
 }
cout<<" \n";

}


int main()
{  struct coada_prioritati *prim=NULL, *ultim=NULL;
   char s[50];

   while(f>>s)
   {   cout<<"Da";
        if(strcmp(s,"push")==0)
         push(prim,ultim);
       if(strcmp(s,"pop")==0)
            {int x=pop(prim,ultim);
             if(x!=-1)
                {cout<<"Elementul scos din coada este " <<x<<" \n";
                  cout<<"Noua coada este: ";
                  afisare(prim);
                }
             else
                cout<<"Coada goala\n";
            }
         if(strcmp(s,"afisare")==0)
                afisare(prim);

   }



    return 0;
}
