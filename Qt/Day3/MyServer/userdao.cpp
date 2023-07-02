#include "userdao.h"

UserDao *UserDao::ins = NULL;

UserDao::UserDao()
{
    //加载数据库驱动
    db = QSqlDatabase::addDatabase("QSQLITE");
    //设置主机名称
    db.setHostName("testdb");
    //数据库文件设置名字
    db.setDatabaseName("testdb.db");
    //打开数据库
    db.open();
    //创建表
    createTable();
}

void UserDao::createTable()
{
    //创建操作类对象
    QSqlQuery query;
    //创建表
    bool re = query.exec("create table if not exists user("
               "userid integer primary key autoincrement,"
               "password varchar(20),"
               "nickname varchar(20),"
               "headid integer)");
    if(re)
    {
        qDebug()<<"创建表";
    }
    else
    {
        qDebug()<<"创建表失败";
    }
    //插入一个原始用户因为希望用户的id是用100001开始，所以原始用户的id是100000
    query.exec("insert into user values(100000,'abc123','admin',0)");
}

bool UserDao::insertTable(UserEntity &e)
{
    //创建操作类对象
    QSqlQuery query;
    //准备sql文
    query.prepare("insert into user(password,nickname,headid) values(?,?,?)");
    //绑定数据
    query.bindValue(0,e.passwd);
    query.bindValue(1,e.nickName);
    query.bindValue(2,e.headId);
    //执行sql文
    bool re = query.exec();
    if(re)
    {
        qDebug()<<"插入表";
    }
    else
    {
        qDebug()<<"插入表失败";
    }
    query.exec("select LAST_INSERT_ROWID()");//查询最新插入的id
    if(query.next())//结果被存入到链表当中 query.next()获取到下一个有效结点
    {
        //query.record()获取一整条记录 value(0)：获取到一个字段的值
        int id = query.record().value(0).toInt();
        qDebug()<<id;
        //保存到结构体当中
        e.userId = id;
    }
    return re;
}

bool UserDao::selectTable(UserEntity &e, bool &ok)
{
    QSqlQuery query;
    query.prepare("select * from user where userid = ? and password = ?");
    query.bindValue(0,e.userId);
    query.bindValue(1,e.passwd);

    qDebug()<<e.userId;
    qDebug()<<e.passwd;

    bool re = query.exec();
    if(re)  //查找成功
    {
        qDebug()<<"查询表";
        if(query.next())
        {
            //获取查询的数据
            e.nickName = query.record().value(2).toString();
            e.headId = query.record().value(3).toInt();
            qDebug()<<e.nickName;
            ok = true;
        }
        else
        {

            qDebug()<<"失败";
            ok = false;
        }

    }
    else
    {
        qDebug()<<"查询表失败";
    }

    return re;
}

UserDao::UserDao(const UserDao &o)
{

}

UserDao *UserDao::getIns()
{
    if(ins == NULL)
    {
        ins = new UserDao;
    }
    return ins;
}

UserDao::~UserDao()
{

}

