//
// Created by leonard on 16.03.2022.
//

#ifndef LAB3_SERVICE_H
#define LAB3_SERVICE_H

typedef struct {
    repository* repo;
} service;

service *create_service(repository *repo);
void delete_service(service *srv);
int add_spending(service *srv, int ap_no, int sum, char *type);
int remove_spending(service *srv, int id);
char *service_order(service *srv, char *field, char *key);
char *service_filter(service *srv, char *field, char *key);
void test_service();

#endif //LAB3_SERVICE_H
