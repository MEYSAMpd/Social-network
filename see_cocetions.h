#ifndef SEE_COCETIONS_H
#define SEE_COCETIONS_H

#include <QMainWindow>

namespace Ui {
class see_cocetions;
}

class see_cocetions : public QMainWindow
{
    Q_OBJECT

public:
    explicit see_cocetions(QWidget *parent = 0);
    ~see_cocetions();

    void on_button_clicked();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::see_cocetions *ui;
};

#endif // SEE_COCETIONS_H
