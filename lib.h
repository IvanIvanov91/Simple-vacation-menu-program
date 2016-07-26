#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#include<Windows.h>
typedef struct date
{       int day;
        int month;
		int year;
		date ()
		{
		day=0;
		month=0;
		year=0;
		}

}d;
typedef struct {
        char unikalen_kod[50];
        float cena;
        int dni;
		date d;
} trip;
typedef struct node {
        char unikalen_kod[50];
        float cena;
        int dni;
		date d;
        struct node* next;
} tripList;


int insertTrip(tripList** head, trip data);
void deleteList(tripList**head);
tripList *longest(tripList* head);
int expired(tripList *head,int den,int mesec,int godina);
void view_trips(tripList* head);
int del(tripList** head,char kod[30]);
int checkCorr(char *buf);
int writeIntoFile(tripList* head);
