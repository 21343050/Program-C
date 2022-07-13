#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

int input_data();
int input_nilai();
int score();
int display();
int delete_data();

struct peserta
{
	char nama[50], asal[50], usia[20], burung[20];
	int no, nilai;
	struct peserta *next, *prev;	
}*beg, *last;

void menu() {
	system("cls");
	int noMenu;

	printf("\n----------------------------------------------------------\n");
	printf("\n|MENU--> Perlombaan Benteng Pertahanan| Pilih (1 - 4)\n");
	printf("   1. Entri Identitas Peserta\n");
	printf("   2. Daftar Peserta Beserta Hasil Pertandingan\n");
	printf("   3. Daftar Juara Lomba\n");
	printf("   4. Keluar\n\n");
	printf("   5. Delete\n\n");
	printf("----------------------------------------------------------\n");
	printf(" Masukkan Nomor Pilihan\t\t: ");
	scanf("%i", &noMenu);
	printf("----------------------------------------------------------\n\n");

	switch (noMenu) {
		case 1:
			system("cls");
			printf("----------------------------------------------------------\n");
		// entryPeserta();
		input_data();
		// input_nilai();
		printf(" Tekan enter untuk kembali ke Manu Pilihan...\n");
		getch();
		menu();
		break;
		case 2:
			system("cls");
			printf("----------------------------------------------------------\n");
			printf("\t2. Daftar Peserta Beserta Hasil Pertandingan\n\n");
		score();
		printf(" Tekan enter untuk kembali ke Manu Pilihan...\n");
		getch();
		menu();
		break;
		case 3:
			system("cls");
			printf("----------------------------------------------------------\n");
			printf("\t3. Daftar Juara Dari Pertandingan\n\n");
		display();
		// viewPeserta();
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
		case 5:
			system("cls");
			delete_data();
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

int input_data()
{
	struct peserta *save, *first;
	int i=0;
	char pilih[2];
	while(1){
		system("cls");
		first=(struct peserta*)malloc(sizeof(struct peserta));
		fflush(stdin);
		printf("        UJIAN AKHIR SEMESTER  \n");
		printf("NAMA\t\t : ADENG PRATAMA \n");
		printf("NIM\t\t : 20343001\n");
		printf("PROGRAM STUDI\t : INFORMATIKA \n");
		printf("MATA KULIAH\t : ALGORITMA DAN STRUKTUR DATA \n");
		printf("DOSEN PENGAMPU\t : Drs. Denny Kurniadi, M.Kom\n");
		printf("============================================================\n");
		printf("		KONTES LOMBA LAYANGAN   	   \n");
		printf("============================================================\n");
		printf("Nama Peserta : ");
		gets(first->nama);
		fflush(stdin);
		
		printf("No Peserta : ");
		scanf("%d", &first->no);
		fflush(stdin);
		
		printf("Asal Daerah : "); 
		gets(first->asal);
		
		printf("Usia Peserta : "); 
		gets(first->usia);
		
		if(i==0)
		{
			first->next=NULL;
			first->prev=NULL;
			beg=first;
			save=beg;
			last=first;
		}
		else
		{
			save->next=first;
			first->next=NULL;
			first->prev=save;
			last=first;
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
	}
}



int delete_data(){
	char jawab='Y';
	struct peserta *del;
	char srch[30];
	if(beg==NULL){
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
		if(strcmp(beg->nama,srch)==0){
			printf("DATA TELAH DIHAPUS");
			del= beg->next;
            free(beg);
            beg = del;
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


int display(){
	system("cls");
	struct peserta *display;
	display=beg;
	printf("------------------------------------");
	printf("* DATA PESERTA KONTES LOMBA LAYANGAN *");
	printf("------------------------------------");
	while(display!=NULL){
		printf("\nNama : %s|\t|", display->nama);
		printf("No Peserta : %d|\t|", display->no);
		printf("Asal Daerah : %s|\t|", display->asal);
		printf("Usia : %s|\t|", display->usia);
		display=display->next;
	}
	return 0;
}

int score(){
	system("cls");
	struct peserta *score;
	score=beg;
	printf("------------------------------------");
	printf("* DATA PESERTA KONTES LOMBA LAYANGAN *");
	printf("------------------------------------");
	while(score!=NULL){
		printf("\nNama : %s|\t|", score->nama);
		printf("No Peserta : %d|\t|", score->no);
		printf("Asal Daerah : %s|\t|", score->asal);
		printf("Usia : |%s|\t|", score->usia);
		printf("|%d\t|\n", score->nilai);
		
		score=score->next;
	}
	return 0;
}

struct psrt {
    int no;
    char nama[10]; 
    int slr;
    int ed;
    int td;
    int jumlah;
};



int input_nilai()
{
    int a,b,c,d,i;
    char nama[50];
    printf("Input Jumlah Peserta Lomba : ");
    scanf("%d",&b);
    struct psrt pes[b], swap;
    for (i=0; i<b;i++) {
        printf("No Peserta : ");
        scanf("%d",&pes[i].no);
        fflush(stdin);
        printf("Nama Peserta : ");
        gets(nama);
        fflush(stdin);
        printf("Nilai Secara Keseluruhan : ");
        scanf("%d",&pes[i].slr);
        printf("Nilai Keindahan Layangan : ");
        scanf("%d",&pes[i].td);
        printf("--------------------------------------------------\n");
        
        pes[i].jumlah = (pes[i].slr*100)+(pes[i].ed*100)+(pes[i].td);
    };
    
	
    for(d=0; d<b-1; d++) {
        for(c=0; c<b-1; c++) {
            if(pes[c].jumlah < pes[c+1].jumlah) { 
                swap = pes[c];      
                pes[c] = pes[c+1];  
                pes[c+1] = swap;  
            }
        }
    }
}


	int main() {
	system("cls");
	char jawab='Y';
	// judul();
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