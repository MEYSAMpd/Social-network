#ifndef SUGGESTIONS_H
#define SUGGESTIONS_H

#include <QMainWindow>

namespace Ui {
class suggestions;
}

class suggestions : public QMainWindow
{
    Q_OBJECT

public:
    explicit suggestions(QWidget *parent = 0);
    ~suggestions();

    void on_button_clicked();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::suggestions *ui;
};

#endif // SUGGESTIONS_H
