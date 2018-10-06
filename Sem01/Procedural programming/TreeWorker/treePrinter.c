#include "treePrinter.h"
#include <malloc.h>
#include <stdio.h>
#include <mem.h>
#include <ctype.h>


char *DIRECTIONS[] = {
        "parent",
        "left",
        "right"
};

Node *createNode(Node *parent, int element) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;
    node->is_root = 0;
    node->element = element;
    return node;
}
void moveFromCurrentNode(char *direction) {
    int i=0;
    for (i = 0; i < strlen(direction); ++i) {
        tolower(direction[i]);
    }
    if ( !strcmp(direction, DIRECTIONS[0]) && CURRENT_NODE->parent)
        CURRENT_NODE = CURRENT_NODE->parent;
    else if( !strcmp(direction, DIRECTIONS[1]) && CURRENT_NODE->left)
        CURRENT_NODE = CURRENT_NODE->left;
    else if( !strcmp(direction, DIRECTIONS[2]) && CURRENT_NODE->right)
        CURRENT_NODE = CURRENT_NODE->right;
    else printf("[Error]:Bad direction!\n");
}
void deleteTreeFromNode(Node *root) {
    if(root == NULL || root->is_root){
        return;
    }
    deleteTreeFromNode(root->left);
    root->parent->left = NULL;

    deleteTreeFromNode(root->right);
    root->parent->right = NULL;

    free(root);

}
void addNode (char *direction, int element){
    Node *node = createNode(CURRENT_NODE, element);
    if(!strcmp(direction, DIRECTIONS[1])){
        CURRENT_NODE->left = node;
    } else if(!strcmp(direction, DIRECTIONS[2])){
        CURRENT_NODE->right = node;
    } else {
        free(node->parent);
        free(node);
        printf("[Error]: Node cant be added!\n");
        return;
    }
    CURRENT_NODE = node;
}

int getLeavesCount(){
    LEAVES = 0;
    countOfLeaves(ROOT_NODE);
    return LEAVES;

}
 void countOfLeaves(Node *root){
    if(root == NULL){
        LEAVES++;
        return;
    }
    countOfLeaves(root->left);
    countOfLeaves(root->right);

}

int getNodesCount(){
    NODES = 0;
    countOfNodes(ROOT_NODE);
    return NODES;
}
void countOfNodes(Node *root){
    if(root == NULL){
        return;
    }
    NODES++;
    countOfNodes(root->left);
    countOfNodes(root->right);
}

int getAllNodesCount(){
    return getLeavesCount() + getNodesCount();
}


void saveTreeInFile(Node *tree){
    if((freopen("Tree.txt", "w", stdout)) == NULL)
        return;

    print_ascii_tree(tree);

    freopen("CON", "w", stdout);
}
void loadTreeFromFile(){
    //todo
}


/*printer */
int lprofile[MAX_HEIGHT];
int rprofile[MAX_HEIGHT];
int gap = 3;
int print_next;

int MIN (int X, int Y) {
    return ((X) < (Y)) ? (X) : (Y);
}
int MAX (int X, int Y) {
    return ((X) > (Y)) ? (X) : (Y);
}

