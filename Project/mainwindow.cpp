#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    m_DatabaseManager.Connect("hobbits.db");
    QList<Sportsmen> sportsmenList = m_DatabaseManager.GetSportsmens();

    for (int i = 0, size = sportsmenList.size(); i < size; ++i)
    {
        ui->m_sportsmenCombo->addItem(sportsmenList[i].name + " " + sportsmenList[i].surname);
    }

    m_execiseWidget = new ExeciseWidget();


    bool connection;
    connection = connect(ui->m_addProgram, SIGNAL(clicked()), SLOT(OnAddProgramClicked())); Q_ASSERT(connection);
    connection = connect(ui->m_viewProgram, SIGNAL(clicked()), SLOT(OnViewProgramClicked())); Q_ASSERT(connection);
    connection = connect(ui->m_addExecise, SIGNAL(clicked()), SLOT(OnAddExecise())); Q_ASSERT(connection);

    m_addMethodicWidget = new AddMethodicWidget();
    m_addMethodicWidget->setGeometry(100,100, 1024, 768);
    m_addMethodicWidget->hide();

    selectDateWidget = new SelectDateWidget();
    selectDateWidget->hide();
    connection = connect(selectDateWidget, SIGNAL(DatesChanged(QString,QString)), SLOT(ShowViewProgram(QString, QString))); Q_ASSERT(connection);

    m_viewMehodicWidget = new ViewMethodicWidget();
    m_viewMehodicWidget->hide();

    m_addMethodicWidget->SetDatamanager(&m_DatabaseManager);
}

MainWindow::~MainWindow()
{
    delete m_execiseWidget;
    delete selectDateWidget;
    delete m_viewMehodicWidget;
    delete ui;
}


void MainWindow::OnAddProgramClicked()
{
    int index = ui->m_sportsmenCombo->currentIndex();
    m_addMethodicWidget->SetCurrentSportsmen((m_DatabaseManager.GetSportsmens())[index].user_id);
    m_addMethodicWidget->show();
}

void MainWindow::OnViewProgramClicked()
{
    selectDateWidget->show();
}

void MainWindow::OnAddExecise()
{
    m_execiseWidget->show();
}

void MainWindow::ShowViewProgram(QString startDate, QString endDate)
{
    int index = ui->m_sportsmenCombo->currentIndex() + 1;
    m_DatabaseManager.SetSportsmenId(index);
    m_viewMehodicWidget->SetUserId(index);
    m_viewMehodicWidget->SetDates(startDate, endDate);
    m_viewMehodicWidget->show();
}
