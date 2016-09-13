#include "addprogramwidget.h"
#include "ui_addprogramwidget.h"

AddProgramWidget::AddProgramWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddProgramWidget)
{
    ui->setupUi(this);
}

AddProgramWidget::~AddProgramWidget()
{
    delete ui;
}
