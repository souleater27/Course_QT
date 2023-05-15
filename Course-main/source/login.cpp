#include "login.h"
#include "ui_login.h"
#include "registration.h"
#include <user.h>
#include <QtSql>
#include <QDebug>
#include <QWidget>

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_clicked()
{
    QString password;
    username=ui->lineEdit->text();
    password=ui->lineEdit_2->text();

    if(!connOpen()){
        qDebug()<< "Не удалось загрузить базу данных";
        return;
    }

    connOpen();
    QSqlQuery qry(new_db);
    qry.prepare("select * from Users where user_id='"+username +"' and password='"+password +"'");
    if(qry.exec()){
        int count = 0;
        while(qry.next()){
            count++;
        }
        if(count==1){
            connClose();
            User *use = new User();
            use->show();
            this->hide();
        }
        if(count<1){
                QMessageBox::warning(this, "Ошибка!", "Неправильные логин или пароль!");
        }
    }
    connClose();
}

void Login::on_pushButton_2_clicked()
{
    Registration *reg = new Registration();
    reg->show();
    this->hide();
}
