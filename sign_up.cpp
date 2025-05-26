#include "sign_up.h"
#include "ui_sign_up.h"
#include <main_user_page.h>
#include "user.h"

sign_up::sign_up(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sign_up)
{
    ui->setupUi(this);
    ui->leEmail->setPlaceholderText("*****@gmail.com");
}

sign_up::~sign_up()
{
    delete ui;
}

void sign_up::on_pushButton_2_clicked()
{
    socialNetwork *login = new socialNetwork;
    login->show();
    hide();
}

void sign_up::on_pushButton_clicked()
{
    bool flag = true;
    if(ui->leEmail->text().size() < 15){
        flag = false;
    }
    else{
        string email = ui->leEmail->text().toStdString();
        email = email.substr(email.size() - 10 , 10);
        if(email != "@gmail.com"){
            flag = false;
        }
    }
    if(ui->leName->text().isEmpty() || ui->leUsername->text().isEmpty() || ui->lePassword->text().isEmpty() || ui->leEmail->text().isEmpty()){
        QMessageBox::information(this , "ERROR" , "All items must be filled!");
    }
    else if(!USER.checkUsername(ui->leUsername->text())){
        QMessageBox::information(this , "ERROR" , "Username is duplicate!");
    }
    else{
        if(flag){
            vector<QString> submissions , connections;
            User newUser;
            newUser.setUser(ui->leUsername->text() , ui->lePassword->text() , ui->leName->text() , "" , submissions , 0 , connections);
            M_Database.insert(pair<QString , User>(ui->leUsername->text() , newUser));
            USER = newUser;
            viewingUser = USER;
            QMessageBox::information(this , "success" , "New user added.");
            main_user_page *main_page = new main_user_page;
            main_page->show();
            hide();
        }
        else{
            QMessageBox::information(this , "ERROR" , "Wrong Email address!");
        }
    }
}
