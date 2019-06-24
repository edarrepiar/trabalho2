#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    char data;
    struct node * right;
    struct node * left;

} node;

struct node *raiz; //Ponteiro da raiz
struct node *alocar; //Ponteiro para fazer alocação


char* ReadFile(char *filename)
{
   char *buffer = NULL;
   int string_size, read_size;
   FILE *handler = fopen(filename, "r");

   if (handler)
   {
       // Seek the last byte of the file
       fseek(handler, 0, SEEK_END);
       // Offset from the first to the last byte, or in other words, filesize
       string_size = ftell(handler);
       // go back to the start of the file
       rewind(handler);

       // Allocate a string that can hold it all
       buffer = (char*) malloc(sizeof(char) * (string_size + 1) );

       // Read it all in one operation
       read_size = fread(buffer, sizeof(char), string_size, handler);
        
       // fread doesn't set it so put a \0 in the last position
       // and buffer is now officially a string
       buffer[string_size] = '\0';

       if (string_size != read_size)
       {
           // Something went wrong, throw away the memory and set
           // the buffer to NULL
           free(buffer);
           buffer = NULL;
       }

       // Always remember to close the file.
       fclose(handler);
    }

    return buffer;
}

// void insert(node ** tree, char val[])
// {
    
//     int i = 0;
//     char * aux;

//     while(val[i] != '\0'){
        
//         if(val[i] == '\n'){    
//             // printf("%c \n", val[i+1]);
//             insertNode(tree, val[i+1]);
//         }
//                 i++;
//             }

// }

// void insertNode(node ** tree, char val[]){

//     node *temp = NULL;

//             if(!(*tree)){
//                 temp = (node *)malloc(sizeof(node));
//                 temp->left = temp->right = NULL;
//                 temp->data = val;
//                 *tree = temp;
//                 printf("%c\n\n", temp->data);
        
//             }
//             if(strcmp(val, (*tree)->data)<0)
//             {
//                 printf("entrou\n\n");
//                 insertNode(&(*tree)->left, val);
//             }
//             else if(strcmp(val, (*tree)->data) > 0)
//             {
//                 insertNode(&(*tree)->right, val);
//             }
// }


void insert(node **tree, char val[]){

    int i = 0;
    char * aux;

    while(val[i] != '\0'){
        
        if(val[i] == '\n'){    
            printf("%c \n", val[i+1]);
        }
                i++;
            }
}

void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(node * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
}

void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

node* search(node ** tree, char val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}

void print_preorder(node * tree)
{
    if (tree)
    {
        printf("%d\n",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

void print2DUtil(node *root, int space) 
{   
    int count=0;
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += count; 
  
    // Process right child first 
    print2DUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = count; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->data); 
  
    // Process left child 
    print2DUtil(root->left, space); 
}

int main()
{
    struct node *node = (struct node*)malloc(sizeof(node));

    char *string = ReadFile("morse.txt");
    insert(&node, string);

    // print2DUtil(node, 2);

    if (string)
    {
        // puts(string);
        free(string);
    }

    return 0;
}