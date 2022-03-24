#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
//
// Created by leonard on 24.03.2022.
//

#include <stdlib.h>
#include <string.h>
#include "validator.h"

int validate_add(char *input, int *ap, double *sum, char *type) {
    char *p = strtok(input, " ");
    *ap = strtol(p, NULL, 10);
    p = strtok(NULL, " ");
    *sum = strtof(p, NULL);
    p = strtok(NULL, " ");
    strcpy(type, p);
    if (type == NULL || *ap <= 0 || sum <= 0) {
        return 0;
    }
    return 1;
}

int validate_remove(char *input, int *id, int size) {
    *id = strtol(input, NULL, 10);
    if (*id > 0 && *id < size) {
        return 1;
    }
    return 0;
}

int validate_modify(char *input, int *id, int *sum, char *type) {
    char *p = strtok(input, " ");
    *id = strtol(p, NULL, 10);
    p = strtok(NULL, " ");
    *sum = strtof(p, NULL);
    p = strtok(NULL, " " );
    strcpy(type, p);
}

int validate_order(char *input1, char *input2, int *op, int *type) {
    *op = strtol(input1, NULL, 10);
    *type = strtol(input2, NULL, 10);
    return (*op == 0 || *op == 1) && (*type == 0 || *type == 1);
}
