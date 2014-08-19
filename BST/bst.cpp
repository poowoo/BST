#include<stdlib.h>
#include<stdio.h>
#include<string.h>


typedef struct _tree{
	_tree* leftnode;
	_tree* rightnode;
	_tree* fathernode;
	int num;
	int level;
}tree;
void usage(void){
	printf("input a num  = add number\n");
	printf("input d num  = delete number\n");
	printf("input s num  = show number's information\n");
}
void add(int insert,tree *root){
	tree *newnode = (tree *)malloc(sizeof(tree)*1);
	tree *tmp = (tree *)malloc(sizeof(tree)*1);
	int level = root->level;
	newnode->num = insert;
	/*if(root){
		if(root->rightnode){
			if(newnode->num > root->rightnode->num){
				tmp = root;
				while(tmp->num){
					if(tmp->num > newnode->num){
						if(tmp->leftnode && tmp->rightnode){

						}else if(tmp->rightnode){
							tmp->leftnode = newnode;
							newnode->fathernode = tmp;
							newnode->level = tmp->fathernode->level++;
							break;
						}else if(tmp->leftnode){
							newnode->fathernode = tmp->fathernode;
							newnode->leftnode = tmp->leftnode;
							tmp->leftnode->fathernode = newnode;
							newnode->rightnode = tmp;
						}else{
							tmp->leftnode = newnode;
							newnode->fathernode = tmp;
							newnode->level = tmp->fathernode->level++;
							break;
						}
					}else{
						tmp = tmp->rightnode;
					}
				}
			}else{
			
			}
		}else if(newnode->num > root->num){
			root->rightnode = newnode;
			newnode->fathernode = root;
		}
		if(root->leftnode){
			if(newnode->num < root->leftnode->num){
			}
		}else if(newnode->num < root->leftnode->num){
			root->leftnode = newnode;
			newnode->fathernode = root;
		}
	}else{
		root = newnode;
	}*/
	tmp = root;
	while(1){
		if(tmp->num){
			level++;
			if(tmp->num == insert){
				printf("already have num in tree\n");
			}else if(tmp->num < insert && !tmp->rightnode){
				tmp->rightnode = newnode;
				newnode->fathernode = tmp;
				newnode->level = level;
				break;
			}else if(tmp->num <insert && tmp->rightnode){
				tmp = tmp->rightnode;
			}else if(tmp->num > insert && !tmp->leftnode){
				tmp->leftnode = newnode;
				newnode->fathernode = tmp;
				newnode->level = level;
				break;
			}else if(tmp->num > insert && tmp->leftnode){
				tmp = tmp->leftnode;
			}
			
		}else{
			tmp->num = insert;
			break;
		}
	}
}
void search(int search,tree *root){
	tree * tmp = (tree *)malloc(sizeof(tree));
	tmp = root;
	while(1){
		if(root->num){
			if(tmp->num == search){
				printf("find \n");
				printf("num  : %d\n",tmp->num);
				printf("level : %d\n",tmp->level);
				break;
			}else if(tmp->num > search && tmp->leftnode){
				tmp = tmp->leftnode;
			}else if(tmp->num > search && !tmp->leftnode){
				printf("%d is not in tree");
				break;
			}else if(tmp->num < search && tmp->rightnode){
				tmp = tmp->rightnode;
			}else if(tmp->num < search && !tmp->rightnode){
				printf("%d is not in tree");
				break;
			}
		}else{
			printf("no num in tree");
		}
	}
}
int main(void){

	tree *rootnode = (tree *)malloc(sizeof(tree));
	rootnode->leftnode = NULL;
	rootnode->rightnode = NULL;
	rootnode->level = 0;
	rootnode->num = 0;
	char state_c[1] = "";
	int state = 0;
	int num = 0;
	while(1){
		scanf("%s",state_c);
		scanf("%d",&num);
		while(1){
			if( state_c[0] == 'a'){
				state = 2;
				break;
			}else if(state_c[0] == 'd'){
				state = 3;
				break;
			}else if(state_c[0] == 's'){
				state = 4;
				break;
			}else{
				state = 0;
				break;
			}
		}
		switch(state){
			case 2 :
				add(num,rootnode);
			   break;
			case 4 :
				search(num,rootnode);
				break;
		}
	}
	return 0;
}