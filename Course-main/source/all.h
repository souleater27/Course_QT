#ifndef ALL_H
#define ALL_H

#include <QDialog>

namespace Ui {
    /*!
    ///\brief окно со списком талонов
    Данный класс отображает все талоны пациента, которые он когда-либо заказывал.
    */
class ALL;
}

class ALL : public QDialog
{
    Q_OBJECT

public:
    /**
    * @brief Конструктор
    * @param parent Указатель на экземпляр родительского класса
    */
    explicit ALL(QWidget *parent = nullptr);
    ~ALL();

private slots:
    ///Выход из окна со списком записей
    void on_pushButton_clicked();

private:
    Ui::ALL *ui;
};

#endif // ALL_H
