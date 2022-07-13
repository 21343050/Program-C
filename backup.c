/*
	Code by : Heri Ramadhan
	NIM		: 21343050
	Prodi	: Informatika (NK)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h> 

//pendeklarasian fungsi
void judul(); //judul
void menu(); //menu
void entryPeserta(); //input data peserta
void viewPeserta(); //melihat hasil data pertandingan
void urutData(); // untuk lakukan urutkan data

//pendeklarasian struct
typedef struct Peserta {
	char nama[25];
	char id[25];
} Peserta;

typedef struct Benteng {
	double p;
	double l;
	double t;
	double luas;
} Benteng;

typedef struct node {
	Peserta peserta;
	Benteng data;
	struct node *next;
	// struct tree *right, *left;
} node;

struct bin_tree {
int data;
struct bin_tree * right, * left;
};
typedef struct bin_tree nod;

struct node *head=NULL;

int length() {
	int length=0;
	struct node *current;

	for(current=head; current !=NULL; current=current->next) {
		length++;
	}

	return length;
}
void insert(nod ** tree, int val) {
    nod *temp = NULL;
    if(!(*tree))
    {
        temp = (nod *)malloc(sizeof(nod));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}
 

//insert link at the first location
	void createPeserta(Peserta peserta, Benteng data) {

	//create a link
	struct node *link=(struct node*) malloc(sizeof(struct node));

	link->peserta=peserta;
	link->data=data;

	//point it to old first node
	link->next=head;

	//point first to new first node
	head=link;
}


void judul() {
	printf("----------------------------------------------------------\n");
	printf(" Nama Lengkap\t\t: Heri Ramadhan\n");
	printf(" NIM\t\t\t: 21343050\n");
	printf(" Program Studi\t\t: INFORMATIKA\n");
	printf(" Universitas\t\t: UNIVERSITAS NEGERI PADANG\n");
	printf("----------------------------------------------------------\n");
	printf("\t\t   Ujian Tengah Semester\n");
	printf("----------------------------------------------------------\n\n");
	printf("----------------------------------------------------------\n");
	printf("\t   Program Perlombaan Benteng Pertahanan\n");
	printf("----------------------------------------------------------\n");
	printf(" Tekan tombol enter...");
	getch();
}

void menu() {
	system("cls");
	int noMenu;

	printf("\n----------------------------------------------------------\n");
	printf("\n|MENU--> Perlombaan Benteng Pertahanan| Pilih (1 - 4)\n");
	printf("   1. Entri Identitas Peserta\n");
	printf("   2. Daftar Peserta Beserta Hasil Pertandingan\n");
	printf("   3. Daftar Juara Lomba\n");
	printf("   4. Keluar\n\n");
	printf("----------------------------------------------------------\n");
	printf(" Masukkan Nomor Pilihan\t\t: ");
	scanf("%i", &noMenu);
	printf("----------------------------------------------------------\n\n");

	switch (noMenu) {
		case 1:
			system("cls");
			printf("----------------------------------------------------------\n");
		entryPeserta();
		printf(" Tekan enter untuk kembali ke Manu Pilihan...\n");
		getch();
		menu();
		break;
		case 2:
			system("cls");
			printf("----------------------------------------------------------\n");
			printf("\t2. Daftar Peserta Beserta Hasil Pertandingan\n\n");
		viewPeserta();
		printf(" Tekan enter untuk kembali ke Manu Pilihan...\n");
		getch();
		menu();
		break;
		case 3:
			system("cls");
			printf("----------------------------------------------------------\n");
			printf("\t3. Daftar Juara Dari Pertandingan\n\n");
		urutData();
		viewPeserta();
			printf(" Tekan enter untuk kembali ke Manu Pilihan...\n");
		getch();
		menu();
		break;
		case 4:
			system("cls");
			printf("Keluar dari Program\n");
			printf("Terima kasih... Tekan Enter");
		getch();
		exit(1);
		break;
		default:
			system("cls");
			printf("Pilihan anda tidak ada\n");
			printf("Tekan Enter.. Untuk Kembali Ke Menu!");
		getch();
		menu();
		break;
	}
}

void entryPeserta() {
	Peserta peserta;
	Benteng data, luas;

	printf("\t\t1. Entri Identitas Peserta\n\n");

	//identitas peserta
	printf(" Masukkan nama Peserta\t\t: ");
	scanf("%s", &peserta.nama);
	fflush(stdin);
	printf(" Masukkan Nomor Peserta\t\t: ");
	scanf("%s", &peserta.id);
	fflush(stdin);

	//data pertandingan
	printf(" Panjang Benteng\t\t: ");
	scanf("%lf", &data.p);
	printf(" Lebar Benteng\t\t\t: ");
	scanf("%lf", &data.l);
	printf(" Tinggi Benteng\t\t\t: ");
	scanf("%lf", &data.t);

	//proses data pertandingan
	data.luas=2*(data.p*data.l)+2*(data.p*data.l)+2*(data.t*data.l);
	createPeserta(peserta, data);


	printf("----------------------------------------------------------\n");
	printf(" Entri Data selesai... Tekan enter...\n");
	getch();
}

void viewPeserta() {

	printf("----------------------------------------------------------\n");
	printf(" NO.\tNOMOR PESERTA\tNAMA PESERTA\tHASIL PERTANDINGAN\n");
	printf("----------------------------------------------------------\n");

	//start from the beginning
	struct node *ptr=head;
	int i=1;

	while(ptr !=NULL) {
		printf(" %d\t%s\t\t%s\t\t%.2f \n", i, ptr->peserta.id, ptr->peserta.nama, ptr->data.luas);
		ptr=ptr->next;
		i++;
	}

	printf("----------------------------------------------------------\n");
	printf(" Info Data selesai... Tekan enter...\n");
	getch();

}

void urutData() {
	int i, j, k;
	Benteng tempData;
	Peserta tempPeserta;
	struct node *current;
	struct node *next;

	int size=length();
	k=size;

	for (i=0; i < size - 1; i++, k--) {
		current=head;
		next=head->next;

		for (j=1; j < k; j++) {
			if (current->data.luas < next->data.luas) {
				tempData=current->data;
				current->data=next->data;
				next->data=tempData;

				tempPeserta=current->peserta;
				current->peserta=next->peserta;
				next->peserta=tempPeserta;
			}

			current=current->next;
			next=next->next;
		}
	}
}

	int main() {
	system("cls");
	char jawab='Y';
	judul();
	do {
		system("cls");
		menu();
		printf("\nKembali ke Menu Pilihan (Y/T)?: ");
		jawab=getche();
	}
	while ((jawab)=='Y');
	printf("\nTerima kasih...");
	getch();
	return 0;
}