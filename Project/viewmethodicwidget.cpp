#include "viewmethodicwidget.h"
#include "ui_viewmethodicwidget.h"
#include "QSqlError"

ViewMethodicWidget::ViewMethodicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewMethodicWidget),
    m_currentUser(-1),
    m_currentRow(0),
    m_currentColumn(0)
{
    ui->setupUi(this);
}

ViewMethodicWidget::~ViewMethodicWidget()
{
    while (m_viewWidgets.size() > 0)
    {
        delete m_viewWidgets[0];
        m_viewWidgets.remove(0);
    }

    delete ui;
}

void ViewMethodicWidget::SetDates(const QString& startDate, const QString& endDate)
{
    QSqlQuery query;
    QString queryStr = QString(" SELECT gym.name,plan_gym.time, plan_gym.weight, plan_gym.reps, plan_gym.sets "
                               " FROM plan_gym, gym "
                               " INNER JOIN user ON plan_gym.user_id = user.user_id "
                               " WHERE (plan_gym.user_id = %1) "
                               " AND (plan_gym.gym_id = gym.gym_id) "
                               " AND (plan_gym.time < date('%2')) "
                               " AND (plan_gym.time > date('%3')) "
                               " ORDER BY plan_gym.time, gym.name DESC  ").arg(m_currentUser).arg(endDate).arg(startDate);

    bool result = query.exec(queryStr);
    QString lastError = query.lastError().text();

    if (!result)
    {

    }
    else
    {
        QSqlRecord rec = query.record();

        int col_name = rec.indexOf("name");
        int col_time = rec.indexOf("time");
        int col_weight = rec.indexOf("weight");
        int col_reps = rec.indexOf("reps");
        int col_sets = rec.indexOf("sets");

        QString m_currentDay = "";

        while (query.next())
        {
            QString name = query.value(col_name).toString();
            QString date = query.value(col_time).toString();
            int weight = query.value(col_weight).toInt();
            int reps = query.value(col_reps).toInt();
            int sets = query.value(col_sets).toInt();
            // Если этот тренировочный день еще не существует
            if (m_currentDay != date)
            {
                ViewDayWidget *viewDay = new ViewDayWidget();
                m_viewWidgets.append(viewDay);
                viewDay->setVisible(true);
                m_currentDay = date;
                viewDay->AppendData(name, date, weight, reps, sets);
                if (m_currentColumn == 2)
                {
                    ++m_currentRow;
                    m_currentColumn = 0;
                }
                ui->gridLayout_2->addWidget(viewDay, m_currentRow, m_currentColumn, 1, 1);
                ++m_currentColumn;
            }
            else
            {
                m_viewWidgets[m_viewWidgets.size() - 1]->AppendData(name, date, weight, reps, sets);
            }
        }
    }
}

void ViewMethodicWidget::closeEvent(QCloseEvent *event)
{
    while (m_viewWidgets.size() > 0)
    {
        delete m_viewWidgets[0];
        m_viewWidgets.remove(0);
    }
    m_currentColumn = 0;
    m_currentRow = 0;
    m_currentUser = -1;
}

void ViewMethodicWidget::SetUserId(int uId)
{
    m_currentUser = uId;
}
