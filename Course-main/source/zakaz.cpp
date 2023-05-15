#include "zakaz.h"
#include "ui_zakaz.h"
#include "login.h"
#include <QString>

Zakaz::Zakaz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Zakaz)
{
    ui->setupUi(this);
    Login conn;
    conn.connOpen();
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("select ФИО from Doctors");
    ui->comboBox->setModel(model);
    conn.connClose();
}

Zakaz::~Zakaz()
{
    delete ui;
}



void Zakaz::on_pushButton_2_clicked()
{
    User *user = new User();
    user->show();
    this->hide();
}

void Zakaz::on_pushButton_clicked()
{
    Login conn;
    conn.connOpen();
    QString patient="", name="", data="", time="";
    patient=ui->lineEdit->text();
    name=ui->comboBox->currentText();
    data=ui->dateEdit->text();
    time=ui->timeEdit->text();
    if(!conn.connOpen()){
        qDebug()<< "Не удалось загрузить базу данных";
        return;
    }

    QSqlQuery qry(QSqlDatabase::database("mydb.db"));
    qry.prepare("insert into Talons (доктор, пациент,дата, время) values (?,?,?, ?)");
    qry.addBindValue(name);
    qry.addBindValue(patient);
    qry.addBindValue(data);
    qry.addBindValue(time);
    if(qry.exec()){
                QMessageBox::information(this, "Сохранение", "Данные успешно сохранены!");
                User *user = new User();
                user->show();
                this->hide();
        }
    conn.connClose();
}

