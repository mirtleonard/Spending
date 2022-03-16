//
// Created by leonard on 13.03.2022.
//

#ifndef LAB3_REPOSITORY_H
#define LAB3_REPOSITORY_H

typedef struct {
    spending_type **list;
    int size, capacity;
} repository;

repository * create_repository();
void add_to_repository(repository *repo, spending_type  *spending);
void delete_repository(repository *repo);
int delete_id(repository *repo, int id);
void test_repository();

#endif //LAB3_REPOSITORY_H
