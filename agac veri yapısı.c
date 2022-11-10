#include <stdio.h>
#include <stdlib.h>
struct tnode {
 int data;
 struct tnode *lchild, *rchild; 
 };
/* Dugum degeri verilen dugumun kok pointer degerini elde eden bir foksiyondur*/
struct tnode *getptr(struct tnode *p, int key, struct tnode **y){
	printf("kok pointer\n");//silme an.nda devreye giriyor
	struct tnode *temp;
 	if( p == NULL) 
		return(NULL);
	temp = p; *y = NULL;
 	while( temp != NULL) {
 		if(temp->data == key) 
			return(temp);
 		else {
 			*y = temp; /* bu pointer root (kok) olarak depolanir */
 			if(temp->data > key)
 				temp = temp->lchild;
 			else
 				temp = temp->rchild; 
 		} 
 	}
	return(NULL); 
}
 
 /* Veri degeri verilen dugumu silmek icin bir fonksiyon */
struct tnode *delete1(struct tnode *p,int val) {
 	struct tnode *x, *y, *temp;
 	x = getptr(p,val,&y);
 	if( x == NULL) {
		printf("Dugum mevcut degil\n");
		return(p);
	}
 	else{/* bu kod kok (root) dugumu silmek icindir*/
		if( x == p){
 			printf("kok dugum siliniyor\n");
			temp = x->lchild;
 			y = x->rchild;
 			p = temp;
 			while(temp->rchild != NULL)
				temp = temp->rchild;
 			temp->rchild=y;
 			free(x);
 			return(p);
 		}
 		
		/* bu kod dugumun sahip oldugu cocuklarý silmek icindir.*/
		if( x->lchild != NULL && x->rchild != NULL) {
			if(y->lchild == x) {
				temp = x->lchild;
				y->lchild = x->lchild;
				while(temp->rchild != NULL)
					temp = temp->rchild;
				temp->rchild=x->rchild;
				x->lchild=NULL;
				x->rchild=NULL;
 			}
 			else {
 				temp = x->rchild;
 				y->rchild = x->rchild;
 				while(temp->lchild != NULL)
 					temp = temp->lchild;
 				temp->lchild=x->lchild;
				x->lchild=NULL;
 				x->rchild=NULL;
 			}
			free(x);
 			return(p); 
		}
 
 
		/* bu kod cocuklarý ile birlikte bir dugum siliyor*/
		if(x->lchild == NULL && x->rchild !=NULL){
			if(y->lchild == x)
				y->lchild = x->rchild;
			else
				y->rchild = x->rchild;
			x->rchild=NULL;
			free(x);
 			return(p);
 		}
 		
 		
 		if( x->lchild != NULL && x->rchild == NULL){
 			if(y->lchild == x)
 				y->lchild = x->lchild ;
			else
 				y->rchild = x->lchild;
 			x->lchild = NULL;
 			free(x);
 			return(p);
 		}
 
 
 		/* bu kod cocuklarý olmadan bir dugumu siliyor*/
		if(x->lchild == NULL && x->rchild == NULL){
			if(y->lchild == x)
				y->lchild = NULL ;
 			else
 				y->rchild = NULL;
 			free(x);
 			return(p);
 		}
	}
}


/*inorder binary agacýný tekrarlamalý olarak yazdýran bir fonksiyon*/
void inorder1(struct tnode *p){
	struct tnode *stack[100]; //yigin
	int top;
	top = -1;
	if(p != NULL){
		top++;
		stack[top] = p;
		p = p->lchild;
		while(top >= 0){
			/* sol cocuk yigindan (stack dizisinden) cikariliyor*/
			while ( p!= NULL){
				top++;
				stack[top] =p;
				p = p->lchild; 
			}
			p = stack[top];
			top--;
			printf("%d\t",p->data);
			p = p->rchild;
			 /* sag cocuk cikariliyor*/
			if ( p != NULL){
				top++;
				stack[top] = p;
				p = p->lchild; 
			} 
		} 
	} 
}


/* Olusturulan agaca yeni bir dugum ilave etmek icin olusturulan bir fonksiyon*/
struct tnode *insert(struct tnode *p,int val) {
	printf("Agaca eklendi\n");
	struct tnode *temp1,*temp2;
	if(p == NULL){
		p = (struct tnode *) malloc(sizeof(struct tnode)); /* koke bir dugum ilave ediliyor*/
		if(p == NULL) {
			printf("Erisim izni yok\n");
			exit(0);
		}
		p->data = val;
		p->lchild=p->rchild=NULL; 
	}
	else{
		temp1 = p;
		/* child (cocuk) olacak dugumun pointer(gostergesini) almak icin agacta dolasma*/
		while(temp1 != NULL){
			temp2 = temp1;
			if( temp1 ->data > val)
				temp1 = temp1->lchild;
			else 
				temp1 = temp1->rchild;
		}
		if( temp2->data > val) {
			temp2->lchild = (struct tnode*)malloc(sizeof(struct tnode));/*Sol cocuk (left child) olarak yeni olusturulan dugumu ekler*/
			temp2 = temp2->lchild;
			if(temp2 == NULL) {
				printf("Erisim izni yok\n");
				exit(0);
			}
			temp2->data = val;
			temp2->lchild=temp2->rchild = NULL; 
		}
		else {
			temp2->rchild = (struct tnode*)malloc(sizeof(struct tnode));/*Sag cocuk (right child) olarak yeni olusturulan dugumu ekler*/
			temp2 = temp2->rchild;
			if(temp2 == NULL) {
				printf("Erisim izni yok\n");
				exit(0);
			}
			temp2->data = val;
			temp2->lchild=temp2->rchild = NULL; 
		} 
	}
	return(p);
}


int main(){
	struct tnode *root = NULL;
	int n,x;
	printf("Agactaki dugumlerin sayisini giriniz\n");
	scanf("%d",&n);
	while( n-->0){
		printf("Degerleri giriniz\n");
		scanf("%d",&x);
		root = insert(root,x);
	}
	printf("Olusturulan agac :\n");
	inorder1(root);
	printf("\n Silinencek dugumun degeri giriniz\n");
	scanf("%d",&n);
	root=delete1(root,n);
	printf("Dugum agactan silindikten sonra \n");
	inorder1(root);
}
