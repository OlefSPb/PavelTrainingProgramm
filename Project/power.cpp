#include "power.h"
#include "ui_power.h"

#include <QSqlQuery>
#include <QSqlRecord>

#include "powerunit.h"


Power::Power(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Power)
{
    ui->setupUi(this);

    bool connection;
    connection = connect(ui->addPowerUnit, SIGNAL(clicked()), SLOT(OnAddPower())); Q_ASSERT(connection);

    Update();
}

Power::~Power()
{
    delete ui;
}

void Power::Update()
{
    m_execiseMap.clear();
    m_availExeciseList.clear();
    ui->comboBox->clear();
    QSqlQuery query;
    bool result = query.exec("Select gym_id, name from gym");
    if (!result)
    {
        return;
    }

     int id;
     QString name;
     QSqlRecord rec = query.record();
      while (query.next())
      {
          id = query.value(rec.indexOf("gym_id")).toInt();
          name = query.value(rec.indexOf("name")).toString();
          m_execiseMap.insert(id, name);
          m_availExeciseList.append(name);
      }

      ui->comboBox->addItems(m_availExeciseList);
}

void Power::GetExercises(Exercise* exercise)
{
    int index = ui->comboBox->currentIndex();
    QString item = ui->comboBox->itemText(index);
    for (QMap<int, QString>::const_iterator iter = m_execiseMap.begin(); iter != m_execiseMap.end(); ++iter)
    {
        if (iter.value() == item)
        {
            exercise->gymType = iter.key();
            break;
        }
    }

    for (int i = 0, size = m_units.size(); i < size; ++i)
    {
        WRS unit;
        m_units[i]->GetWRS(&unit);
        exercise->wrsList.append(unit);
    }
}

void Power::OnAddPower()
{
    PowerUnit *pUnit = new PowerUnit();
    QGridLayout* layout = qobject_cast<QGridLayout*>(ui->frame->layout());
    layout->addWidget(pUnit,0, layout->columnCount(),  1, 1 );
    m_units.append(pUnit);
}
