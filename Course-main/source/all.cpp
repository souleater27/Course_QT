#include "all.h"
#include "ui_all.h"
#include "user.h"

ALL::ALL(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ALL)
{
    ui->setupUi(this);
    Login conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.new_db);
    qry->prepare("select пациент, доктор, дата, время from Talons");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
}

ALL::~ALL()
{
    delete ui;
}

void ALL::on_pushButton_clicked()
{
    User *user = new User();
    user->show();
    this->hide();
}
