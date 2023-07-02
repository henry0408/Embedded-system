#ifndef USERDATA_H
#define USERDATA_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

struct UserEntity
{
    //每个成员对应表中的一个字段，主要用于数据的传递
    int userId;
    QString nickName;
    QString passwd;
    int headId;
};

//单例模式-》数据库
class UserDao
{
private:
    //创建数据驱动类对象
    QSqlDatabase db;
    static UserDao *ins;
    UserDao();//构造 -》创建表
    UserDao(const UserDao& o);
public:
    static UserDao* getIns();
    void createTable();//创建表
    bool insertTable(UserEntity& e);//插入数据   用于注册
    bool selectTable(UserEntity& e, bool& ok); //查询数据，用于登录
    ~UserDao();
};

#endif // USERDATA_H
