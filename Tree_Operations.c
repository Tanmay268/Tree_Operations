/*
Implement a program for Binary Search Tree operations using integer elements. Tree
operations are (i) insertion (ii) deletion (iii) search.
*/
#include<stdio.h>
#include<stdlib.h>
struct Tree{
    int data;
    struct Tree *left;
    struct Tree *right;
}*root = NULL;

struct Tree *Create_node(int val){
    struct Tree *newNode = (struct Tree*)malloc(sizeof(struct Tree));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Tree *insert(struct Tree *root, int val){
    if(root==NULL){
        return Create_node(val);
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else if(val > root->data){
        root->right = insert(root->right, val);
    }
    return root;
}

struct Tree *getSuccessor(struct Tree *curr){
    curr = curr->right;
    while(curr != NULL && curr->left!=NULL){
        curr = curr->left;
    }
    return curr;
}
struct Tree *delete(struct Tree *root, int del){
    if(root==NULL){
        return root;
    }
    if(del < root->data){
        root->left = delete(root->left, del);
    }
    else if(del > root->data){
        root->right = delete(root->right, del);
    }
    else{  // when del == root->node
        if(root->left==NULL){
            struct Tree *temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right==NULL){
            struct Tree *temp = root->left;
            free(root);
            return temp;
        }
        struct Tree *temp = getSuccessor(root);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;

}

void search(struct Tree *root, int val){   
    while(root!=NULL){
        if(val < root->data){
            root = root->left;
        }
        else if(val > root->data){
            root = root->right;
        }
        else{
            printf("Found!\n");
            return;
        }
    }
    printf("Not Found!\n");
}

void inOrder(struct Tree *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d\t", root->data);
        inOrder(root->right);
    }
}

int main(){
    printf("Enter Root Node data: ");
    int x;
    scanf("%d",&x);
    root = insert(root, x);
    printf("Enter choice of your operation:\n1 to Insert\n2 to delete\n3 to search\n4 to display\n5 to Exit\n");
    int val;
    while(1>0){
        printf("\nChoice: ");
        scanf("%d", &x);
        switch(x){
            case 1:  //Inserting an Element
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                printf("INSERTED SUCCESSFULLY!\n");
                break;
            case 2:  //Deleting an Element
                printf("\nEnter value of Node to be Deleted: ");
                scanf("%d", &val);
                root = delete(root, val);
                printf("NODE DELETED!\n");
                break;

            case 3:  //Searching an Element
                printf("\nEnter Element You want to check: ");
                scanf("%d", &val);
                search(root, val);
                break;

            case 4:  //Printing InOrder Traversal
                printf("\nInOrder Traversal of BST: ");
                inOrder(root);
                break;

            case 5:  //Exiting
                printf("\nExiting...");
                return 0;
            default:
                printf("Invalid Choice! Try Again..\n");
                break;
        }
    }
}


