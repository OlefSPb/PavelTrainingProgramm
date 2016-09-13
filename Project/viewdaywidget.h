#ifndef VIEWDAYWIDGET_H
#define VIEWDAYWIDGET_H

#include <QWidget>

namespace Ui {
class ViewDayWidget;
}

class ViewDayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ViewDayWidget(QWidget *parent = 0);
    ~ViewDayWidget();
    void AppendData(const QString& name, const QString& date, int weight, int reps, int sets);

private:
    Ui::ViewDayWidget *ui;


};

#endif // VIEWDAYWIDGET_H
