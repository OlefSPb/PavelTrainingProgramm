#include "databasemanager.h"
#include "trainday.h"

#include <QtSql>
#include <QSqlQuery>
#include <QSqlError>

#include <QDebug>

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent)
{
    m_sportsmenId = -1;
}

bool DatabaseManager::Connect(const QString& name)
{
    m_base = QSqlDatabase::addDatabase("QSQLITE");
    m_base.setHostName("127.0.0.1");
    m_base.setDatabaseName("hobbits.sqlite");
    m_base.setUserName("");
    m_base.setPassword("");
    bool flag = m_base.open();
    if (!flag)
    {
        qDebug() << "error: database not loaded : " << m_base.lastError().text();
    }

    return flag;
}

QList<Sportsmen>& DatabaseManager::GetSportsmens()
{
    m_sportsMens.clear();
    QSqlQuery query("SELECT * from user");
    if (!query.exec())
    {
        qDebug() << "error: GetSportsmens: " << m_base.lastError().text();
    }

    QSqlRecord rec = query.record();

    int col_userid = rec.indexOf("user_id");
    int col_name = rec.indexOf("name");
    int col_surname = rec.indexOf("surname");

    while (query.next())
    {
        Sportsmen sportsmen;
        sportsmen.user_id = query.value(col_userid).toInt();
        sportsmen.name = query.value(col_name).toString();
        sportsmen.surname = query.value(col_surname).toString();
        m_sportsMens.append(sportsmen);
    }
    return m_sportsMens;
}

void DatabaseManager::DumpToBase(const QList<TDay>& days)
{
    for (int idx = 0, idxSize = days.size(); idx < idxSize; ++idx)
    {
        QDate day = days[idx].date; // Дата
        QList<Exercise> exercises = days[idx].data;
        for (int idy = 0, idySize = exercises.size(); idy < idySize; ++idy)
        {
            int type = exercises[idy].gymType;
            QList<WRS> wrsList = exercises[idy].wrsList;
            for (int idz = 0, idzSize = wrsList.size(); idz < idzSize; ++idz)
            {
                WRS wrs;
                wrs = wrsList[idz];
                QSqlQuery query;
                query.prepare("INSERT INTO plan_gym(user_id, gym_id, time, weight, reps, sets)"
                              "VALUES(:user_id, :gym_id, :time, :weight, :reps, :sets);");
                query.bindValue(":user_id", m_sportsmenId); // Исправить
                query.bindValue(":gym_id", exercises[idy].gymType); // Исправить
                query.bindValue(":time", day.toString("yyyy-MM-dd"));
                query.bindValue(":weight", wrs.weight);
                query.bindValue(":reps", wrs.count);
                query.bindValue(":sets", wrs.sets);
                query.exec();
            }
        }
    }
}

void DatabaseManager::SetSportsmenId(int id)
{
    m_sportsmenId = id;
}

