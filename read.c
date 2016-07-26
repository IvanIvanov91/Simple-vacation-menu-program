#include "lib.h"

bool readFromFile(char *fname, tripList** head)
{    int br;
     int read;
     char text[128]="";
     FILE *file;
     trip temp;
     if ((file = fopen(fname,"rb")) == NULL) {
               printf("Can't open file\n");
               return false;
     }


	while (!feof(file)) {
		tripList data;

		br=fread(&data,1,sizeof(tripList),file);

		if (br<sizeof(tripList)) {
			continue;
		}
		temp.d.day = data.d.day;
	    temp.d.month = data.d.month;
	    temp.d.year = data.d.year;
        strcpy(temp.unikalen_kod,data.unikalen_kod);
        temp.cena = data.cena;
        temp.dni = data.dni;


	   insertTrip(head,temp);
	}

     fclose(file);
     return true;
}
