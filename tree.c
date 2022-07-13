#include <stdlib.h>
#include <stdio.h>
#define info(p) (p)->info
#define left(p) (p)->left
#define right(p) (p)->right
typedef struct treenode *data;
typedef struct treenode{
       int info;
       data right;
       data left;
 }node;
 data root;

void insert(data *tree, int elem){
        //Kamus
       data item;
        //Algoritma
        item = (data) malloc (sizeof(node));
        left (item) = right(item) = NULL;
        info (item) = elem;
        if(!(*tree)){
               *tree = item;
               return;
        }
        if(info(item) < info(*tree))
              insert(&left(*tree),elem);
        else if(info(item) > info(*tree))
              insert(&right(*tree), elem);
}

//Buat prosedur inorder, preorder, postorder, main program
void inorder(data *tree){
        if(*tree != NULL){
              inorder(&left(*tree));
              printf(" %d ", info(*tree));
              inorder(&right(*tree));
        }
}

void preorder(data *tree){
        if(*tree != NULL){
              printf(" %d ", info(*tree));
              preorder(&left(*tree));
              preorder(&right(*tree));
        }
}            

void postorder(data *tree){
        if(*tree != NULL){
              postorder(&left(*tree));
              postorder(&right(*tree));
              printf(" %d ", info(*tree));
        }
}

//Program Utama
int main(){
         insert (&root,2);
         insert (&root,3);
         insert (&root,1);
         insert (&root,4);
         printf("Inorder  : ");
         inorder(&root);
         printf("\n");
         printf("Preorder : ");
         preorder(&root);
         printf("\n");
         printf("Postorder: ");
         postorder(&root);
         printf("\n");
         getch();
         return 0;
}