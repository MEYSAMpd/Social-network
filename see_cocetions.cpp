#include "see_cocetions.h"
#include "ui_see_cocetions.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QObject>
#include <user.h>
#include <other_user_page.h>
#include <main_user_page.h>
#include <QMessageBox>

see_cocetions::see_cocetions(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::see_cocetions)
{
    ui->setupUi(this);
    for (auto x : viewingUser.getConnections())
    {
        QHBoxLayout *newlayout = new QHBoxLayout();
        QLabel *label = new QLabel("");
        label->setFixedSize(111, 111);
        label->setStyleSheet("border: none; border-radius: 50px; border-image: url(:/img/user-01_generated.jpg);");
        QPushButton *button = new QPushButton(x);
        button->setFixedHeight(90);
        button->setStyleSheet("background-color: rgb(33, 150, 243); color: rgb(255, 255, 255); border: none; border-radius: 40px;");
        button->setCursor(Qt::PointingHandCursor);
        newlayout->addWidget(button);
        newlayout->addWidget(label);
        ui->verticalLayout->insertLayout(0, newlayout);
        QObject::connect(button , &QPushButton::clicked, this, &see_cocetions::on_button_clicked);
    }
    QWidget *buttonContainer = new QWidget(this);
    buttonContainer->setLayout(ui->verticalLayout);
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(buttonContainer);
    scrollArea->setWidgetResizable(true);
    QHBoxLayout *mainLayout = new QHBoxLayout(ui->widget);
    mainLayout->addWidget(scrollArea);
}

void see_cocetions::on_button_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(QObject::sender());
    QString name = button->text();
    if (name == USER.getUsername())
    {
        QMessageBox::information(this , "Attention" , "This is you!");
    }
    else {
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
}

see_cocetions::~see_cocetions()
{
    delete ui;
}

void see_cocetions::on_pushButton_2_clicked()
{
    if(seenUsers.size() == 0){
        main_user_page *main_page = new main_user_page;
        main_page->show();
        hide();
    }
    else{
        //viewingUser = seenUsers.top();
        //seenUsers.pop();
        other_user_page *anotherone_page = new other_user_page;
        anotherone_page->show();
        hide();
    }
}
