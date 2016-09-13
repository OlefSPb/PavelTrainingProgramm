#include "viewdaywidget.h"
#include "ui_viewdaywidget.h"

ViewDayWidget::ViewDayWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewDayWidget)
{
    ui->setupUi(this);
}

ViewDayWidget::~ViewDayWidget()
{
    while (ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(0);
    }
    delete ui;
}

void ViewDayWidget::AppendData(const QString& name, const QString& date, int weight, int reps, int sets)
{
    QTableWidgetItem* item0 = new QTableWidgetItem(name);
    QTableWidgetItem* item1 = new QTableWidgetItem(QString::number(weight));
    QTableWidgetItem* item2 = new QTableWidgetItem(QString::number(reps));
    QTableWidgetItem* item3 = new QTableWidgetItem(QString::number(sets));
    ui->dateEdit->setDate(QDate::fromString(date, "yyyy-MM-dd"));
    int r = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(r);
    ui->tableWidget->setItem(r, 0, item0);
    ui->tableWidget->setItem(r, 1, item1);
    ui->tableWidget->setItem(r, 2, item2);
    ui->tableWidget->setItem(r, 3, item3);
}
