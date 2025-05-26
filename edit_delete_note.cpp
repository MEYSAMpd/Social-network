#include "edit_delete_note.h"
#include "ui_edit_delete_note.h"
#include <main_user_page.h>
#include "user.h"


edit_delete_note::edit_delete_note(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::edit_delete_note)
{
    ui->setupUi(this);
    ui->leName->setText(NOTE);
}

edit_delete_note::~edit_delete_note()
{
    delete ui;
}

void edit_delete_note::on_pushButton_2_clicked()
{
    main_user_page *main_page = new main_user_page;
    main_page->show();
    hide();
}

void edit_delete_note::on_pbEdit_clicked()
{
    vector<QString> temp = USER.getSubmussions();
    for(int i = 0 ; i < int(temp.size()) ; i++){
        if(NOTE == temp[i]){
            temp[i] = ui->leName->text();
            break;
        }
    }
    USER.setSubmissions(temp);
    for(auto itr = M_Database.begin() ; itr != M_Database.end() ; itr++){
        if(itr->first == USER.getUsername()){
            M_Database.erase(itr);
        }
    }
    M_Database.insert(pair<QString , User>(USER.getUsername() , USER));
    main_user_page *main_page = new main_user_page;
    main_page->show();
    hide();
}

void edit_delete_note::on_pbDelete_clicked()
{
    vector<QString> temp = USER.getSubmussions();
    for(int i = 0 ; i < int(temp.size()) ; i++){
        if(NOTE == temp[i]){
            temp.erase(temp.begin() + i);
            break;
        }
    }
    USER.setSubmissions(temp);
    for(auto itr = M_Database.begin() ; itr != M_Database.end() ; itr++){
        if(itr->first == USER.getUsername()){
            M_Database.erase(itr);
        }
    }
    M_Database.insert(pair<QString , User>(USER.getUsername() , USER));
    main_user_page *main_page = new main_user_page;
    main_page->show();
    hide();
}
