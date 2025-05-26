#include "other_user_page.h"
#include "ui_other_user_page.h"
#include <socialnetwork.h>
#include "user.h"
#include <vector>
#include <QString>
#include <QPushButton>
#include <QHBoxLayout>
#include <QScrollArea>
#include <main_user_page.h>
#include "see_cocetions.h"

User viewingUser;
other_user_page::other_user_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::other_user_page)
{
    ui->setupUi(this);

    ui->lUsername->setText(viewingUser.getUsername());
    ui->lBio->setText(viewingUser.getBio());
    ui->pbConections->setText(QString::number(viewingUser.getNumconnections()));

    bool isFollowing = false;
    for (auto x : USER.getConnections())
    {
        if (x == ui->lUsername->text())
            isFollowing = true;
    }
    if (isFollowing)
    {
        ui->label_2->hide();
        ui->pushButton_3->setText("Following");
        ui->pushButton_3->setStyleSheet("background-color: rgb(202, 202, 202); border: none; border-radius: 20px; color: rgb(255, 255, 255); font: 75 12pt ""MS Shell Dlg 2"";");
        for (auto note : viewingUser.getSubmussions())
        {
            QLabel *label = new QLabel(note);
            label->setFixedHeight(80);
            label->setStyleSheet("background-color: rgb(33, 150, 243); color: rgb(255, 255, 255); border: none; border-radius: 20px;");
            label->setAlignment(Qt::AlignCenter);
            ui->verticalLayout->addWidget(label);
        }
        QWidget *buttonContainer = new QWidget(this);
        buttonContainer->setLayout(ui->verticalLayout);
        QScrollArea *scrollArea = new QScrollArea(this);
        scrollArea->setWidget(buttonContainer);
        scrollArea->setWidgetResizable(true);
        QHBoxLayout *mainLayout = new QHBoxLayout(ui->widget);
        mainLayout->addWidget(scrollArea);
    }
    //======================profile overload========================
    if (viewingUser.getProfile_path()!="")
    {
        QString filePath = viewingUser.getProfile_path() ;
        QString css = QString("border-image: url(%1); border-radius: 80px").arg(filePath);
        ui->label->setStyleSheet(css);
    }
}

other_user_page::~other_user_page()
{
    delete ui;
}

void other_user_page::on_pushButton_3_clicked()
{
    if (ui->pushButton_3->text() == "Follow")
    {
        vector<QString> followers = USER.getConnections();
        followers.push_back(viewingUser.getUsername());
        USER.setConnections(followers);
        USER.setNumconnections(followers.size());
        for(auto itr = M_Database.begin() ; itr != M_Database.end() ; itr++){
            if(itr->first == USER.getUsername()){
                M_Database.erase(itr);
            }
        }
        M_Database.insert(pair<QString , User>(USER.getUsername() , USER));
        ui->label_2->hide();
        ui->pushButton_3->setText("Following");
        ui->pushButton_3->setStyleSheet("background-color: rgb(202, 202, 202); border: none; border-radius: 20px; color: rgb(255, 255, 255); font: 75 12pt ""MS Shell Dlg 2"";");
        for (auto note : viewingUser.getSubmussions())
        {
            QLabel *label = new QLabel(note);
            label->setFixedHeight(80);
            label->setStyleSheet("background-color: rgb(33, 150, 243); color: rgb(255, 255, 255); border: none; border-radius: 20px;");
            label->setAlignment(Qt::AlignCenter);
            ui->verticalLayout->addWidget(label);
        }
        QWidget *buttonContainer = new QWidget(this);
        buttonContainer->setLayout(ui->verticalLayout);
        QScrollArea *scrollArea = new QScrollArea(this);
        scrollArea->setWidget(buttonContainer);
        scrollArea->setWidgetResizable(true);
        QHBoxLayout *mainLayout = new QHBoxLayout(ui->widget);
        mainLayout->addWidget(scrollArea);

        followers = viewingUser.getConnections();
        followers.push_back(USER.getUsername());
        viewingUser.setConnections(followers);
        viewingUser.setNumconnections(followers.size());
        for(auto itr = M_Database.begin() ; itr != M_Database.end() ; itr++){
            if(itr->first == viewingUser.getUsername()){
                M_Database.erase(itr);
            }
        }
        M_Database.insert(pair<QString , User>(viewingUser.getUsername() , viewingUser));
        ui->pbConections->setText(QString::number(viewingUser.getNumconnections()));
    }
    else {
       ui->label_2->show();
       ui->pushButton_3->setStyleSheet("background-color: rgb(33, 150, 243); border: none; border-radius: 20px; color: rgb(255, 255, 255); font: 75 12pt ""MS Shell Dlg 2"";");
       ui->pushButton_3->setText("Follow");
       USER.unFollow();
    }
    other_user_page *anotherone_page = new other_user_page;
    anotherone_page->show();
    hide();
}

void other_user_page::on_pushButton_2_clicked()
{
    seenUsers.pop();
    if(seenUsers.size() == 0){
        viewingUser = USER;
        main_user_page *main_page = new main_user_page;
        main_page->show();
        hide();
    }
    else{
        viewingUser = seenUsers.top();
        other_user_page *anotherone_page = new other_user_page;
        anotherone_page->show();
        hide();
    }
}

void other_user_page::on_pbConections_clicked()
{
    see_cocetions *conections = new see_cocetions;
    conections->show();
    hide();
}
