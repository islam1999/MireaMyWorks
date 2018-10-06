#include <stdio.h>
#include <mem.h>
#include <stdlib.h>
#include <ctype.h>

#include "treePrinter.h"

char *commands[] = {
        "help",
        "set",  /* INT */
        "move", /* DIRECTION */
        "add",  /* DIRECTION */
        "delete",
        "print",
        "save",
        "load",
        "exit"
};

int main() {
    ROOT_NODE = CURRENT_NODE = createNode(NULL, 0);
    ROOT_NODE->is_root = 1;

    int ex = 1;

    do{
        size_t size_in = sizeof(char) * 64;
        char *line = NULL;
        char *command = (char *) malloc(size_in);
        char *value   = (char *) malloc(size_in);
        printf("\nWrite command:\n");
        getline(&line, &size_in, stdin);

        int i=0;
        for ( i = 0; line[i] != '\n'; ++i) {
            if(line[i] != ' ') {
                command[i] = line[i];
            } else break;
        }
        command[i] = '\0';

        while (line[i] == ' ')
            i++;

        int j=0;
        for ( ;line[i] != '\n'; ++i, ++j) {
            if(line[i] != ' ') {
                value[j] = line[i];
            } else break;

        }
        value[j] = '\0';

        if(!strcmp(command, commands[0])){
            printf(
                           "set <digit>\n"
                           "move <parent/left/right>\n"
                           "add <left/right> <digit>\n"
                           "delete\n"
                           "print\n"
                           "save\n"
                           "load\n"
                           "exit\n");
        } else if(!strcmp(command, commands[1])){
                    CURRENT_NODE->element = atoi(value);
        }else if(!strcmp(command, commands[2])) {
            moveFromCurrentNode(value);
        }else if(!strcmp(command, commands[3])){
            char *value2 = (char *) malloc(size_in);
            while (line[i] == ' ')
                i++;
            for (++i, j=0 ; line[i] != '\0'; ++i, ++j) {
                if(line[i] != ' ') {
                    value2[j] = line[i];
                } else break;
            }
            value2[j] = '\0';
            addNode(value,atoi(value2));
            free(value2);
        }else if(!strcmp(command, commands[4])){
            deleteTreeFromNode(CURRENT_NODE);
        }else if(!strcmp(command, commands[5])){
            print_ascii_tree(ROOT_NODE);
            printf("\nLeaves: %d\n", getLeavesCount());
            printf("Nodes: %d\n", getNodesCount());
            printf("All: %d\n", getAllNodesCount());
        }else if(!strcmp(command, commands[6])){
            saveTreeInFile(ROOT_NODE);
        }else if(!strcmp(command, commands[7])){
            loadTreeFromFile();
        }else if(!strcmp(command, commands[8])){
            ex=0;
        }else printf("Try again, human...\n");

        free(line);
        free(command);
        free(value);
    }while(ex);

    return 0;
}