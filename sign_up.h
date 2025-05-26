#ifndef SIGN_UP_H
#define SIGN_UP_H

#include <QMainWindow>
#include <socialnetwork.h>
#include "user.h"

namespace Ui {
class sign_up;
}

class sign_up : public QMainWindow
{
    Q_OBJECT

public:
    explicit sign_up(QWidget *parent = 0);
    ~sign_up();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::sign_up *ui;
};

#endif // SIGN_UP_H
