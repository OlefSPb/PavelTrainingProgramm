#include "execisewidget.h"
#include "ui_execisewidget.h"
#include <QSqlQuery>
#include <QMessageBox>

ExeciseWidget::ExeciseWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExeciseWidget)
{
    ui->setupUi(this);

    model = new QSqlTableModel();
    model->setTable("gym");
    model->setSort(1, Qt::AscendingOrder);
    model->select();

    ui->tableView->setModel(model);

    bool connection = connect(ui->pushButton, SIGNAL(clicked()), SLOT(OnAddExeciseClicked())); Q_ASSERT(connection);
}

ExeciseWidget::~ExeciseWidget()
{
    delete model;
    delete ui;
}

void ExeciseWidget::OnAddExeciseClicked()
{
    int cRow = model->rowCount();
    model->insertRow(cRow);
    model->setData(model->index(cRow, 0), cRow);
    model->setData(model->index(cRow, 1), ui->lineEdit->text());
    model->setData(model->index(cRow, 2), QString::fromUtf8("кг"));
    bool result = model->submit();

    if (!result)
    {
        QMessageBox::warning(this, QString::fromUtf8("Ошибка"), QString::fromUtf8("Невозможно добавить упражнение"), QMessageBox::Ok, QMessageBox::NoButton);
    }
}
