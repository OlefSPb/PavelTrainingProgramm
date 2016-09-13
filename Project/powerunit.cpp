#include "powerunit.h"
#include "ui_powerunit.h"

PowerUnit::PowerUnit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PowerUnit)
{
    ui->setupUi(this);
}

PowerUnit::~PowerUnit()
{
    delete ui;
}


double PowerUnit::GetWeight()
{
    return ui->m_weight->text().toDouble();
}

int PowerUnit::GetCount()
{
    return ui->m_count->text().toInt();
}

int PowerUnit::GetSets()
{
    return ui->m_sets->text().toInt();
}

void PowerUnit::SetWeight(double weight)
{
    ui->m_weight->setText(QString::number(weight));
}

void PowerUnit::SetCount(int count)
{
    ui->m_weight->setText(QString::number(count));
}

void PowerUnit::SetSets(int setsCount)
{
    ui->m_weight->setText(QString::number(setsCount));
}

void PowerUnit::GetWRS(WRS* data)
{
    data->weight = GetWeight();
    data->sets = GetSets();
    data->count = GetCount();
}
