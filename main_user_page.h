#ifndef MAIN_USER_PAGE_H
#define MAIN_USER_PAGE_H

#include <QMainWindow>

namespace Ui {
class main_user_page;
}

class main_user_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit main_user_page(QWidget *parent = 0);
    ~main_user_page();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pbConections_clicked();

    void on_button_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::main_user_page *ui;
};

#endif // MAIN_USER_PAGE_H
