#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
#include <string>
#include <QString>
#include <map>
#include <stack>

using namespace std ;

using namespace std ;

class User
{                                   //P : private var
    QString P_Username ;
    QString P_Password ;
    QString P_Name ;
    QString P_Bio ;
    vector<QString> P_Submissions ;
    int P_Numconnections ;
    vector<QString> P_Connections ;
    QString P_Profile_path;

public:
    void setUser(const QString & username, const QString& password, const QString& name , const QString& bio , vector<QString> submissions
         , const int numconnections , vector<QString> connections , QString profile_path="");


    //                     Getter
    QString getUsername() const ;
    QString getPassword() const;
    QString getName() const ;
    QString getBio() const ;
    vector<QString> getSubmussions() ;
    int getNumconnections() ;
    vector<QString> getConnections() ;
    QString getProfile_path();

    //                      Setter
    void setUsername(const QString & username);
    void setPassword(const QString & password);
    void setName(const QString & name);
    void setBio(const QString & bio);
    void setSubmissions(const vector<QString> & submissions);
    void setNumconnections(int numconnections);
    void setConnections(const vector<QString> & connections);
    void setProfile_path(QString filepath);


    bool checkUsername(QString username);
    void unFollow();
    map<float , QString> suggestion();
};

extern map<QString , User> M_Database;
extern User USER;
extern User viewingUser;
extern stack<User> seenUsers;
extern QString NOTE;

#endif // USER_H
