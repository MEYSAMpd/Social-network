#ifndef OTHER_USER_PAGE_H
#define OTHER_USER_PAGE_H

#include <QMainWindow>

namespace Ui {
class other_user_page;
}

class other_user_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit other_user_page(QWidget *parent = 0);
    ~other_user_page();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pbConections_clicked();

private:
    Ui::other_user_page *ui;
};

#endif // OTHER_USER_PAGE_H
