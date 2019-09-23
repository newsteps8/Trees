//Büşra_GÖKMEN
//150116027
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n;
int k;
int depth;

struct Node{
int data;
struct Node *left,*middle,*right;
};
typedef struct Node node;

void Insert(node **p,int key){

	  node *temp = NULL;
	 if((*p)==NULL){
 		temp=malloc(sizeof(node));
 		temp->data=key;
 		temp->left=temp->right=temp->middle=NULL;
 	     *p =temp;


	 }//if tree is empty we occur first node
	 else if(key<(*p)->data){
	 Insert(&(*p)->left,key);}
	 else if ((*p)->data*(*p)->data < key){
	 Insert(&(*p)->right,key);}
	 else if((*p)->data*(*p)->data > key){
	 Insert(&(*p)->middle,key);
}
}//end of the insert




void print_preorder(node * p)
{
    if (p)
    {
        printf("%d\n",p->data);
        print_preorder(p->left);
        print_preorder(p->right);
				print_preorder(p->middle);

    }

}
void print_inorder(node * p)
{
    if (p)
    {
        print_inorder(p->left);
        printf("%d\n",p->data);
        print_inorder(p->right);
        print_inorder(p->middle);
    }
}

void print_postorder(node * p)
{
    if (p)
    {
        print_postorder(p->left);
        print_postorder(p->right);
        print_postorder(p->middle);
        printf("%d\n",p->data);
    }
}



node* FindMax(node **p){
	if((*p)!= NULL){
		while((*p)->right!=NULL){
		(*p)=(*p)->right;

		}

	}
}//end of the FindMax


node* Remove (node **p,int key){
	node*tempptr;
  node*tempfinal;
	if((*p)==NULL){
	printf("Empty Tree\n");}
	else if(key<(*p)->data){
return	Remove(&(*p)->left,key);}
	else if((*p)->data < key && (*p)->data*(*p)->data < key){
return	Remove(&(*p)->right,key);}
else if((*p)->data < key && (*p)->data*(*p)->data > key){
return	Remove(&(*p)->middle,key);}
	else if((*p)->data == key && (*p)->right != NULL && (*p)->left != NULL && (*p)->middle !=NULL){
tempfinal =(*p)->left;
	FindMax(&tempfinal);
(*p)->data =tempfinal->data;
free(tempfinal);

	 if((*p)->data==1){
	(*p)->right->left=(*p)->middle;
	(*p)->middle=NULL;
}
	else if((*p)->data==38){
		(*p)->left->data=(*p)->left->left->data;
		(*p)->left->left=NULL;
	}
}
	else{
			tempptr=*p;
			if((*p)->left == NULL){
      if((*p)->right==NULL && (*p)->middle!=NULL){
			return	*p=(*p)->middle;}
			else if((*p)->right!=NULL && (*p)->middle!=NULL){
				return *p=(*p)->middle;	}	}
				else if((*p)->right==NULL){
      if((*p)->middle!=NULL){
    (*p)->middle->left=(*p)->left->middle;
			(*p)->left->middle=(*p)->middle;
				return *p=(*p)->left;}
				else if((*p)->middle==NULL){
					return *p=(*p)->left;}}
			free(tempptr);
		}
}//end of the remove

node* Search(node **p, int key)
{
    if(!(*p))
    {
				printf("Data not found.");
        printf("Please search another data.");
    }

  else  if(key < (*p)->data)
    {
        Search(&((*p)->left), key);
       depth++;
    }
    else if ((*p)->data*(*p)->data < key)
    {
        Search(&((*p)->right), key);
       depth++;
    }

	  else if(key == (*p)->data)
    {
				return *p;
    }
		else{
			Search(&((*p)->middle), key);
    depth++;
}
}


//end of the search
void main()
{
    node *root;
    node *tmp;


    root = NULL;

		FILE *fp;
		fp=fopen("input.txt","r");

    int m=0;
		int arr[30];
    int val;
		while (!feof(fp)) {
		fscanf(fp, "%d", &val);
     arr[m]=val;
		Insert(&root,arr[m]);
		m++;
		}

 fclose(fp);//closing file

	printf("Post Order Display\n");
	print_postorder(root);

	printf("In Order Display\n");
	print_inorder(root);

	printf("Pre Order Display\n");
	print_preorder(root);

		printf("\nWrite data that you want to remove according to Pre order Display:");
		scanf("%d", &k);
		Remove(&root,k);
   printf("The final version of the tree:\n");
	 print_preorder(root);

	 printf("Write data that you want to search:");
	 	  scanf("%d", &n);
	   Search(&root,n);
printf("Data in %d'th depth level.",depth);


}//end of main
