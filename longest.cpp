#include "lib.h"


tripList *longest(tripList* head)
{
	tripList *view=head;
    while(view)
	{
	if(view->dni>view->next->dni)return view;
	else return view->next;
	view=view->next;
	}
	return NULL;

}
