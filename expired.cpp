#include "lib.h"


int expired(tripList *head,int den,int mesec,int godina)
{
	tripList *view=head;
    while(view)
	{
	if(view->d.year<godina)printf(" %d.%d.%d | %10s | %10ld | %10d\n",view->d.day,view->d.month,view->d.year,view->unikalen_kod,view->cena,view->dni);
	else if((view->d.year==godina) && (view->d.month<mesec))printf(" %d.%d.%d | %10s  | %10ld | %10d \n",view->d.day,view->d.month,view->d.year,view->unikalen_kod,view->cena,view->dni);
	else if((view->d.year==godina) && (view->d.month==mesec) && (view->d.day<den))printf(" %d.%d.%d | %10s | %10ld | %10d\n",view->d.day,view->d.month,view->d.year,view->unikalen_kod,view->cena,view->dni);
	view=view->next;
	}
	return 1;

}
