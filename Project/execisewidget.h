#ifndef EXECISEWIDGET_H
#define EXECISEWIDGET_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QSqlTableModel>

namespace Ui {
class ExeciseWidget;
}

class ExeciseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ExeciseWidget(QWidget *parent = 0);
    ~ExeciseWidget();

private slots:

    void OnAddExeciseClicked();

private:
    Ui::ExeciseWidget *ui;

    QSqlTableModel *model;
};

#endif // EXECISEWIDGET_H
