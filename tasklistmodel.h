#ifndef TASKLISTMODEL_H
#define TASKLISTMODEL_H
#include <QAbstractListModel>
#include <QDate>
#include <QDateTime>
#include <QTime>

class Task {
public:

    Task() { }
    Task(int id, const QString &taskName, const QString &taskDescription, int taskLevel,
         const QDate &date, const QDateTime &beginDate, const QDateTime &endDate, const QTime &runTime,
         bool isSonTask, int fatherId, const QString &tag)
        : id(id), taskName(taskName), taskDescription(taskDescription), taskLevel(taskLevel),
        date(date), beginDate(beginDate), endDate(endDate), runTime(runTime),
        isSonTask(isSonTask), fatherId(fatherId), tag(tag) {}

    // 变量
    int id;
    QString taskName;
    QString taskDescription;
    int taskLevel;
    QDate date;
    QDateTime beginDate;
    QDateTime endDate;
    QTime runTime;
    bool isSonTask;
    int fatherId;
    QString tag;

};

class TaskListModel :public QAbstractListModel
{
    Q_OBJECT
public:
    enum TaskRoles {
        IdRole = Qt::UserRole + 1,
        TaskNameRole,
        TaskDescriptionRole,
        TaskLevelRole,
        DateRole,
        BeginDateRole,
        EndDateRole,
        RunTimeRole,
        IsSonTaskRole,
        FatherIdRole,
        TagRole
    };
    TaskListModel(QObject *parent = nullptr);
    Q_INVOKABLE void addTask(int id, const QString &taskName, const QString &taskDescription, int taskLevel,
                             const QDate &date, const QDateTime &beginDate, const QDateTime &endDate, const QTime &runTime,
                             bool isSonTask, int fatherId, const QString &tag);
    Q_INVOKABLE void removeTask(int id);
    Q_INVOKABLE void updateTask(int id, const QString &taskName, const QString &taskDescription, int taskLevel,
                                const QDate &date, const QDateTime &beginDate, const QDateTime &endDate, const QTime &runTime,
                                bool isSonTask, int fatherId, const QString &tag);

    void addTask(const Task& task);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
protected:
    QHash<int, QByteArray> roleNames() const override;
private:
    QList<Task> tasks;

};

#endif // TASKLISTMODEL_H






































