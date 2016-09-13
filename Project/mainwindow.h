#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addmethodicwidget.h"
#include "databasemanager.h"
#include "execisewidget.h"
#include "viewmethodicwidget.h"

#include "selectdatewidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void OnAddProgramClicked();
    void OnViewProgramClicked();

    void OnAddExecise();

    void ShowViewProgram(QString startDate, QString endDate);

private:
    Ui::MainWindow *ui;
    AddMethodicWidget* m_addMethodicWidget;
    ExeciseWidget* m_execiseWidget;
    SelectDateWidget* selectDateWidget;

    ViewMethodicWidget* m_viewMehodicWidget;

    DatabaseManager m_DatabaseManager;

};

#endif // MAINWINDOW_H
