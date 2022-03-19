//
// Created by leonard on 13.03.2022.
//

#ifndef LAB3_REPOSITORY_H
#define LAB3_REPOSITORY_H

typedef struct {
    spending_type **list;
    int size, capacity;
} repository;

repository *create_repository();
repository *repository_filter(repository *repo, char *field, char *key);
repository *repository_order(repository *repo, int op, int type);
void repository_add(repository *repo, spending_type  *spending);
void repository_modify(repository *repo, int id, double sum, char *type);
void delete_repository(repository *repo);
int repository_delete(repository *repo, int id);
void test_repository();

#endif //LAB3_REPOSITORY_H
