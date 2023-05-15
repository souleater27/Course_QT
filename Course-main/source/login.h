#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QWidget>
#include "user.h"
#include "doctors.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE
/*!
    \brief Класс окна авторизации

    В данном классе пользователь может войти в свой аккаунт или создать новый, если аккаунта не существует
    */
class Login : public QMainWindow
{
    Q_OBJECT
public:
    QString username;
    QSqlDatabase new_db;
    /*!
Закрывает доступ к базе данных
*/
    void connClose(){
        new_db.close();
        new_db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    /*!
Открывает доступ к базе данных
*/
    bool connOpen(){
        new_db = QSqlDatabase::addDatabase("QSQLITE");
        new_db.setDatabaseName("./database/mydb.db");

        if(!new_db.open()){
            qDebug()<<("В открытии базы данных произошла ошибка");
            return false;
        }
        else {
            qDebug()<<("Соединение установлено");
            return true;
        }
    }
public:
    /**
 * @brief Конструктор
 * @param parent Указатель на экземпляр родительского класса
 */
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
///При успешной авторизации переход в меню пользователя
    void on_pushButton_clicked();
///Переход в окно регистрации
    void on_pushButton_2_clicked();

private:
    Ui::Login *ui;
};
#endif // LOGIN_H
