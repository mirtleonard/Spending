#include "domain/spending.h"
#include "repository/repository.h"
#include "utils/service.h"
#include "ui/ui.h"

int main() {
    test_domain();
    test_repository();
    test_service();
    repository *repo = create_repository();
    service *srv = create_service(repo);
    ui_type *ui = create_ui(srv);
    ui_run(ui);
}