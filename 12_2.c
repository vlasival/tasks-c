#include <stdio.h>
#include <stdlib.h>


typedef struct Node_s {
  int data, cnt;
  struct Node_s *left, *right;
} Node;

Node* addnode(Node *tree, int x) {
  if (tree == NULL) {
    tree = malloc(sizeof(Node));
    tree->data = x;
    tree->left = NULL;
    tree->right = NULL;
    tree->cnt = 1;
  }
  else{
    if (x < tree->data){
      tree->left = addnode(tree->left, x);
    }
    else if (x > tree->data){
      tree->right = addnode(tree->right, x);
    }
    else{
      tree->cnt += 1;
    }
  }
  return tree;
}

void printTree(Node *tree, FILE *output){
  if (tree != 0){
    printTree(tree->left, output);
    for (int i = 0; i < tree->cnt; i++){
      fwrite(&tree->data, sizeof(int), 1, output);
    }
    printTree(tree->right, output);
  }
}

void freeTree(Node *tree){
  if (tree != 0){
    freeTree(tree->left);
    freeTree(tree->right);
    free(tree);
  }
}

int myrand(int key){
  key *= 0xD9F3;
	key = key ^ (key >> 16);
	return key;
}

void shuffle(int *arr, int n){
  int pos, tmp;
  for (int i = 0; i < n; i++){
    pos = myrand(i + ((n - i / 2) * 17)) % n;
    tmp = arr[pos];
    arr[pos] = arr[i];
    arr[i] = tmp;
  }
}

int main(){
  FILE *input = fopen("input.bin", "rb");
  FILE *output = fopen("output.bin", "wb");
  int n, flag = 0;
  fread(&n, sizeof(int), 1, input);
  if (n > 0){
    int *arr = malloc(sizeof(int) * n);
    fread(arr, sizeof(int), n, input);
    shuffle(arr, n);
    Node *head = 0;
    head = addnode(head, arr[0]);
    for(int i = 1; i < n; i++){
      addnode(head, arr[i]);
    }
    printTree(head, output);
    freeTree(head);
    free(arr);
  }
  fclose(input);
  fclose(output);
  return 0;
}
