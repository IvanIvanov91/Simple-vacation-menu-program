#include "lib.h"

int writeIntoFile(tripList* head)
{
     FILE *file;
     tripList *p;
     char buff[50];
     if (head == NULL) {
              printf ("Spisykyt e prazen\n");
              return false;
     }
	 else p=head;

	 printf("Vyvedete ime na izhodqshtiq fail: ");
	 scanf("%s",&buff);
     	 {
     if ((file = fopen(buff,"wb")) == NULL) {
               printf("Failyt ne moje da se otvori\n");
               return false;
     }
     for (p=head;p!=NULL;p=p->next) {

		 fwrite(p,1,sizeof(tripList),file);
     }
     fclose(file);
	 }

     return true;
}
