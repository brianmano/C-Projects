#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct node{
    char *name;
    char *tea;
    struct node * left;
    struct node * right;
} Node;

int depth(Node *root);
int dfs(Node *root, char *name);

/******************The binary tree***********************
 * The following is an illustration of the binary tree
 ********************************************************
 *                        Nicholas
 *                        /      \
 *                     Mark      Parker
 *                    /          /     \
 *                Swaleh     Soroush   Other Mark
 *                                 \
 *                                 Ana
 *                                 /
 *                             Bassel
 *
 *
 * (where "/" indicates a left branch, 
 *    and "\" indicates a right branch)
 *
 */ 

int main() {

    Node *root = malloc(sizeof(Node));
    root->name = "Nicholas";
    root->tea = "Orange Pekoe with Lemon";
    root->left = malloc(sizeof(Node));
    root->left->left = malloc(sizeof(Node));
    root->left->right = NULL;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->right = malloc(sizeof(Node));
    root->right->left = malloc(sizeof(Node));
    root->right->right = malloc(sizeof(Node));
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    root->right->left->left = NULL;
    root->right->left->right = malloc(sizeof(Node));
    root->right->left->right->left = malloc(sizeof(Node));
    root->right->left->right->right = NULL;
    root->right->left->right->left->left = NULL;
    root->right->left->right->left->right = NULL;
    
    root->left->name = "Mark";
    root->left->tea = "Green";
    
    root->right->left->name = "Soroush";
    root->right->left->tea = "Oolong";
    
    root->right->name = "Parker";
    root->right->tea = "Rooibos";
    
    root->right->right->name = "Other Mark";
    root->right->right->tea = "Sencha";
    
    root->left->left->name = "Swaleh";
    root->left->left->tea = "White";
    
    root->right->left->right->name = "Ana";
    root->right->left->right->tea = "Hibiscus";
    
    root->right->left->right->left->name = "Bassel";
    root->right->left->right->left->tea = "Matcha";
    
    printf("The depth of the tree is: %d\n", depth(root));
    // expected result is 5.
    
    printf("Depth First Search for : Nicholas\n");
    printf("result: %d\n", dfs(root, "Nicholas"));
    // expected result is 1
    
    printf("Depth First Search for : Other Mark\n");
    printf("result: %d\n", dfs(root, "Other Mark"));
    // expected result is 8
    
    printf("Depth First Search for : Parker\n");
    printf("result: %d\n", dfs(root, "Parker"));
    // expected result is 4
    
    printf("Depth First Search for : Julius Ceasar\n");
    printf("result: %d\n", dfs(root, "Julius Ceasar"));
    // expected result is -1
    
    free(root->right->left->right->left);
    free(root->right->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root->left->left);
    free(root->left);
    free(root);
} 

int depth(Node *root){
    if (root == NULL){
        return 0;
    }
    else {
        int leftdepth = depth(root->left);
        int rightdepth = depth(root->right);

        if (leftdepth > rightdepth){
            return (leftdepth+1);
        }
        else{
            return (rightdepth+1);
        }
    }
}

void recursive (Node *root, char *name, int *stat, int *counter){

    if (root == NULL){
        return;
    }
    *counter+=1;
    if (strcmp(name, root->name)==0){
        *stat = 1; 
        return;
    }
    
    recursive(root->left, name, stat, counter);
    recursive(root->right, name, stat, counter);

    if (*stat == 1){
        return;
    }
} 

int dfs(Node *node, char *name){
    int final = 0; int count = 0;

    recursive(node, name, &final, &count); 
    
    if (final == 1){
        return count; 
    }
    return -1; 
} 
