#ifndef ADD_NOTE_H
#define ADD_NOTE_H

#include <QMainWindow>

namespace Ui {
class add_note;
}

class add_note : public QMainWindow
{
    Q_OBJECT

public:
    explicit add_note(QWidget *parent = 0);
    ~add_note();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::add_note *ui;
};

#endif // ADD_NOTE_H
