//
// Created by leonard on 16.03.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../domain/spending.h"
#include "../repository/repository.h"
#include "../utils/service.h"
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
    printf("'view' - afiseaza facturile\n");
    printf("'add' - adauga o factura\n");
    printf("'remove' - sterge o factura\n");
    printf("'modify' - modifica o factura\n");
    printf("'order' - ordoneaza facturile dupa suma sau tip(crescator/descrescator)\n");
    printf("'filter' - filtreaza facturile dupa suma, tip sau apartament(ex tip = 'gaz')\n");
}

void ui_add(service *srv) {
    printf("Introdu numarul apartamentului, suma si tipul cheltuielii:\n");
    int no_ap;
    double sum;
    char *type = malloc(sizeof(char) * 10);
    scanf("%d %lf %s", &no_ap, &sum, type);
    add_spending(srv, no_ap, sum, type);
}
void ui_remove(service *srv) {
   return;
}
void ui_modify(service *srv) {
   return;
}
void ui_order(service *srv) {
   return;
}
void ui_filter(service *srv) {
   return;
}
void ui_view(service *srv) {
   return;
}


void ui_run(ui_type *ui) {
    char *input = malloc(sizeof(char) * 10);
    printf("Salutare, aceasta aplicatie gestioneaza facturile tale\n"
           "pentru a afla ce poti face in aplicatie introdu comanda 'help'\n"
           "iar daca vrei sa iesi din aplicatie introdu comanda 'exit'\n");
    while(1) {
        scanf("%s", input);
        if (!strcmp(input, "exit")) {
            printf("Bye\n");
            delete_ui(ui);
            return;
        } else if (!strcmp(input, "help")) {
            ui_help();
        } else if (!strcmp(input, "add")) {
            ui_add(ui->srv);
        } else if (!strcmp(input, "view")) {
            ui_view(ui->srv);
        } else if (!strcmp(input, "modify")) {
            ui_modify(ui->srv);
        } else if (!strcmp(input, "remove")) {
            ui_remove(ui->srv);
        } else if (!strcmp(input, "order")) {
            ui_order(ui->srv);
        } else if (!strcmp(input, "filter")) {
            ui_filter(ui->srv);
        } else {
            printf("Ai introdus o comanda invalida, introdu 'help' daca te-ai blocat");
        }
    }
    free(input);
}


