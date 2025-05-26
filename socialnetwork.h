#ifndef SOCIALNETWORK_H
#define SOCIALNETWORK_H

#include <QMainWindow>
#include <sign_up.h>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <user.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QDir>
#include <QDebug>
#include "user.h"

namespace Ui {
class socialNetwork;
}

class socialNetwork : public QMainWindow
{
    Q_OBJECT

public:
    explicit socialNetwork(QWidget *parent = 0);
    ~socialNetwork();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::socialNetwork *ui;
};

#endif // SOCIALNETWORK_H
