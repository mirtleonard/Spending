//
// Created by leonard on 13.03.2022.
//

#include "../domain/spending.h"
#include "repository.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

repository *create_repository() {
    repository *repo = malloc(sizeof(repository));
    repo->capacity = 1;
    repo->size = 0;
    repo->list = malloc(repo->capacity * sizeof(spending_type*));
    return  repo;
}

void delete_repository(repository *repo) {
    for (int i = 0; i < repo->size; ++i) {
        delete_spending(repo->list[i]);
    }
    free(repo);
}

void realloc_repository(repository *repo, int new_capacity) {
    spending_type **new_list = malloc(new_capacity * sizeof(spending_type));
    for (int i = 0; i < repo->size; ++i) {
        new_list[i] = repo->list[i];
    }
    free (repo->list);
    repo->list = new_list;
    repo->capacity = new_capacity;
}

void add_to_repository(repository *repo, spending_type  *spending) {
    if (repo->size == repo->capacity) {
        realloc_repository(repo, repo->capacity * 2);
    }
    repo->list[repo->size] = spending;
    repo->size++;
}

int delete_id(repository *repo, int id) {
    if (id >= repo->size) {
        return 0;
    }
    delete_spending(repo->list[id]);
    for (int i = id; i <= repo->size; ++i) {
        repo->list[i] = repo->list [i + 1];
    }
    --repo->size;
    return 1;
}

repository *repository_filter(repository *repo, char *field, char *key) {
    repository *filtered = create_repository();
    realloc_repository(filtered, repo->capacity);
    for (int i = 0; i < repo->size; ++i) {
        if (!strcmp(field, "numar")) {
            if (atoi(key) == repo->list[i]->ap_no) {
                filtered->list[filtered->size] = repo->list[i];
                ++filtered->size;
            }
        } else if(!strcmp(field, "suma")) {
            if (atoi(key) == repo->list[i]->sum) {
                filtered->list[filtered->size] = repo->list[i];
                ++filtered->size;
            }
        } else if(!strcmp(field, "tip")) {
            if (!strcmp(key, repo->list[i]->type) {
                filtered->list[filtered->size] = repo->list[i];
                ++filtered->size;
            }
        }
    }
    return filtered;
}

void test_repository() {
    repository *repo = create_repository();
    assert(repo != NULL);
    spending_type *spending = create_spending(21, 100, "curent");
    add_to_repository(repo, spending);
    spending = create_spending(20, 200, "gaz");
    add_to_repository(repo, spending);
    assert(delete_id(repo, 0) == 1);
    delete_repository(repo);
}