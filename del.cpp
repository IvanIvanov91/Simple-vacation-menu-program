#include "lib.h"

int del(tripList** head,char kod[30])
{tripList *view=*head;
 trip *buff,in;

 buff=(trip *)malloc(sizeof(trip));
  if (buff == NULL) {
               printf ("Nqma dostatychno pamet\n");
               exit(1);
     }
	int i=0,j,k,found=-1;
	do
	{
		(buff+i)->d.day=view->d.day;
		(buff+i)->d.month=view->d.month;
		(buff+i)->d.year=view->d.year;
		strcpy((buff+i)->unikalen_kod,view->unikalen_kod);
		(buff+i)->cena=view->cena;
		(buff+i)->dni=view->dni;
		i++;
		view=view->next;
		buff=(trip*)realloc(buff,(i+1)*sizeof(trip));
	} while (view);

	fflush(stdin);
	for (j=0;j<i;j++)
		if (strcmp((buff+j)->unikalen_kod,kod)==0)
			found=j;
	if (found==-1)
		{printf("\nNe e namerena ekskurziq s tozi kod!\n");
		exit(1);}
	else{
	*head=NULL;
	for (k=0;k<i;k++)
		if (strcmp((buff+k)->unikalen_kod,kod)!=0)
		{
			in=*(buff+k);
			insertTrip(head,in);

		}
	}

 return 0;
}
