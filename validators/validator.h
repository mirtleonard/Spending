//
// Created by leonard on 24.03.2022.
//

#ifndef LAB3_VALIDATOR_H
#define LAB3_VALIDATOR_H

int validate_add(char *input, int *ap, double *sum, char *type);
int validate_remove(char *input, int *id, int size);
int validate_modify(char *input, int *id, int *sum, char *type);
int validate_order(char *input1, char *input2, int *op, int *type);

#endif //LAB3_VALIDATOR_H


