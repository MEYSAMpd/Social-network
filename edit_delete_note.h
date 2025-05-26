#ifndef EDIT_DELETE_NOTE_H
#define EDIT_DELETE_NOTE_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class edit_delete_note;
}

class edit_delete_note : public QMainWindow
{
    Q_OBJECT

public:
    explicit edit_delete_note(QWidget *parent = 0);
    ~edit_delete_note();


private slots:
    void on_pushButton_2_clicked();

    void on_pbEdit_clicked();

    void on_pbDelete_clicked();

private:
    Ui::edit_delete_note *ui;
};

#endif // EDIT_DELETE_NOTE_H
