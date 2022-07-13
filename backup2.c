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
void update();
int delete_data();

//pendeklarasian struct
typedef struct Peserta {
	char nama[25];
	char id[25];
} Peserta;

typedef struct Benteng {
	int p;
	int l;
	int t;
	double luas;
} Benteng;

struct node {
	Peserta peserta;
	Benteng data;
	struct node *right, *left;
} *awal, *akhir;

struct node *head=NULL;

int length() {
	int length=0;
	struct node *current;

	for(current=head; current !=NULL; current=current->right) {
		length++;
	}

	return length;
}

//insert link at the first location
	void createPeserta(Peserta peserta, Benteng data) {
	struct node *link=(struct node*) malloc(sizeof(struct node));

	link->peserta=peserta;
	link->data=data;

	//point it to old first node
	link->right=head;

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
	printf("   4. Delete Data\n");
	printf("   5. Edit Data\n");
	printf("   6. Keluar\n\n");
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
		printf("----------------------------------------------------------\n");
		printf("\t4. Delete\n\n");
		delete_data();
		printf(" Tekan enter untuk kembali ke Manu Pilihan...\n");
		getch();
		menu();
		break;
		case 5:
		system("cls");
		printf("----------------------------------------------------------\n");
		printf("\t4. Edit\n\n");
		update();
		printf(" Tekan enter untuk kembali ke Manu Pilihan...\n");
		getch();
		menu();
		break;
		case 6:
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
	// Peserta peserta;
	// Benteng data, luas;
	char pilih[2];
	int i=0;
	struct node *save, *first;

	while (1)
	{

	printf("\t\t1. Entri Identitas Peserta\n\n");

	//identitas peserta
	first=(struct node*)malloc(sizeof(struct node));
	printf(" Masukkan nama Peserta\t\t: ");
	scanf("%s", &first->peserta.nama);
	fflush(stdin);
	printf(" Masukkan Nomor Peserta\t\t: ");
	scanf("%s", &first->peserta.id);
	fflush(stdin);

	//data pertandingan
	printf(" Panjang Benteng\t\t: ");
	scanf("%d", &first->data.p);
	printf(" Lebar Benteng\t\t\t: ");
	scanf("%d", &first->data.l);
	printf(" Tinggi Benteng\t\t\t: ");
	scanf("%d", &first->data.t);

	//proses data pertandingan
	first->data.luas=2*(first->data.p*first->data.l)+2*(first->data.p*first->data.l)+2*(first->data.t*first->data.l);
	// createPeserta(peserta, data);

		if(i==0){
		
			first->right=NULL;
			first->left=NULL;
			awal=first;
			save=awal;
			akhir=first;
		}
		else
		{
			save->right=first;
			first->left=NULL;
			first->left=save;
			akhir=first;
			save=first;
		}

		system("cls");
		printf("\n Apakah anda akan memasukkan data peserta lagi? (y/n) "); 
		scanf("%s",&pilih);
		if((strcmp(pilih, "Y")==0)||(strcmp(pilih,"y")==0)){
			i++;
			continue;
		}
		else{
			break;
		}


	printf("----------------------------------------------------------\n");
	printf(" Entri Data selesai... Tekan enter...\n");
	getch();
	}
}

void update()
{
	struct node *upd;
	char nama[30];
	char id[30];
	int p, l, t;
  if( !awal ){
	printf("Data tidak ada/n");
  }else{
	printf("Masukkan Nama Pengganti %s: \n-> ", awal->peserta.nama);
	scanf("%s", &awal->peserta.nama); fflush(stdin);
	char nama = upd;
	upd = awal->peserta.nama;
	printf("\nNama Berhasil Diubah");
	printf("\nMasukkan No Peserta Pengganti %s: \n-> ", awal->peserta.id);
	scanf("%s", &awal->peserta.id); fflush(stdin);
	char id = upd;
	upd = awal->peserta.id;
	printf("\nNo Berhasil Diubah");
	printf("\nMasukkan Panjang Peserta Pengganti %d: \n-> ", awal->data.p);
	scanf("%d", &awal->data.p); fflush(stdin);
	int p = upd;
	upd = awal->data.p;
	printf("\nPanjang Berhasil Diubah");
	printf("\nMasukkan Lebar Peserta Pengganti %d: \n-> ", awal->data.l);
	scanf("%d", &awal->data.l); fflush(stdin);
	int l = upd;
	upd = awal->data.l;
	printf("\nLebar Berhasil Diubah");
	printf("\nMasukkan Tinggi Peserta Pengganti %d: \n-> ", awal->data.t);
	scanf("%d", &awal->data.t); fflush(stdin);
	int t = upd;
	upd = awal->data.t;
	printf("\nTinggi Berhasil Diubah\n");
  }
}

int delete_data(){
	char jawab='Y';
	struct peserta *del;
	char srch[30];
	if(awal==NULL){
		printf("Data belum di input. Input data peserta terlebih dahulu!");
		// return 0;
		do {
		system("cls");
		printf("\nKembali ke Menu Pilihan (Y/T)?: ");
		jawab=getche();
		menu();
	}
	while ((jawab)=='Y');
		}
	else{
		printf("Input nama peserta yang ingin dihapus : "); 
		scanf("%s", &srch);
		fflush(stdin);
		// gets(srch);
		if(strcmp(awal->peserta.nama,srch)==0){
			printf("DATA TELAH DIHAPUS");
			del= awal->right;
            free(awal);
            awal = del;
				do {
		// system("cls");
		printf("\nKembali ke Menu Pilihan (Y/T)?: ");
		menu();
		jawab=getche();
	}
	while ((jawab)=='Y');
        }
	}
}

void viewPeserta() {

	printf("----------------------------------------------------------\n");
	printf(" NO.\tNOMOR PESERTA\tNAMA PESERTA\tHASIL PERTANDINGAN\n");
	printf("----------------------------------------------------------\n");

	struct node *display;
	display = awal;
	int i=1;

	while(display !=NULL) {
		printf(" %d\t%s\t\t%s\t\t%.2f \n", i, display->peserta.id, display->peserta.nama, display->data.luas);
		display=display->right;
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
		next=head->right;

		for (j=1; j < k; j++) {
			if (current->data.luas < next->data.luas) {
				tempData=current->data;
				current->data=next->data;
				next->data=tempData;

				tempPeserta=current->peserta;
				current->peserta=next->peserta;
				next->peserta=tempPeserta;
			}

			current=current->right;
			next=next->right;
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