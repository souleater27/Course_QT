#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include "login.h"

namespace Ui {
    /*!
\brief Класс окна регистрации нового пользователя

В данном классе пользователь зарегистрироваться для использования приложения
*/
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    /**
 * @brief Конструктор
 * @param parent Указатель на экземпляр родительского класса
 */
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

private slots:
    ///Кнопка для сохранения регистрации
    void on_pushButton_clicked();
    /// Кнопка для выхода из окна регистрации в окно авторизации
    void on_pushButton_2_clicked();

private:
    Ui::Registration *ui;
    Login *log;
};

#endif // REGISTRATION_H
