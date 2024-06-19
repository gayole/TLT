import QtQuick 2.15
import QtQuick.Controls 2.15
import com.yourcompany.tasklist 1.0
ApplicationWindow {
    visible: true
    width: 640
    height: 480

    TaskListModel {
        id: taskListModel
    }

    Component.onCompleted: {
        taskListModel.addTask(1, "Task 1", "Description 1", 1, new Date(), new Date(), new Date(), "01:30:00", false, -1, "Tag1");
        taskListModel.addTask(2, "Task 2", "Description 2", 2, new Date(), new Date(), new Date(), "02:00:00", true, 1, "Tag2");
    }
    ListView {
        anchors.fill: parent
        model: taskListModel

        delegate: Item {
            width: parent.width
            height: 50

            Row {
                Text {
                    text: model.taskName
                    width: 100
                }
                Text {
                    text: model.taskDescription
                    width: 200
                }
                Text {
                    text: model.taskLevel
                    width: 50
                }
                // 你可以添加更多的 Text 元素来显示其他属性。
                Button {
                    text: "Delete"
                    onClicked: {
                        taskListModel.removeTask(model.id)
                    }
                }
                Button {
                    text: "Update"
                    onClicked: {
                        taskListModel.updateTask(model.id, "Updated Task", "Updated Description", 1, new Date(), new Date(), new Date(), "01:00:00", false, -1, "Updated Tag")
                    }
                }
            }
        }
    }
}
