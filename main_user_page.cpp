#include "main_user_page.h"
#include "ui_main_user_page.h"
#include "socialnetwork.h"
#include <edit_profile.h>
#include <QDebug>
#include <vector>
#include <QString>
#include <QPushButton>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QObject>
#include <edit_delete_note.h>
#include <add_note.h>
#include <suggestions.h>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <see_cocetions.h>
#include "user.h"

QString NOTE;
main_user_page::main_user_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::main_user_page)
{
    ui->setupUi(this);
    ui->lUsername->setText(USER.getUsername());
    ui->lBio->setText(USER.getBio());
    ui->pbConections->setText(QString::number(USER.getNumconnections()));
    for (auto note : USER.getSubmussions())
    {
        QPushButton *button = new QPushButton(note);
        button->setFixedHeight(80);
        button->setStyleSheet("background-color: rgb(202, 202, 202); color: rgb(255, 255, 255); border: none; border-radius: 20px;");
        button->setCursor(Qt::PointingHandCursor);
        ui->verticalLayout->addWidget(button);
        QObject::connect(button , &QPushButton::clicked, this, &main_user_page::on_button_clicked);
    }
    QWidget *buttonContainer = new QWidget(this);
    buttonContainer->setLayout(ui->verticalLayout);
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(buttonContainer);
    scrollArea->setWidgetResizable(true);
    QHBoxLayout *mainLayout = new QHBoxLayout(ui->widget);
    mainLayout->addWidget(scrollArea);

    //======================profile overload========================
    if (USER.getProfile_path()!="")
    {
        QString filePath = USER.getProfile_path() ;
        QString css = QString("border-image: url(%1); border-radius: 90px").arg(filePath);
        ui->label->setStyleSheet(css);
    }
}

main_user_page::~main_user_page()
{
    delete ui;
}

void main_user_page::on_button_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(QObject::sender());
    NOTE = button->text();
    edit_delete_note *editnote = new edit_delete_note;
    editnote->show();
    hide();
}

void main_user_page::on_pushButton_3_clicked()
{
    edit_profile * editprof = new edit_profile;
    editprof->show();
    hide();
}

void main_user_page::on_pushButton_4_clicked()
{
    socialNetwork * login = new socialNetwork;
    login->show();
    hide();
}

void main_user_page::on_pushButton_2_clicked()
{
    add_note *addnote = new add_note;
    addnote->show();
    hide();
}

void main_user_page::on_pushButton_5_clicked()
{
    suggestions *suggest = new suggestions;
    suggest->show();
    hide();
}

void main_user_page::on_pbConections_clicked()
{
    see_cocetions * conections = new see_cocetions;
    conections->show();
    hide();
}

QString copyImageFileToLocalFolder() {
    QString sourceFilePath = QFileDialog::getOpenFileName(nullptr, "Choose a picture", "", "Images (*.png *.xpm *.jpg)");

    if (!sourceFilePath.isEmpty()) {
        QString targetDirectory = "profile_img/";
        QString fileName = QFileInfo(sourceFilePath).fileName();
        QString targetFilePath = targetDirectory + fileName;

        QDir dir;
        if (!dir.exists(targetDirectory)) {
            dir.mkpath(targetDirectory);
        }

        if (QFile::copy(sourceFilePath, targetFilePath)) {
            QMessageBox::information(nullptr, "Info", "Inserting img done successfully");
            return targetFilePath; // بازگرداندن مسیر کامل فایل
        } else {
            QMessageBox::information(nullptr, "Error", "Failed to copy file");
        }
    }
    return QString();
}


void main_user_page::on_pushButton_clicked()
{
    QString filePath = copyImageFileToLocalFolder();
    if (!filePath.isEmpty()) {
        QString css = QString("border-image: url(%1); border-radius: 90px").arg(filePath);
        ui->label->setStyleSheet(css);
        USER.setProfile_path(filePath);
    }
    QMessageBox::information(nullptr, "info", "Photo is added");
}



void main_user_page::on_pushButton_6_clicked()
{
    for(auto itr = M_Database.begin() ; itr != M_Database.end() ; itr++){
        if(itr->first == USER.getUsername()){
            M_Database.erase(itr);
            break;
        }
    }
    for(auto itr = M_Database.begin() ; itr != M_Database.end() ; itr++){
        vector<QString> following = itr->second.getConnections();
        for(int i = 0 ; i < int(following.size()) ; i ++){
            if(following[i] == USER.getUsername()){
                following.erase(following.begin() + i);
                itr->second.setConnections(following);
                itr->second.setNumconnections(following.size());
                break;
            }
        }
    }
    socialNetwork * login = new socialNetwork;
    login->show();
    hide();
}
