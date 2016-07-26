#include "lib.h"

int main(int argc, char *argv[])
{

    tripList *head=NULL;
	tripList *tmp;
    trip temp;
    int choice,schoice,tchoice,flag,flag2;

    while(1) {
      system("cls");
      printf("Menu\n");
      printf("1. Dobavqne na ekskurziq\n");
	  printf("2. Iztrivane dannite na ekskurziq s posochen kod\n");
	  printf("3. Izvejdane dannite za nai-dylga ekskurziq\n");
	  printf("4. Izvejdane info za ekskurziite s iztekla data na zaminavane\n");
	  printf("5. Pokazvane na vsichki ekskurzii\n");
      printf("6. Zapis vyv fail\n");
      printf("0. Izhod\n");
      printf("Izberi: ");
      scanf("%d",&choice);

      switch(choice) {
        case 1:
			{
					do
					{

						//printf("\n\n1. Chetene ot fail");
						printf("\n2. Dobavqne na ekskurziq\n");
						printf("3. Izhod\n");
						printf("\nIzberi: ");
						scanf("%d",&schoice);
						switch(schoice)
						{
							case 2:
								{

                              do{
							 fflush(stdin);
                             printf("Mesec:");
                             flag2=scanf("%d",&temp.d.month);

                             }while(temp.d.month<1 || temp.d.month>12 || flag2!=1);
                             do{
							  fflush(stdin);
                              printf("Den:");
                              flag2=scanf("%d",&temp.d.day);
                              if ((temp.d.month==2) && (temp.d.day>28)) {printf ("Greshna data\n");
                              return 1;}
                              if ((temp.d.month==4 || temp.d.month==6 || temp.d.month==9 || temp.d.month==11) && (temp.d.day>30)) {printf ("Greshna data\n");
                              return 1;}
                              }while(temp.d.day<0 || temp.d.day>31 || flag2!=1);
                              do{
                             fflush(stdin);
                             printf("Godina:");
                             flag2=scanf("%d",&temp.d.year);
                             }while(temp.d.year<0 || temp.d.year>5000 || flag2!=1);



                             do{

		              		do
                        	{
	                    	flag=0;
		                    tmp=head;
		                   printf("\nVyveedete kod: ");
		                   scanf("%s",&temp.unikalen_kod);
		                   while(tmp)
		                   {
		                	if (strcmp(tmp->unikalen_kod,temp.unikalen_kod)==0)
			            	flag=1;
		                	tmp=tmp->next;
	                    	}
                        	} while (flag);

			               }
		             	 while(!checkCorr(temp.unikalen_kod));
                         do{
						 fflush(stdin);
						 printf("Prodyljielnost: ");
                         flag2=scanf("%d",&temp.dni);
						 }while(temp.dni<0 || flag2!=1);
						 do{
						 fflush(stdin);
                         printf("Tsena: ");
                         flag2=scanf("%f", &temp.cena);
						 }while(temp.cena<0 || flag2!=1);
                         if (!insertTrip(&head,temp)) {
                         deleteList(&head);
                         exit(1);
                         }
                         break;


								}
							case 3:break;
							default: printf("\n\nGreshen izbor!");
						}
					} while (schoice!=3);
					break;
				}

		case 2:{
			    int exe;
			    char kod[30];
				printf("Vyvedete kod: ");
				scanf("%s",&kod);
				exe=del(&head,kod);


			   }break;

		case 3:{
			       tripList *duration;
				   duration=longest(head);
				   if(duration){
					   printf("%d.%d.%d\t%s\t%f\t%d\n",duration->d.day,duration->d.month,duration->d.year,duration->unikalen_kod,duration->cena,duration->dni);
				   }
				   else printf("Nqma takava ekskurziq!\n");

				   }break;
		case 4:{
			       int exkurziq;
				   do
					{

						printf("\n\n1.Vyvedete data");

						printf("\n3. Izhod\n");
						printf("\nIzbor: ");
						scanf("%d",&tchoice);
						switch(tchoice)
						{
						case 1:{
							    int den=0,mesec=0,godina=0;
				                do{
				                fflush(stdin);
                                printf("Den:");
                                flag2=scanf("%d",&den);
                                }while(den<0 || den>31 || flag2!=1);
                                do{
				                fflush(stdin);
                                printf("Mesec:");
                                flag2=scanf("%d",&mesec);
                                }while(mesec<1 || mesec>12 || flag2!=1);
                                do{
				                fflush(stdin);
                                printf("Godina:");
                                flag2=scanf("%d",&godina);
                                }while(godina<0 || godina>5000 || flag2!=1);

				                exkurziq=expired(head,den,mesec,godina);
							    if(exkurziq)printf("Namerena e ekskurziq!\n");
								else printf("Ne e namerena ekskurziq!\n");


							   }break;

							case 3:break;
							default: printf("\n\nGreshen izbor!");
						}
					} while (tchoice!=3);
			   }break;

		case 5: view_trips(head);break;
		case 6:if (!writeIntoFile(head)) {
               deleteList(&head);
               exit(1);
             }
             printf("Zapisyt e gotov");
             break;
        case 0:
             deleteList(&head);
             exit(0);
        default:
             printf("Greshen izbor\n");
        }
        fflush(stdin);
        system("PAUSE");
      }
  return 0;
}
