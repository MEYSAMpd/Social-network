#include "add_note.h"
#include "ui_add_note.h"
#include <socialnetwork.h>
#include <main_user_page.h>
#include <vector>
#include <QString>
#include <main_user_page.h>

add_note::add_note(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::add_note)
{
    ui->setupUi(this);
}

add_note::~add_note()
{
    delete ui;
}

void add_note::on_pushButton_3_clicked()
{
    vector<QString> notes = USER.getSubmussions();
    notes.push_back(ui->leName->text());
    USER.setSubmissions(notes);
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

void add_note::on_pushButton_2_clicked()
{
    main_user_page *mainpage = new main_user_page;
    mainpage->show();
    hide();
}
