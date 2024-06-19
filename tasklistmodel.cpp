#include "tasklistmodel.h"

TaskListModel::TaskListModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void TaskListModel::addTask(const Task &task)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    tasks << task;
    endInsertRows();
}

void TaskListModel::addTask(int id, const QString &taskName, const QString &taskDescription, int taskLevel,
                            const QDate &date, const QDateTime &beginDate, const QDateTime &endDate, const QTime &runTime,
                            bool isSonTask, int fatherId, const QString &tag)
{
    addTask(Task(id, taskName, taskDescription, taskLevel, date, beginDate, endDate, runTime, isSonTask, fatherId, tag));
}

void TaskListModel::removeTask(int id)
{
    for (int i = 0; i < tasks.size(); ++i) {
        if (tasks[i].id == id) {
            beginRemoveRows(QModelIndex(), i, i);
            tasks.removeAt(i);
            endRemoveRows();
            return;
        }
    }

}

void TaskListModel::updateTask(int id, const QString &taskName, const QString &taskDescription, int taskLevel, const QDate &date, const QDateTime &beginDate, const QDateTime &endDate, const QTime &runTime, bool isSonTask, int fatherId, const QString &tag)
{
    for (int i = 0; i < tasks.size(); ++i) {
        if (tasks[i].id == id) {
            tasks[i].taskName = taskName;
            tasks[i].taskDescription = taskDescription;
            tasks[i].taskLevel = taskLevel;
            tasks[i].date = date;
            tasks[i].beginDate = beginDate;
            tasks[i].endDate = endDate;
            tasks[i].runTime = runTime;
            tasks[i].isSonTask = isSonTask;
            tasks[i].fatherId = fatherId;
            tasks[i].tag = tag;

            QModelIndex modelIndex = index(i);
            emit dataChanged(modelIndex, modelIndex, {TaskNameRole, TaskDescriptionRole, TaskLevelRole, DateRole, BeginDateRole, EndDateRole, RunTimeRole, IsSonTaskRole, FatherIdRole, TagRole});
            return;
        }
    }
}

int TaskListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return tasks.count();
}

QVariant TaskListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= tasks.count())
        return QVariant();

    const Task &task = tasks[index.row()];

    switch (role) {
    case IdRole:
        return task.id;
    case TaskNameRole:
        return task.taskName;
    case TaskDescriptionRole:
        return task.taskDescription;
    case TaskLevelRole:
        return task.taskLevel;
    case DateRole:
        return task.date;
    case BeginDateRole:
        return task.beginDate;
    case EndDateRole:
        return task.endDate;
    case RunTimeRole:
        return task.runTime;
    case IsSonTaskRole:
        return task.isSonTask;
    case FatherIdRole:
        return task.fatherId;
    case TagRole:
        return task.tag;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> TaskListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[TaskNameRole] = "taskName";
    roles[TaskDescriptionRole] = "taskDescription";
    roles[TaskLevelRole] = "taskLevel";
    roles[DateRole] = "date";
    roles[BeginDateRole] = "beginDate";
    roles[EndDateRole] = "endDate";
    roles[RunTimeRole] = "runTime";
    roles[IsSonTaskRole] = "isSonTask";
    roles[FatherIdRole] = "fatherId";
    roles[TagRole] = "tag";
    return roles;
}
