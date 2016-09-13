#include "addmethodicwidget.h"
#include "ui_addmethodicwidget.h"

#include "trainday.h"
#include <QMessageBox>

AddMethodicWidget::AddMethodicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddMethodicWidget),
    m_rows(0),
    m_columns(0)
{
    ui->setupUi(this);

    bool connection;

    m_addDay = new QPushButton(this);
    m_addDay->setText(QString::fromUtf8("Добавить тренировки"));
    ui->gridLayout->addWidget(m_addDay, 999, 0, 1, 1);
    m_addDay->show();
    m_trainCount = new QLineEdit(this);
    m_trainCount->setText("");
    ui->gridLayout->addWidget(m_trainCount, 999, 1, 1, 1);
    m_trainCount->show();
    connection = connect(m_addDay, SIGNAL(clicked()), SLOT(OnAddDays())); Q_ASSERT(connection);
}

AddMethodicWidget::~AddMethodicWidget()
{
    delete ui;
}

void AddMethodicWidget::SetCurrentSportsmen(int id)
{
    m_currentSportsmen = id;
}

void AddMethodicWidget::SetDatamanager(DatabaseManager* mgr)
{
    m_database = mgr;
}

void AddMethodicWidget::RemoveAllData()
{
    while (m_days.size() > 0)
    {
        delete m_days[0];
        m_days.removeAt(0);
    }
}

void AddMethodicWidget::closeEvent(QCloseEvent *event)
{
    QList<TDay> days;
    for (int i = 0, size = m_days.size(); i < size; ++i)
    {
        days.append(TDay());
        m_days[i]->GetDayInfo(&days[i]);
    }
    m_database->SetSportsmenId(m_currentSportsmen);
    m_database->DumpToBase(days);

    RemoveAllData();
}

void AddMethodicWidget::OnAddDays()
{
    int count = m_trainCount->text().toInt();
    if ((count > 0) && (count < 11))
    {
        while (count > 0)
        {
            TrainDay* day = new TrainDay();
            ui->gridLayout->addWidget(day, m_rows, m_columns, 1, 1);
            ++m_columns;
            if (m_columns == 3)
            {
                m_columns = 0;
                ++m_rows;
            }
            day->show();
            m_days.append(day);
            --count;
        }
    }
    else
    {
        QMessageBox::warning(this, "Error!", "The count of days (< 0 or > 10)");
    }
}
