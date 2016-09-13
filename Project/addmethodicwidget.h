#ifndef ADDMETHODICWIDGET_H
#define ADDMETHODICWIDGET_H

#include <QWidget>
#include <QList>
#include <QPushButton>
#include <QLineEdit>
#include "trainday.h"

#include "databasemanager.h"

namespace Ui {
class AddMethodicWidget;
}



class AddMethodicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddMethodicWidget(QWidget *parent = 0);
    ~AddMethodicWidget();

    void SetCurrentSportsmen(int id);

    void SetDatamanager(DatabaseManager* mgr);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void OnAddDays();

private:
    void RemoveAllData();

private:
    Ui::AddMethodicWidget *ui;

    QPushButton* m_addDay;
    QLineEdit *m_trainCount;

    int m_rows;
    int m_columns;

    int m_currentSportsmen;

    QList<TrainDay*> m_days;
    DatabaseManager* m_database;
};

#endif // ADDMETHODICWIDGET_H
