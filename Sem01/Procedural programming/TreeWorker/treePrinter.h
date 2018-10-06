#ifndef TREEWORKER_TREEPRINTER_H
#define TREEWORKER_TREEPRINTER_H

#define INFINITY (1<<20)
#define MAX_HEIGHT 1000




typedef struct Tree_s{
    struct Tree_s *parent;
    struct Tree_s *left;
    struct Tree_s *right;
    int is_root;
    int element;
} Node;

Node *CURRENT_NODE;
Node *ROOT_NODE;

int LEAVES;
int NODES;
Node *createNode(Node *parent, int element);
void moveFromCurrentNode(char *value);
void deleteTreeFromNode(Node *root);
void addNode (char* direction, int element);

int getLeavesCount();
void countOfLeaves(Node *root);
int getNodesCount();
void countOfNodes(Node *root);
int getAllNodesCount();
void saveTreeInFile(Node *tree);
void loadTreeFromFile();

/* printer */
typedef struct asciinode_struct asciinode;

struct asciinode_struct {
    asciinode * left, * right;
    int edge_length;
    int height;
    int lablen;
    int parent_dir;
    char label[11];
};

asciinode *build_ascii_tree_recursive(Node * t);
asciinode * build_ascii_tree(Node * t);
void free_ascii_tree(asciinode *node);
void compute_lprofile(asciinode *node, int x, int y);
void compute_rprofile(asciinode *node, int x, int y);
void compute_edge_lengths(asciinode *node);
void print_level(asciinode *node, int x, int level);
void print_ascii_tree(Node * t);

#endif
