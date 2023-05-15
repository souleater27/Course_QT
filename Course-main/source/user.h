#ifndef USER_H
#define USER_H

#include <QDialog>
#include <doctors.h>
#include "login.h"

namespace Ui {
class User;
}

/*!
\brief Класс меню пользователя

В данном классе пользователь может переключаться между другими разделами приложения
*/
class User : public QDialog
{
    Q_OBJECT

public:
    /**
* @brief Конструктор
* @param parent Указатель на экземпляр родительского класса
*/
    explicit User(QWidget *parent = nullptr);
    ~User();

private slots:
    ///Кнопка для перехода в раздел со списком психологов
    void on_pushButton_clicked();
    ///Кнопка для перехода в раздел с возможность записаться на приём
    void on_pushButton_4_clicked();
    ///Кнопка для перехода в раздел с полным списком записей
    void on_pushButton_2_clicked();
    ///Кнопка для выхода из аккаунта
    void on_pushButton_3_clicked();

private:
    Ui::User *ui;
    Doctors *doctor;
};

#endif // USER_H
