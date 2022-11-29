#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct railways {
	char name[20];
	char gen[6];
	int age;
	struct railways* link;
} Node;

Node* start = NULL;

void details(int);
int seat(int);
int cal(int, int, int);
void bill(int, int);

char source[20], des[20], train[40];
char station[40], cla[40];
int time1, time2, a[55], total_seat = 60;

void main()
{
	int i, j, a1, a2, b, c, x = 0, d, e, r;
	char o;
    FILE *fp1;
    char open;
    fp1 = fopen("serving.txt", "r");
    open = fgetc(fp1);
    while (open != EOF)
    {
        printf("%c", open);
        open = fgetc(fp1);
    }
    fclose(fp1);
	printf("Enter Number Of Passengers: ");
	fflush(stdin);
	scanf("%d", &j);
	details(j);
	printf("Enter The Source Place: ");
	fflush(stdin);
	gets(source);
	printf("Enter The Destination Place: ");
	gets(des);
	printf("\t\tThe Following Trains Are Available.....\n");
	printf("\t\t1. DNR PUNE EXPRESS(12150).........11:15 p.m........DANAPUR JUNCTION\n");
	printf("\t\t2. DBG PUNE EXPRESS(01043)..........04:45 p.m........DARBHANGA STATION\n");
	printf("\t\t3. NZM VSG SUP SPL(07380)..........9:15 p.m........HAJRAT NIJAMUDDIN STATION\n");
	printf("\t\t4. GKP PUNE EXPRESS(15029).........04:23 p.m........GORAKHPUR JUNCTION\n");
	printf("\t\t5. DURANTO EXPRESS(12246)............07:00 a.m.........SANTRAGACHI STATION\n");
	scanf("%d", &i);
	do {
		switch (i) {
		case 1: {
			strcpy(train,
				"DNR PUNE EXPRESS(12150)");
			strcpy(station,
				"DANAPUR JUNCTION");
			time1 = 23;
			time2 = 15;
			a1 = 2099;
			a2 = 1560;
			d = cal(a1, a2, j);
			printf("Total Bill Amount:"
				" %d\n",
				d);
		}; break;
		case 2: {
			strcpy(train,
				"DBG PUNE EXPRESS(01043)");
			strcpy(station,
				"DARBHANGA STATION");
			time1 = 16;
			time2 = 45;
			a1 = 1801;
			a2 = 981;
			d = cal(a1, a2, j);
			printf("Total Bill Amount:"
				"%d\n",
				d);
		}; break;
		case 3: {
			strcpy(train,
				"NZM VSG SUP SPL(07380)");
			strcpy(station,
				"HAJRAT NIJAMUDDIN STATION");
			time1 = 21;
			time2 = 15;
			a1 = 2199;
			a2 = 1780;
			d = cal(a1, a2, j);
			printf("Total Bill Amount: %d\n", d);
		}; break;
		case 4: {
			strcpy(train, "GKP PUNE EXPRESS(15029)");
			strcpy(station, "GORAKHPUR JUNCTION");
			time1 = 16;
			time2 = 23;
			a1 = 1759;
			a2 = 1200;
			d = cal(a1, a2, j);
			printf("Total Bill Amount: %d\n", d);
		}; break;
		case 5: {
			strcpy(train, "DURANTO EXPRESS(12246)");
			strcpy(station, "SANTRAGACHI STATION");
			time1 = 07;
			time2 = 00;
			a1 = 2205;
			a2 = 1905;
			d = cal(a1, a2, j);
			printf("Total Bill Amount: %d\n", d);
		}; break;
		default:
			printf("Enter Correct choice.....\n");
			x = 1;
			break;
		}
	} while (x);
	printf("Now Book Your Seats......\n");
	seat(j);
	bill(d, j);
}
int cal(int y1, int y2, int h)
{
	int b, c, i, t, r, n;
	printf("\t\tEnter Your Choice......\n");
	printf("\t\t1. Sleeper Class....\n");
	printf("\t\t2. A.C Class.......\n");
	scanf("%d", &i);
	switch (i) {
	case 1: {
		strcpy(cla, "Sleeper Class");
		b = y2 * h;
		c = b + (b * 0.18);
	} break;
	case 2: {
		printf("\t\tEnter Your Choice....\n");
		printf("\t\t1. 3A Class....\n");
		printf("\t\t2. 2A Class....\n");
		printf("\t\t3. 1st Class A.C.....\n");
		scanf("%d", &n);
		switch (n) {
		case 1: {
			strcpy(cla, "3A Class");
			b = y1 * h;
			c = b + (b * 0.18);
		} break;
		case 2: {
			strcpy(cla, "2A Class");
			b = (y1 + 1000) * h;
			c = b + (b * 0.18);
		} break;
		case 3: {
			strcpy(cla, "1A Class");
			b = (y1 + 5000) * h;
			c = b + (b * 0.18);
		} break;
		default: {
			printf("\t\tEnter Right Choice......\n");
		}
		}
	} break;
	default: {
		printf("\t\tEnter Right Choice......\n");
	}
	}
	return c;
}
void details(int k)
{
	int i, a;
	char val[20], gen[6];
	for (i = 1; i <= k; i++) {
		printf("Enter The %dth Passenger Name: ", i);
		fflush(stdin);
		gets(val);
		printf("Enter The %dth Passenger Gender: ", i);
		fflush(stdin);
		gets(gen);
		printf("Enter The %dth Passenger Age: ", i);
		fflush(stdin);
		scanf("%d", &a);
		add_node(val, gen, a);
	}
}
void add_node(char lol[20], char der[6], int b)
{
	Node *newptr = NULL, *ptr;
	newptr = (Node*)malloc(sizeof(Node));
	strcpy(newptr->name, lol);
	strcpy(newptr->gen, der);
	newptr->age = b;
	newptr->link = NULL;
	if (start == NULL)
		start = newptr;
	else {
		ptr = start;
		while (ptr->link != NULL)
			ptr = ptr->link;
		ptr->link = newptr;
	}
}
int seat(int p)
{
	int i;
	printf("\t		 -:SEAT MATRIX:-	 \n");
    for (int j = 1; j <= total_seat; j++)
    {
        printf("%d || ",j);
    }
    printf("\n*********************************\n");
	printf("\tEnter Seat Numbers: \n");
	for (i = 0; i < p; i++)
		scanf("%d", &a[i]);
}
void bill(int y, int j)
{
	int i;
	Node* ptr = start;
    FILE *f1;
    f1=fopen("ticket.txt","a");
    fprintf(f1,"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	for (i = 1; i <= j; i++) {
		printf("\t\t%dst Passenger Name: ", i);
		puts(ptr->name);
        fprintf(f1,"\t\t%dst Passenger Name: %s\n", i,ptr->name);
		printf("\t\t%dst Passenger Gender: ", i);
		puts(ptr->gen);
        fprintf(f1,"\t\t%dst Passenger Gender: %s\n", i,ptr->gen);
		printf("\t\t%dst Passenger Age: %d\n\n", i,ptr->age);
        fprintf(f1,"\t\t%dst Passenger Age: %d\n\n", i,ptr->age);
		ptr = ptr->link;
	}
    fclose(f1);
    f1=fopen("ticket.txt","a");
	printf("\t\tSource Place: ");
	puts(source);
    fprintf(f1,"\t\tSource Place: %s\n",source);
	printf("\t\tDestination Place: ");
	puts(des);
    fprintf(f1,"\t\tDestination Place: %s\n",des);
	printf("\t\tThe Boarding Station: ");
	puts(station);
    fprintf(f1,"\t\tThe Boarding Station: %s\n",station);
	printf("\t\tTrain Is: ");
	puts(train);
    fprintf(f1,"\t\tTrain Is: %s\n",train);
	printf("\t\tAllocated Class: ");
	puts(cla);
    fprintf(f1,"\t\tAllocated Class: %s\n",cla);
	printf("\t\tBoarding Time: %d:%d\n", time1, time2);
	printf("\t\tTotal Bill Amount: %d\n", y);
	printf("\t\tAllocated Seats Are: \n");
	fprintf(f1,"\t\tBoarding Time: %d:%d\n", time1, time2);
	fprintf(f1,"\t\tTotal Bill Amount: %d\n", y);
	fprintf(f1,"\t\tAllocated Seats Are: \n");
	for (i = 0; i < j; i++) {
		printf("\t\t%d ", a[i]);
		fprintf(f1,"\t\t%d ", a[i]);
	}
	printf("\n");
	fprintf(f1,"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	printf("\t\t\t\tThank You......\n");
}
