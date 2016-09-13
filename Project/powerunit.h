#ifndef POWERUNIT_H
#define POWERUNIT_H

#include <QWidget>

namespace Ui {
class PowerUnit;
}

struct WRS
{
    double weight;
    int count;
    int sets;
};

class PowerUnit : public QWidget
{
    Q_OBJECT

public:
    explicit PowerUnit(QWidget *parent = 0);
    ~PowerUnit();

    void SetWeight(double weight);
    void SetCount(int count);
    void SetSets(int setsCount);

    void GetWRS(WRS* data);

private:

    double GetWeight();
    int GetCount();
    int GetSets();

private:
    Ui::PowerUnit *ui;
};

#endif // POWERUNIT_H
