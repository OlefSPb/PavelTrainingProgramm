#include "selectdatewidget.h"
#include "ui_selectdatewidget.h"
#include <QDate>

SelectDateWidget::SelectDateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectDateWidget)
{
    ui->setupUi(this);

    bool connection;
    connection = connect(ui->m_ok, SIGNAL(clicked()), SLOT(OnOkClicked())); Q_ASSERT(connection);
}

SelectDateWidget::~SelectDateWidget()
{
    delete ui;
}

void SelectDateWidget::OnOkClicked()
{
    QString startDate = QDate::fromString(ui->m_dateStart->text(), "dd.MM.yyyy").toString("yyyy-MM-dd");
    QString endDate = QDate::fromString( ui->m_dateEnd->text(), "dd.MM.yyyy").toString("yyyy-MM-dd");
    emit DatesChanged(startDate, endDate);
    close();
}
