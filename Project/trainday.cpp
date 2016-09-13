#include "trainday.h"
#include "ui_trainday.h"

#include <QFrame>
#include <QGridLayout>

#include <QMessageBox>

TrainDay::TrainDay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrainDay)
{
    ui->setupUi(this);

    bool connection;

    for (int i = 0; i < 5; ++i)
    {
        AddPower();
    }
}

TrainDay::~TrainDay()
{

    foreach(Power* unit, m_powerList)
    {
        delete unit;
    }

    delete ui;
}

void TrainDay::GetDayInfo(TDay* day)
{
    day->date = ui->dateEdit->date();
    for (int i = 0, size = m_powerList.size(); i < size; ++i)
    {
        day->data.append(Exercise());
        m_powerList[i]->GetExercises(&day->data[i]);
    }
}

void TrainDay::AddPower()
{
    Power* unit = new Power();
    QGridLayout* layout = qobject_cast<QGridLayout*>(ui->trainFrame->layout());
    layout->addWidget(unit, layout->rowCount(), 0, 1, 1);
    unit->show();
    m_powerList.append(unit);
}
