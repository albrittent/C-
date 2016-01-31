#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char key;
	struct node *left;
	struct node *right;
} Node;

struct node * fabNode(char c){
	Node *n = malloc(sizeof(Node));
	n->left = NULL;
	n->right = NULL;
	n->key = c;
	return n;
}

void addNode(Node *root, char *encoding){
    char *value = encoding++;
	while(*encoding){
		if(*encoding =='0'){
			if(root->left==NULL){
				root->left = fabNode('\0');
			}
			root=root->left;
		}
		else if(*encoding == '1'){
			if(root->right==NULL){
				root->right = fabNode('\0');
			}
			root=root->right;
		}	
        encoding++;
	}
	root->key = *value;
}

void searchTree(Node *root, char *encoding){
	Node *current = root;
	while(*encoding){
		if(*encoding == '0'){
			current = current->left;
		}
		else{
			current = current->right;
		}
		if(current->key != '\0'){
			printf("%c",current->key);
			current = root;
		}
		encoding++;
	}
    printf("\n");
}	

int main()
{
	int N;
	scanf("%d\n",&N);
	Node root = {.left = NULL, .right = NULL, .key = '\0'};
	for(int i=0; i<N; i++){
        char string[100];
        gets(string);
        addNode(&root,string);
    }
    char message[100000];
    gets(message);
    searchTree(&root,message);
	return 0;
}
