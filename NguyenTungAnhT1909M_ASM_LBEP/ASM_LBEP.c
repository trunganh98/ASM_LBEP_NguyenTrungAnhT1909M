#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
 
typedef struct Sach{
    char masach[6];
    char name[100];
}sach_t;
 
struct ListSach;
typedef struct ListSach node;
 
struct ListSach{
    sach_t s;
    node *next;
};
 
typedef struct ListSach *root;
 
 
void init(root *A){
    *A=NULL;
}
 
bool isNull(root A){
    return A==NULL;
}
int length(root A){
    if(A==NULL) return 0;
    int len=0;
    while(A!=NULL) {
        len++;
        A=A->next;
    }
    return len;
}
 
node *createNode()
{
    node *s = (node*) malloc(sizeof(node));
    printf("\n\nNhap ten sach: ");
    fflush(stdin); gets((*s).s.name);
    printf("Nhap ma sach: ");
    gets((*s).s.masach);
     
    s->next=NULL;
    return s;
}
void Insert_last(root *A, node *P){
    if(*A==NULL){
         *A=P;
         return;
    }
         
    node *B=*A;
     
    while(B->next!=NULL){
        B=B->next;
    }
    B->next=P;
}
 
void Insert_first (root *A, node *P)  {
      if(*A==NULL){
         *A=P;
         return;
    }
    P->next = *A; 
    *A = P;
}
void input(root *A)
{                    
    printf("Nhap so luong sach: ");
    int n; scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        node *b = createNode();
        Insert_first(A, b);
    }
}
void deletePhantuthuK(root *A){
    int n=length(*A)+1;
    printf("Nhap vi tri k can xoa phan tu: ");
    int k; scanf("%d", &k);
    if(k==0 || k>n){
        printf(" =>Vi tri xoa khong hop le");
        return;
    }
    if(k==1) *A=(*A)->next;
    else{
        int vt=2;
        node *B= *A;
        while(vt<k){
            B=B->next;
            vt++;
        }
        B->next = B->next->next;
    }
}
void output(root A){
    while(A!=NULL) 
    {
        printf("\n%s   %s  ", A->s.name, A->s.masach);
        A = A->next;
    }
}
 
 
int main()
{
    root A;
    init(&A);
    input(&A);
    printf("\n\n---------------Menu---------------\n");
    output(A);
    node * b;
     
    while(true){
        int chon;
        printf("\n\n\n\n--------CHON---------\n1.Nhap lai list\n2.Kiem tra xem list rong\n3.Do dai list\n4.Chen vao dau list\n5.Chen vao cuoi list\n6.Xoa phan tu\n");
        scanf("%d", &chon);
        switch(chon){
            case 1:
                init(&A);
                input(&A);
                output(A);
                break;
            case 2:
                if(isNull(A)) printf("List rong");
                    else printf("List khong rong");
                break;
            case 3:
                printf("Do dai list: %d", length(A));
                break;
            case 4:
                b = createNode();
                Insert_first(&A, b);
                output(A);
                break;
            case 5:
                b = createNode();
                Insert_last(&A, b);
                output(A);
                break;
            case 6:
                deletePhantuthuK(&A);
                output(A);
                break;
        }
    }
}
