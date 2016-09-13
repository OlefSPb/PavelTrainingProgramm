#ifndef POWER_H
#define POWER_H

#include <QWidget>
#include <QMap>

#include "powerunit.h"

namespace Ui {
class Power;
}

struct Exercise
{
    int gymType;
    QList<WRS> wrsList;
};

class Power : public QWidget
{
    Q_OBJECT

public:
    explicit Power(QWidget *parent = 0);
    ~Power();
    void Update();

    void GetExercises(Exercise* exercise);

private slots:
    void OnAddPower();

private:
    Ui::Power *ui;
    QList<PowerUnit*> m_units;

    QStringList m_availExeciseList;
    QMap<int, QString> m_execiseMap;
};

#endif // POWER_H
