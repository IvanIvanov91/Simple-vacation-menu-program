#include "lib.h"

void view_trips(tripList* head)
{tripList *view=head;
int i=1;
if(view==NULL)printf("\nNqma ekskurzii!\n");
else {
printf("\n Data na zaminavane | Kod | Tsena | Prodyljitelnost \n");
while(view)
{
	if(view->d.day<10 && view->d.month<10)printf("%d). 0%d.0%d.%d | %10s | %f | %10d\n",i,view->d.day,view->d.month,view->d.year,view->unikalen_kod,view->cena,view->dni);
	else if(view->d.day<10)printf("%d). 0%d.%d.%d | %10s | %f | %10d\n",i,view->d.day,view->d.month,view->d.year,view->unikalen_kod,view->cena,view->dni);
	else if(view->d.month<10)printf("%d). %d.0%d.%d | %10s | %f | %10d\n",i,view->d.day,view->d.month,view->d.year,view->unikalen_kod,view->cena,view->dni);
    else printf("%d). %d.%d.%d | %10s | %10lf | %10d\n",i,view->d.day,view->d.month,view->d.year,view->unikalen_kod,view->cena,view->dni);
i++;
view=view->next;
}
}
}
