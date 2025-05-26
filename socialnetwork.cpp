#include "socialnetwork.h"
#include "ui_socialnetwork.h"
#include <QString>
#include <QStringList>
#include <main_user_page.h>

map<QString , User> M_Database;
//                                             some data
//================================================================================
//User user1;
//vector<QString> sub;
//vector<QString> con;
//user1.setUser("Nimamms","123","Nima","testbio",sub,0,con );
//M_Database.insert(make_pair(user1.getUsername(),user1));
//================================================================================
User USER;
socialNetwork::socialNetwork(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::socialNetwork)
{
    ui->setupUi(this);

    //  map for all users in database
    //  Username(unique) , all info


//    QString appDir = QCoreApplication::applicationDirPath();
//        qDebug() << "Application Directory:" << appDir;

//        // مسیر مطلق فایل مورد نظر
//        QString absoluteFilePath = "C:/Users/user/Documents/Data structure project/social-network-ghost/Users.sqlite";

//        // تبدیل مسیر مطلق به مسیر نسبی نسبت به مسیر برنامه
//        QDir dir(appDir);
//        QString relativeFilePath = dir.relativeFilePath(absoluteFilePath);

//    //                          **load Database data**
//    //================================================================================
//    QSqlDatabase db = QSqlDatabase ::addDatabase("QSQLITE") ;
//    db.setDatabaseName(relativeFilePath);
//    db.open();
//    if (db.isOpen())
//    {
//        QSqlQuery query("SELECT User_Username , User_Password , User_Name , User_Bio , User_Submissions , User_Numconnections , User_Connections FROM Users");
//        if(query.exec())
//        {
//            while(query.next())
//            {
//                QString username = query.value(0).toString();
//                QString password = query.value(1).toString();
//                QString name = query.value(2).toString();
//                QString bio = query.value(3).toString();
//                //-----------------------------------------------------------
//                QString Str_submissions = query.value(4).toString();
//                vector<QString> V_submissions;
//                QStringList list = Str_submissions.split('+');
//                for (const QString &item : list)
//                    V_submissions.push_back(item);
//                //-----------------------------------------------------------
//                int num_connections = query.value(5).toInt();
//                //-----------------------------------------------------------
//                QString Str_connections = query.value(6).toString();
//                vector<QString> V_connections;
//                QStringList list_1 = Str_connections.split('+');
//                for (const QString &item : list_1)
//                    V_connections.push_back(item);
//                //-----------------------------------------------------------
//                User user_x;
//                user_x.setUser(username , password , name , bio , V_submissions , num_connections , V_connections);
//                M_Database.insert(pair<QString,User>(username,user_x)) ;
//            }
//        }
//        else
//        {
//            QString error_message = "Failed to execute the search query: " + query.lastError().text();
//            QMessageBox::warning(this, "Error", error_message);
//        }

//    }
//    else
//    {
//         QMessageBox::warning(this, "Error", "Failed to open Database ") ;
//    }
//    db.close();
//    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection) ;
    //================================================================================

}

socialNetwork::~socialNetwork()
{
    delete ui;
}

void socialNetwork::on_pushButton_2_clicked()
{
    sign_up *signup = new sign_up;
    signup->show();
    hide();
}

void socialNetwork::on_pushButton_clicked()
{
    auto itr = M_Database.begin();
    for(itr = M_Database.begin() ; itr != M_Database.end() ; itr++){
        if(itr->first == ui->leUsername->text()){
            if(itr->second.getPassword() == ui->lePassword->text()){
                USER = itr->second;
                viewingUser = USER;
                main_user_page *main_page = new main_user_page;
                main_page->show();
                hide();
                break;
            }
            else{
                QMessageBox::information(this , "Error" , "Password wrong.");
                break;
            }
        }
    }
    if(itr == M_Database.end()){
        QMessageBox::information(this , "Error" , "User not found.");
    }
}
