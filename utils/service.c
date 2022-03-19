//
// Created by leonard on 16.03.2022.
//
#include "../domain/spending.h"
#include "../repository/repository.h"
#include "service.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

service *create_service(repository *repo) {
   service *srv = malloc(sizeof(service));
   srv->repo = repo;
   return srv;
}


char *stringify(repository *repo) {
    char *result = (char *) malloc(repo->size * 100 * sizeof(char));
    char *int_to_char = (char *) malloc(10 * sizeof(char));
    result[0] = 0;
    for (int i = 0; i < repo->size; ++i) {
        sprintf(int_to_char, "%d ", repo->list[i]->ap_no);
        strcat(result, int_to_char);
        sprintf(int_to_char, "%lf ", repo->list[i]->sum);
        strcat(result, int_to_char);
        strcat(result, repo->list[i]->type);
        strcat(result, "\n");
    }
    free(int_to_char);
    return result;
}

char *service_filter(service *srv, char *field, char *key) {
   repository *filtered = repository_filter(srv->repo, field, key);
   char *result = stringify(filtered);
   return result;
}

char *service_print(service *srv) {
    return stringify(srv->repo);
}

void delete_service(service *srv) {
    delete_repository(srv->repo);
    free(srv);
}

int add_spending(service *srv, int ap_no, double sum, char *type) {
    //validators
    spending_type *spending = create_spending(ap_no, sum, type);
    add_to_repository(srv->repo, spending);
    return 1;
}

int remove_spending(service *srv, int id) {
    //validators
    delete_id(srv->repo, id);
    return 1;
}

int service_modify(service *srv, int id, double sum, char *type) {
    //validators
   repository_modify(srv->repo, id, sum, type);
   return 1;
}

char *service_order(service *srv, int op, int type) {
    repository *ordered = create_repository();
    ordered = repository_order(srv->repo, op, type);
    return stringify(ordered);
}

void test_service() {
    repository *repo = create_repository();
    service *srv = create_service(repo);
    add_spending(srv, 18, 2000, "gaz");
    add_spending(srv, 17, 1031.5, "gaz");
    add_spending(srv, 16, 31.5, "curent");
    service_modify(srv, 0, 1999.2, "gaz");
    service_order(srv, 1, 1);
    char *result = service_filter(srv, "tip", "gaz");
    service_print(srv);
    //assert(!strcmp(result, "18 1999.200000 gaz\n17 1031.500000 gaz\n"));
    free(result);
    remove_spending(srv, 0);
    delete_service(srv);
}