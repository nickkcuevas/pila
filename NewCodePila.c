#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char **ap;
    int size;
    int top;
}carta;

int IPila(carta *aps,int tam);
int isFull(carta aps);
int isEmpty(carta aps);
int PushCart(carta *aps,char *item);
int PopCart(carta *aps,int *fok);
void ImprimirAll(carta *A, carta *B, carta *C, int *fok);

int main(){
    carta A,B,C;
    carta A1,B1,C1;
    int sizeA,sizeB,sizeC,fok,end=0,i;
    char table,cart,ISBN[10];
    char *item;
    scanf("%d %d %d",&sizeA,&sizeB,&sizeC);
    IPila(&A,sizeA);
    IPila(&B,sizeB);
    IPila(&C,sizeC);
    IPila(&A1,sizeA);
    IPila(&B1,sizeB);
    IPila(&C1,sizeC);
    while(end!=1){
        scanf(" %c %c",&table,&cart);
            if(table=='A'){
                if(cart=='N'){
                    scanf("%s",&ISBN);
                    PushCart(&A,ISBN);
                }
                if(cart=='R'){
                    PopCart(&A,&fok);
                }
            }    
            if(table=='B'){
                if(cart=='N'){
                    scanf("%s",&ISBN);
                    PushCart(&B,ISBN);
                }
                if(cart=='R'){
                    PopCart(&B,&fok);
                }
            }    
            if(table=='C'){
                if(cart=='N'){
                    scanf("%s",&ISBN);
                    PushCart(&C,ISBN);
                }
                if(cart=='R'){
                    PopCart(&C,&fok);
                }    
            }
            if(table=='*'){
                for(i=-1;i<=A.top;i++){
                    item=PopCart(&A,&fok);
                    PushCart(&A1,item);
                }
                for(i=-1;i<=B.top;i++){
                    item=PopCart(&B,&fok);
                    PushCart(&B1,item);
                }
                for(i=-1;i<=C.top;i++){
                    item=PopCart(&C,&fok);
                    PushCart(&C1,item);
                }
                ImprimirAll(&A1,&B1,&C1,&fok);
                end=1;
            }
    }
    return 0;
}

int IPila(carta *aps,int tam){
    int i;
    aps->top=-1;
    aps->size=tam;
    if((aps->ap=malloc(sizeof(char*)*tam))==0){
        return 0;
    }
    for(i=0;i<tam;i++){
    aps->ap[i]=malloc(sizeof(char)*10);
    }
    return 1;
}

int PushCart(carta *aps,char *item){
    if(isFull(*(aps))){
        return 0;
    }
    strcpy(aps->ap[++aps->top],item);
    return 1;
}

int PopCart(carta *aps,int *fok){
    if(isEmpty(*(aps))){
        *(fok)=0;
        return 0;
    }
    *(fok)=1;
    return aps->ap[aps->top--];
}

void ImprimirAll(carta *A, carta *B, carta *C, int *fok){
    int i;
    printf("MESA A: ");
    for(i=-1;i<=A->top;i++){
        printf("%s\t",PopCart(A,&fok));
    }
    printf("\nMESA B: ");
    for(i=-1;i<=B->top;i++){
        printf("%s\t",PopCart(B,&fok));
    }
    printf("\nMESA C: ");
    for(i=-1;i<=C->top;i++){
        printf("%s\t",PopCart(C,&fok));
    }
    return;
}

int isFull(carta aps){
    if(aps.top>=aps.size-1){
        return 1;
    }
    return 0;
}

int isEmpty(carta aps){
    if(aps.top<=-1){
        return 1;
    }
    return 0;
}

/* PRUEBA PARA VERIFICAR EJEMPLO
3 	3 	2
A 	N 	U-607
A 	N 	R-313
B 	N 	D-568
C 	N 	E-916
C 	N 	A-111
B 	N 	D-099
B 	R
A 	N 	Y-173
A 	N 	Y-801
A 	R
C 	R
*
SALIDA
MESA A: U-607   R-313	
MESA B: D-568
MESA C: E-916
*/
