#ifndef DOCTORS_H
#define DOCTORS_H

#include <QDialog>
#include <QWidget>

namespace Ui {
    /*!
    \brief Класс окна, отображающего список всех специалистов

    В данном классе пользователь может изучить данные всех специалистов
    */
class Doctors;
}

class Doctors : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор
     * @param parent Указатель на экземпляр родительского класса
     */
    explicit Doctors(QWidget *parent = nullptr);
    ~Doctors();

private slots:
    /// Выход из окна со списком врачей в меню
    void on_pushButton_2_clicked();

private:
    Ui::Doctors *ui;
};

#endif // DOCTORS_H
