#ifndef ZAKAZ_H
#define ZAKAZ_H

#include <QDialog>

namespace Ui {
class Zakaz;
}
/*!
\brief Класс записи на приём

В данном классе пользователь может записаться на приём
*/
class Zakaz : public QDialog
{
    Q_OBJECT

public:
    /**
* @brief Конструктор
* @param parent Указатель на экземпляр родительского класса
*/
    explicit Zakaz(QWidget *parent = nullptr);
    ~Zakaz();

private slots:
    ///Кнопка для выхода из раздела записи в меню
    void on_pushButton_2_clicked();
    ///Кнопка для сохранения записи
    void on_pushButton_clicked();

private:
    Ui::Zakaz *ui;
};

#endif // ZAKAZ_H
