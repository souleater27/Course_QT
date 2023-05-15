#include "registration.h"
#include "ui_registration.h"
#include <QMessageBox>

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_pushButton_clicked()
{
    Login conn;
    conn.connOpen();
    QString name="", surname="", middle_name="", login="", location="", age="", password="";


    login=ui->lineEdit_4->text();
    password=ui->lineEdit_5->text();
    name=ui->lineEdit->text();
    surname=ui->lineEdit_2->text();
    middle_name=ui->lineEdit_3->text();
    location=ui->lineEdit_6->text();
    age=ui->lineEdit_7->text();

    if(!conn.connOpen()){
        qDebug()<< "Не удалось загрузить базу данных";
        return;
    }
    QSqlQuery qry1;
    qry1.prepare("select user_id from Users");
    if(qry1.exec()){
        while(qry1.next()){
            QString cur = qry1.value(0).toString();
            if(cur == login){
                QMessageBox::warning(this, "Ошибка!", "Такой логин уже существует!");
                ui->lineEdit_4->clear();
                return;
                break;
            }
        }
    }

    QSqlQuery qry(QSqlDatabase::database("mydb.db"));
    qry.prepare("insert into Users (user_id, password, name, surname, middle_name, location, age) values (?,?,?,?,?,?,?)");
    qry.addBindValue(login);
    qry.addBindValue(password);
    qry.addBindValue(name);
    qry.addBindValue(surname);
    qry.addBindValue(middle_name);
    qry.addBindValue(location);
    qry.addBindValue(age);
    if(qry.exec()){
                QMessageBox::information(this, "Регистрация", "Вы успешно зарегистрированы!");
                Login *log = new Login();
                log->show();
                this->hide();
        }
    conn.connClose();

}

void Registration::on_pushButton_2_clicked()
{
    Login *log = new Login();
    log->show();
    this->hide();
}
