#include <stdio.h>
#include <stdlib.h>

//inisialisasi struct
struct data{
	int number;
	//pointer untuk menampung percabangan kiri dan kanan
	struct data *left, *right;
};

//fungsi push untuk menambah data
void push(data **current, int number){
	//jika pointer current kosong maka akan membuat blok data baru
	if((*current)==NULL){
		(*current) = (struct data *)malloc(sizeof data);
		//mengisi data
		(*current)->number=number;
		(*current)->left = (*current)->right = NULL;
	//jika tidak kosong, maka akan dibandingkan apakah angka yang 
	//ingin dimasukkan lebih kecil dari pada root
	//kalau iya, maka belok ke kiri dan lakukan rekursif 
	//terus menerus hingga kosong
	}else if(number < (*current)->number){
		push(&(*current)->left, number);
	//jika lebih besar, belok ke kanan
	}else if(number >= (*current)->number){
		push(&(*current)->right, number);
	}
}

//preOrder : cetak, kiri, kanan
void preOrder(data **current){
	if((*current)!=NULL){
		printf("%d -> ", (*current)->number);
		preOrder(&(*current)->left);
		preOrder(&(*current)->right);
	}
}

//inOrder : kiri, cetak, kanan
void inOrder(data **current){
	if((*current)!=NULL){
		inOrder(&(*current)->left);
		printf("%d -> ", (*current)->number);
		inOrder(&(*current)->right);
	}
}

//postOrder : kiri, kanan, cetak
void postOrder(data **current){
	if((*current)!=NULL){
		postOrder(&(*current)->left);
		postOrder(&(*current)->right);
		printf("%d -> ", (*current)->number);
	}
}

//searching data
void search(data **current, int number){
	//jika pointer current memiliki data
	if((*current)!=NULL){
		//cek, apakah datanya lebih kecil. Jika iya, belok ke kiri
		if(number<(*current)->number){
			search(&(*current)->left,number);
		//jika lebih besar, maka belok ke kanan
		}else if(number>(*current)->number){
			search(&(*current)->right,number);
		//jika sama dengan, maka angka ketemu
		}else{
			printf("Found : %d", (*current)->number);
		}
	//jika tidak ada data lagi (not found)
	}else{
		printf("Not Found.");
	}
}

void main(){
	push(&root, 11);
	push(&root, 22);
	push(&root, 13);
	push(&root, 15);
	push(&root, 9);
	inOrder(&root);
	printf("\n");
	preOrder(&root);
	printf("\n");
	postOrder(&root);
	printf("\n");
	search(&root,91);
	getchar();
}