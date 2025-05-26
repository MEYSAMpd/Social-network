#include "user.h"
#include <QString>

void User::setUser(const QString & username, const QString& password, const QString& name , const QString& bio , vector<QString> submissions
     , const int numconnections , vector<QString> connections , QString profile_path ){
       setUsername(username);
       setPassword(password);
       setName(name);
       setBio(bio);
       setSubmissions(submissions);
       setNumconnections(numconnections);
       setConnections(connections);
       setProfile_path(profile_path);
}




//                     Getter
QString User::getUsername() const { return P_Username;}
QString User::getPassword() const { return P_Password;}
QString User::getName() const { return P_Name;}
QString User::getBio() const { return P_Bio;}
vector<QString> User::getSubmussions() { return P_Submissions;}
int User::getNumconnections() {return P_Numconnections;}
vector<QString> User::getConnections() { return P_Connections;}
QString User::getProfile_path() {return P_Profile_path;}

//                      Setter
void User::setUsername(const QString & username){ P_Username = username;}
void User::setPassword(const QString & password){ P_Password = password;}
void User::setName(const QString & name){ P_Name = name;}
void User::setBio(const QString & bio){ P_Bio = bio;}
void User::setSubmissions(const vector<QString> & submissions){ P_Submissions = submissions;}
void User::setNumconnections(int numconnections){ P_Numconnections = numconnections;}
void User::setConnections(const vector<QString> & connections){ P_Connections=connections;}
void User::setProfile_path(QString profile_path){ P_Profile_path=profile_path;}

bool User::checkUsername(QString username){
    for(auto itr = M_Database.begin() ; itr != M_Database.end() ; itr++){
        if(itr->first == username){
            return false;
        }
    }
    return true;
}

void User::unFollow(){
    vector<QString> temp = USER.getConnections();
    for(int i = 0 ; i < USER.getNumconnections() ; i++){
        if(temp[i] == viewingUser.getUsername()){
            temp.erase(temp.begin() + i);
            break;
        }
    }
    USER.setConnections(temp);
    USER.setNumconnections(temp.size());
    for(auto itr = M_Database.begin() ; itr != M_Database.end() ; itr++){
        if(itr->first == USER.getUsername()){
            M_Database.erase(itr);
        }
    }
    M_Database.insert(pair<QString , User>(USER.getUsername() , USER));

    temp = viewingUser.getConnections();
    for(int i = 0 ; i < viewingUser.getNumconnections() ; i++){
        if(temp[i] == USER.getUsername()){
            temp.erase(temp.begin() + i);
            break;
        }
    }
    viewingUser.setConnections(temp);
    viewingUser.setNumconnections(temp.size());
    for(auto itr = M_Database.begin() ; itr != M_Database.end() ; itr++){
        if(itr->first == viewingUser.getUsername()){
            M_Database.erase(itr);
        }
    }
    M_Database.insert(pair<QString , User>(viewingUser.getUsername() , viewingUser));
}

map<float , QString> User::suggestion(){
    map<float , QString> suggest;
    vector<QString> USERfollow = USER.getConnections();
    for(auto itr = M_Database.begin() ; itr != M_Database.end() ; itr++){
        if(itr->first != USER.getUsername()){
            auto check = find(USERfollow.begin() , USERfollow.end() , itr->first);
            if(check == USERfollow.end()){
                float count = 0;
                vector<QString> usersFollow = itr->second.getConnections();
                for(int i = 0 ; i < int(usersFollow.size()) ; i++){
                    auto subscriber = find(USER.getConnections().begin() , USER.getConnections().begin() , usersFollow[i]);
                    if(subscriber != USER.getConnections().end()){
                        count ++;
                    }
                }
                if(count != 0){
                    count /= usersFollow.size();
                    suggest.insert(pair<float , QString>(count , itr->first));
                }
            }
        }
    }
    return suggest;
}