asciinode *build_ascii_tree_recursive(Node * t) {
    asciinode * node;

    if (t == NULL) return NULL;

    node = (asciinode *) malloc(sizeof(asciinode));
    node->left = build_ascii_tree_recursive(t->left);
    node->right = build_ascii_tree_recursive(t->right);

    if (node->left != NULL) {
        node->left->parent_dir = -1;
    }

    if (node->right != NULL) {
        node->right->parent_dir = 1;
    }

    sprintf(node->label, "%d", t->element);
    node->lablen = strlen(node->label);

    return node;
}
asciinode * build_ascii_tree(Node * t) {
    asciinode *node;
    if (t == NULL) return NULL;
    node = build_ascii_tree_recursive(t);
    node->parent_dir = 0;
    return node;
}
void free_ascii_tree(asciinode *node) {
    if (node == NULL) return;
    free_ascii_tree(node->left);
    free_ascii_tree(node->right);
    free(node);
}
void compute_lprofile(asciinode *node, int x, int y) {
    int i, isleft;
    if (node == NULL) return;
    isleft = (node->parent_dir == -1);
    lprofile[y] = MIN(lprofile[y], x-((node->lablen-isleft)/2));
    if (node->left != NULL) {
        for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++) {
            lprofile[y+i] = MIN(lprofile[y+i], x-i);
        }
    }
    compute_lprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
    compute_lprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);
}
void compute_rprofile(asciinode *node, int x, int y) {
    int i, notleft;
    if (node == NULL) return;
    notleft = (node->parent_dir != -1);
    rprofile[y] = MAX(rprofile[y], x+((node->lablen-notleft)/2));
    if (node->right != NULL) {
        for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++) {
            rprofile[y+i] = MAX(rprofile[y+i], x+i);
        }
    }
    compute_rprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
    compute_rprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);
}
void compute_edge_lengths(asciinode *node) {
    int h, hmin, i, delta;
    if (node == NULL) return;
    compute_edge_lengths(node->left);
    compute_edge_lengths(node->right);

    /* first fill in the edge_length of node */
    if (node->right == NULL && node->left == NULL) {
        node->edge_length = 0;
    } else {
        if (node->left != NULL) {
            for (i=0; i<node->left->height && i < MAX_HEIGHT; i++) {
                rprofile[i] = -INFINITY;
            }
            compute_rprofile(node->left, 0, 0);
            hmin = node->left->height;
        }  else {
            hmin = 0;
        }

        if (node->right != NULL) {
            for (i=0; i<node->right->height && i < MAX_HEIGHT; i++) {
                lprofile[i] = INFINITY;
            }
            compute_lprofile(node->right, 0, 0);
            hmin = MIN(node->right->height, hmin);
        } else {
            hmin = 0;
        }
        delta = 4;
        for (i=0; i<hmin; i++) {
            delta = MAX(delta, gap + 1 + rprofile[i] - lprofile[i]);
        }

        //If the node has two children of height 1, then we allow the
        //two leaves to be within 1, instead of 2
        if (((node->left != NULL && node->left->height == 1) || (node->right != NULL && node->right->height == 1))&&delta>4) {
            delta--;
        }

        node->edge_length = ((delta+1)/2) - 1;
    }

    //now fill in the height of node
    h = 1;
    if (node->left != NULL) {
        h = MAX(node->left->height + node->edge_length + 1, h);
    }
    if (node->right != NULL) {
        h = MAX(node->right->height + node->edge_length + 1, h);
    }
    node->height = h;
}
void print_level(asciinode *node, int x, int level) {
    int i, isleft;
    if (node == NULL) return;
    isleft = (node->parent_dir == -1);
    if (level == 0) {
        for (i=0; i<(x-print_next-((node->lablen-isleft)/2)); i++)
        {
            printf(" ");
        }
        print_next += i;
        printf("%s", node->label);
        print_next += node->lablen;
    }
    else if (node->edge_length >= level)
    {
        if (node->left != NULL) {
            for (i=0; i<(x-print_next-(level)); i++)  {
                printf(" ");
            }
            print_next += i;
            printf("/");
            print_next++;
        }
        if (node->right != NULL) {
            for (i=0; i<(x-print_next+(level)); i++) {
                printf(" ");
            }
            print_next += i;
            printf("\\");
            print_next++;
        }
    } else {
        print_level(node->left,
                    x-node->edge_length-1,
                    level-node->edge_length-1);
        print_level(node->right,
                    x+node->edge_length+1,
                    level-node->edge_length-1);
    }
}
void print_ascii_tree(Node * t) {
    asciinode *proot;
    int xmin, i;
    if (t == NULL) return;
    proot = build_ascii_tree(t);
    compute_edge_lengths(proot);
    for (i=0; i<proot->height && i < MAX_HEIGHT; i++) {
        lprofile[i] = INFINITY;
    }
    compute_lprofile(proot, 0, 0);
    xmin = 0;
    for (i = 0; i < proot->height && i < MAX_HEIGHT; i++) {
        xmin = MIN(xmin, lprofile[i]);
    }
    for (i = 0; i < proot->height; i++) {
        print_next = 0;
        print_level(proot, -xmin, i);
        printf("\n");
    }
    if (proot->height >= MAX_HEIGHT) {
        printf("(This Node is taller than %d, and may be drawn incorrectly.)\n", MAX_HEIGHT);
    }

    free_ascii_tree(proot);
}
