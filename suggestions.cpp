#include "suggestions.h"
#include "ui_suggestions.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QLabel>
#include <QObject>
#include <other_user_page.h>
#include <main_user_page.h>
#include "user.h"

stack<User> seenUsers;
suggestions::suggestions(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::suggestions)
{
    ui->setupUi(this);
    map<float , QString> suggest = USER.suggestion();
    int count = 0;
    if(suggest.size() == 0){
        ui->lSuggest->setText("Newly joined");
        for (auto itr = M_Database.rbegin() ; itr != M_Database.rend() ; itr++)
        {
            int i;
            for(i = 0 ; i < USER.getNumconnections() ; i++){
                if(itr->first == USER.getConnections()[i]){
                    break;
                }
            }
            if(i == USER.getNumconnections() && itr->first != USER.getUsername()){
                QHBoxLayout *newlayout = new QHBoxLayout();
                QLabel *label = new QLabel("");
                label->setFixedSize(111, 111);
                label->setStyleSheet("border: none; border-radius: 50px; border-image: url(:/img/user-01_generated.jpg);");
                QPushButton *button = new QPushButton("name");
                button->setFixedHeight(90);
                button->setStyleSheet("background-color: rgb(33, 150, 243); color: rgb(255, 255, 255); border: none; border-radius: 40px;");
                button->setText(itr->first);
                button->setCursor(Qt::PointingHandCursor);
                newlayout->addWidget(button);
                newlayout->addWidget(label);
                ui->verticalLayout->insertLayout(0, newlayout);
                QObject::connect(button , &QPushButton::clicked, this, &suggestions::on_button_clicked);
                count ++;
            }
            if(count == 6){
                break;
            }
        }
    }
    else{
        ui->lSuggest->setText("Maybe you know");
        for (auto itr = suggest.begin() ; itr != suggest.end() ; itr++){
            QHBoxLayout *newlayout = new QHBoxLayout();
            QLabel *label = new QLabel("");
            label->setFixedSize(111, 111);
            label->setStyleSheet("border: none; border-radius: 50px; border-image: url(:/img/user-01_generated.jpg);");
            QPushButton *button = new QPushButton("name");
            button->setFixedHeight(90);
            button->setStyleSheet("background-color: rgb(33, 150, 243); color: rgb(255, 255, 255); border: none; border-radius: 40px;");
            button->setText(itr->second);
            button->setCursor(Qt::PointingHandCursor);
            newlayout->addWidget(button);
            newlayout->addWidget(label);
            ui->verticalLayout->insertLayout(0, newlayout);
            QObject::connect(button , &QPushButton::clicked, this, &suggestions::on_button_clicked);
            count ++;
            if(count == 6){
                break;
            }
        }
    }
    QWidget *buttonContainer = new QWidget(this);
    buttonContainer->setLayout(ui->verticalLayout);
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(buttonContainer);
    scrollArea->setWidgetResizable(true);
    QHBoxLayout *mainLayout = new QHBoxLayout(ui->widget);
    mainLayout->addWidget(scrollArea);

}

void suggestions::on_button_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(QObject::sender());
    QString name = button->text();
    for (auto itr = M_Database.begin() ; itr != M_Database.end() ; itr++){
        if(itr->first == name){
            viewingUser = itr->second;
            seenUsers.push(viewingUser);
        }
    }
    other_user_page *anotherone_page = new other_user_page;
    anotherone_page->show();
    hide();
}


suggestions::~suggestions()
{
    delete ui;
}

void suggestions::on_pushButton_2_clicked()
{
    main_user_page *main_page = new main_user_page;
    main_page->show();
    hide();
}
