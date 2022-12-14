//
// Created by Rufelle on 18/10/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_UI.h" resolved

#include "ui.h"
#include "ui_UI.h"

namespace uistd {
    UI::UI(QWidget *parent) :
            QWidget(parent), ui(new Ui::UI) {
        ui->setupUi(this);
    }

    UI::~UI() {
        delete ui;
    }
} // uistd
