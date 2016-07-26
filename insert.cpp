#include "lib.h"

int insertTrip(tripList** head, trip data)
{
     tripList *temp = (tripList *)malloc(sizeof(tripList));

     if (temp == NULL) {
               printf ("Nqma dostatychno pamet\n");
               return false;
     }
	 temp->d.day = data.d.day;
	 temp->d.month = data.d.month;
	 temp->d.year = data.d.year;
     strcpy(temp->unikalen_kod,data.unikalen_kod);
     temp->cena = data.cena;
     temp->dni = data.dni;

     if (*head==NULL) {
        temp->next = NULL;
     }
     else {
          temp->next = *head;
     }
     *head = temp;
     return true;
}
