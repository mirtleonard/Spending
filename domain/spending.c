//
// Created by leonard on 10.03.2022.
//

#include<assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "spending.h"

spending_type* create_spending(int ap_no, int sum, char *type) {
    spending_type *spending  = malloc(sizeof(spending_type));
    spending->type = malloc(strlen(type));
    strcpy(spending->type, type);
    spending->sum = sum;
    spending->ap_no = ap_no;
    return spending;
}

void delete_spending(spending_type* spending) {
    free(spending->type);
    free(spending);
}


void test_domain() {
    int sum = 20, ap_no = 10;
    char type[] = "gaz";
    spending_type *spending = create_spending(ap_no, sum, type);
    assert(spending->ap_no == ap_no);
    assert(spending->sum == sum);
    assert(!strcmp(spending->type, type));
}