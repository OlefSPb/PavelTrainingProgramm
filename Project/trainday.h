#ifndef TRAINDAY_H
#define TRAINDAY_H

#include <QWidget>
#include <QList>
#include <QDate>
#include <power.h>

namespace Ui {
class TrainDay;
}

#pragma pack(push, 1)
struct TDay
{
    QDate date;
    QList<Exercise> data;

};
#pragma pop

class TrainDay : public QWidget
{
    Q_OBJECT

public:
    explicit TrainDay(QWidget *parent = 0);
    ~TrainDay();

    void GetDayInfo(TDay* day);

private:
    void AddPower();

private:
    Ui::TrainDay *ui;
    QList<Power*> m_powerList;
};

#endif // TRAINDAY_H
