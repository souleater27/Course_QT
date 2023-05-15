#include "user.h"
#include "ui_user.h"
#include "login.h"
#include "zakaz.h"
#include "all.h"

User::User(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
}

User::~User()
{
    delete ui;
}

void User::on_pushButton_clicked()
{
    doctor = new Doctors();
    doctor->show();
    this->hide();
}

void User::on_pushButton_4_clicked()
{
    Login *log = new Login();
    log->show();
    this->hide();
}

void User::on_pushButton_2_clicked()
{
    Zakaz *zak = new Zakaz();
    zak->show();
    this->hide();
}

void User::on_pushButton_3_clicked()
{
    ALL *al=new ALL();
    al->show();
    this->hide();
}
