#ifndef TASKLISTMODEL_H
#define TASKLISTMODEL_H
#include <QAbstractListModel>

class Task {
    Task() {

    }

};

class TaskListModel :public QAbstractListModel
{
    Q_OBJECT
public:
    TaskListModel();
};

#endif // TASKLISTMODEL_H
