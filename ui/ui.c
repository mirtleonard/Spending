#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
//
// Created by leonard on 16.03.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../domain/spending.h"
#include "../repository/repository.h"
#include "../utils/service.h"
#include "../validators/validator.h"
#include "ui.h"

ui_type *create_ui(service *srv) {
    ui_type *ui = malloc(sizeof(ui_type));
    ui->srv = srv;
    return ui;
}

void delete_ui(ui_type *ui) {
    delete_service(ui->srv);
    free(ui);
}

void ui_help() {
    printf("'help' - afiseaza comenzile\n");
    printf("'add' - adauga o factura\n");
    printf("'remove' - sterge o factura\n");
    printf("'modify' - modifica o factura\n");
    printf("'print' - afiseaza toate facturile\n");
    printf("'order' - ordoneaza facturile dupa suma (crescator/descrescator)\n");
    printf("'filter' - filtreaza facturile dupa suma sau tip (ex tip = 'gaz')\n");
}

void ui_add(service *srv) {
    printf("Introdu numarul apartamentului, suma si tipul cheltuielii:\n");
    char *input = malloc(sizeof(char) * 1000);
    char *type = malloc(sizeof(char) * 500);
    int no_ap;
    double sum;
    gets(input);
    if (validate_add(input, &no_ap, &sum, type)) {
        service_add(srv, no_ap, sum, type);
    } else {
        printf("Nu ai introdus input-ul corect\n");
    }
    free(type);
    free(input);
}

void ui_remove(service *srv) {
    int id;
    char *input = malloc(sizeof(char) * 1000);
    printf("Introdu id-ul cheltuielii: ");
    gets(input);
    if (validate_remove(input, &id, srv->repo->size)) {
        service_remove(srv, id);
    } else {
        printf("Nu ai introdus input-ul corect\n");
    }
    free(input);
}

void ui_modify(service *srv) {
    int id;
    double sum;
    char *type = malloc(sizeof(char) * 500);
    char *input = malloc(sizeof(char) * 1000);
    printf("Introdu id-ul, noua suma si noul tip pentru cheltuiala: ");
    if (validate_modify(input, &id, &sum, type)) {
        service_modify(srv, id, sum, type);
    } else {
        printf("Nu ai introdus input-ul corect\n");
    }
    free(type);
    free(input);
}

void ui_print(service *srv) {
    char *result = service_print(srv);
    printf("%s", result);
    free(result);
}

void ui_order(service *srv) {
    int op = 0, type = 0;
    char *input1 = malloc(sizeof(char) * 1000);
    char *input2 = malloc(sizeof(char) * 1000);
    printf("Introdu 0 pentru a sorta descrescator si 1 pentru crescator: ");
    gets(input1);
    printf("Introdu 0 pentru a sorta dupa suma si 1 pentru a sorta dupa tip: ");
    gets(input2);
    if (validate_order(input1, input2, &op, &type)) {
        char *result = service_order(srv, op, type);
        printf("%s", result);
        free(result);
    } else {
        printf("Nu ai introdus inputul corect\n");
    }
}

void ui_filter(service *srv) {
    char *field = malloc(sizeof(char) * 1000);
    char *key = malloc(sizeof(char) * 1000);
    char *result;
    printf("Introdu campul dupa care vrei sa filtrez(numar/suma/tip): ");
    scanf("%s", field);
    printf("Introdu valoarea dupa care vrei sa filtrezi, %s = ", field);
    scanf("%s", key);
    result = service_filter(srv, field, key);
    printf("%s", result);
    free(result);
    free(field);
    free(key);
}

void add_default(service *srv) {
    service_add(srv, 1, 200.32,"gaz");
    service_add(srv, 1, 10.21,"curent");
    service_add(srv, 2, 1901,"gaz");
    service_add(srv, 3, 90.85,"apa");
    service_add(srv, 1, 10.32,"canal");
}

void ui_run(ui_type *ui) {
    add_default(ui->srv);
    char *input = malloc(sizeof(char) * 1000);
    printf("Salutare, aceasta aplicatie gestioneaza facturile tale\n"
           "pentru a afla ce poti face in aplicatie introdu comanda 'help'\n"
           "iar daca vrei sa iesi din aplicatie introdu comanda 'exit'\n");
    while(1) {
        gets(input);
        if (!strcmp(input, "exit")) {
            printf("Bye\n");
            free(input);
            return;
        } else if (!strcmp(input, "help")) {
            ui_help();
        } else if (!strcmp(input, "add")) {
            ui_add(ui->srv);
        } else if (!strcmp(input, "modify")) {
            ui_modify(ui->srv);
        } else if (!strcmp(input, "remove")) {
            ui_remove(ui->srv);
        } else if (!strcmp(input, "order")) {
            ui_order(ui->srv);
        } else if (!strcmp(input, "filter")) {
            ui_filter(ui->srv);
        } else if (!strcmp(input, "print")) {
            ui_print(ui->srv);
        } else {
            printf("Ai introdus o comanda invalida, introdu 'help' daca te-ai blocat\n");
        }
    }
}