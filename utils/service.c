//
// Created by leonard on 16.03.2022.
//
#include "../domain/spending.h"
#include "../repository/repository.h"
#include "service.h"
#include <stdlib.h>
#include <assert.h>

service *create_service(repository *repo) {
   service *srv = malloc(sizeof(service));
   srv->repo = repo;
   return srv;
}

char *service_order(service *srv, char *field, char *key) {
   return "";
}

char *service_filter(service *srv, char *field, char *key) {
   repository *filtered = repository_filter(srv->repo, field, key);
   char *result = malloc(filtered->size * 50);
   itoa();
   return "";
}

void delete_service(service *srv) {
    delete_repository(srv->repo);
    free(srv);
}

int add_spending(service *srv, int ap_no, int sum, char *type) {
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

void test_service() {
    repository *repo = create_repository();
    service *srv = create_service(repo);
    add_spending(srv, 18, 2000, "gaz");
    remove_spending(srv, 0);
    delete_service(srv);
}