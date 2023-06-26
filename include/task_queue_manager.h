// task_queue_manager.h

#ifndef TASK_QUEUE_MANAGER_H
#define TASK_QUEUE_MANAGER_H

#include <string>
#include <queue>

class TaskQueueManager
{
public:
    TaskQueueManager();
    ~TaskQueueManager();
    void addTask(const std::string &task);
    std::string getTask();
    void processTasks();

private:
    std::queue<std::string> taskQueue;
};

#endif // TASK_QUEUE_MANAGER_H
