#include "edit_profile.h"
#include "ui_edit_profile.h"
#include <main_user_page.h>
#include <QMessageBox>

edit_profile::edit_profile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::edit_profile)
{
    ui->setupUi(this);
    ui->leName->setText(USER.getName());
    ui->leUsername->setText(USER.getUsername());
    ui->leBio->setText(USER.getBio());
}

edit_profile::~edit_profile()
{
    delete ui;
}

void edit_profile::on_pushButton_4_clicked()
{
    main_user_page *main_page = new main_user_page;
    main_page->show();
    hide();
}

void edit_profile::on_pushButton_3_clicked()
{
    if(ui->leName->text().isEmpty()){
        QMessageBox::information(this , "ERROR" , "Name cannot be empty!");
    }
    else if(ui->leUsername->text().isEmpty()){
        QMessageBox::information(this , "ERROR" , "Username cannot be empty!");
    }
    else if(ui->leUsername->text() != USER.getUsername() && !USER.checkUsername(ui->leUsername->text())){
        QMessageBox::information(this , "ERROR" , "Username is duplicate!");
    }
    else if(!ui->lePresentPass->text().isEmpty() && ui->lePresentPass->text() != USER.getPassword()){
        QMessageBox::information(this , "ERROR" , "Password is wrong!");
    }
    else{
        USER.setName(ui->leName->text());
        QString preUsername = USER.getUsername();
        USER.setUsername(ui->leUsername->text());
        USER.setBio(ui->leBio->text());
        if(!ui->lePresentPass->text().isEmpty() && !ui->leNewPass->text().isEmpty()){
            USER.setPassword(ui->leNewPass->text());
        }
        for(auto itr = M_Database.begin() ; itr != M_Database.end() ; itr++){
            if(itr->first == preUsername){
                M_Database.erase(itr);
            }
        }
        M_Database.insert(pair<QString , User>(USER.getUsername() , USER));
        QMessageBox::information(this , "success" , "Done");
        main_user_page *main_page = new main_user_page;
        main_page->show();
        hide();
    }
}
