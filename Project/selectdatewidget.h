#ifndef SELECTDATEWIDGET_H
#define SELECTDATEWIDGET_H

#include <QWidget>

namespace Ui {
class SelectDateWidget;
}

class SelectDateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SelectDateWidget(QWidget *parent = 0);
    ~SelectDateWidget();


private slots:

    void OnOkClicked();

signals:

    void DatesChanged(QString dataStart, QString dataEnd);

private:
    Ui::SelectDateWidget *ui;
};

#endif // SELECTDATEWIDGET_H
