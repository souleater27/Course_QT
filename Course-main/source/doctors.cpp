#include "doctors.h"
#include "ui_doctors.h"
#include <user.h>
#include <QSqlQuery>
#include <QTableWidget>
#include "login.h"
Doctors::Doctors(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Doctors)
{
    ui->setupUi(this);
    Login conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.new_db);
    qry->prepare("select ФИО, телефон, профиль, кабинет from Doctors");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
}

Doctors::~Doctors()
{
    delete ui;
}


void Doctors::on_pushButton_2_clicked()
{
    User *user = new User();
    user->show();
    this->hide();
}
