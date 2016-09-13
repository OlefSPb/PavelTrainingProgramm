#ifndef VIEWMETHODICWIDGET_H
#define VIEWMETHODICWIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QCloseEvent>

#include "viewdaywidget.h"

namespace Ui {
class ViewMethodicWidget;
}

class ViewMethodicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ViewMethodicWidget(QWidget *parent = 0);
    ~ViewMethodicWidget();

    void SetDates(const QString& startDate, const QString& endDate);

    void SetUserId(int uId);

protected:

    void closeEvent(QCloseEvent *event);

private:
    Ui::ViewMethodicWidget *ui;

    int m_currentUser;

    QVector<ViewDayWidget*> m_viewWidgets;

    int m_currentRow;
    int m_currentColumn;
};

#endif // VIEWMETHODICWIDGET_H
