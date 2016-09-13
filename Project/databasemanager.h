#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include "trainday.h"

#include <QString>

struct Sportsmen
{
    int user_id;
    QString name;
    QString surname;
};

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = 0);

    bool Connect(const QString& name);

    QList<Sportsmen>& GetSportsmens();

    void DumpToBase(const QList<TDay>& days);

    void SetSportsmenId(int id);



signals:

public slots:

 private:
    QSqlDatabase m_base;

    QList<Sportsmen> m_sportsMens;

    int m_sportsmenId;
};

#endif // DATABASEMANAGER_H
