#ifndef EDIT_PROFILE_H
#define EDIT_PROFILE_H

#include <QMainWindow>
#include "user.h"

namespace Ui {
class edit_profile;
}

class edit_profile : public QMainWindow
{
    Q_OBJECT

public:
    explicit edit_profile(QWidget *parent = 0);
    ~edit_profile();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::edit_profile *ui;
};

#endif // EDIT_PROFILE_H
