#include "lib.h"

void deleteList(tripList**head)
{
     tripList *p, *temp;

     for (p=*head;p!=NULL; ) {
         temp = p;
         p=p->next;
         free(temp);
     }
     *head = NULL;
}

