#ifndef ADDPROGRAMWIDGET_H
#define ADDPROGRAMWIDGET_H

#include <QWidget>

namespace Ui {
class AddProgramWidget;
}

class AddProgramWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddProgramWidget(QWidget *parent = 0);
    ~AddProgramWidget();

private:
    Ui::AddProgramWidget *ui;
};

#endif // ADDPROGRAMWIDGET_H
