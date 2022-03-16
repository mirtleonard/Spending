//
// Created by leonard on 16.03.2022.
//

#ifndef LAB3_UI_H
#define LAB3_UI_H

typedef struct {
    service *srv;
}ui_type;

ui_type *create_ui(service *srv);
void delete_ui(ui_type *ui);
void ui_run(ui_type *ui);

#endif //LAB3_UI_H
