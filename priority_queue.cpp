#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PriorityQueue {
public:
    struct Task {
        string description;
        int priority;
        Task(string description, int priority) : description(description), priority(priority) {}
    };
    vector<Task> heap;

    void insert(string description, int priority) {
        heap.push_back(Task(description, priority));
        int idx = heap.size() - 1;
        while (idx != 0) {
            int parentIdx = (idx - 1) / 2;
            if (heap[parentIdx].priority < heap[idx].priority) {
                swap(heap[parentIdx], heap[idx]);
                idx = parentIdx;
            } else {
                break;
            }
        }
    }

    Task extractMax() {
        Task maxTask = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        int idx = 0;
        while (idx < heap.size()) {
            int leftChildIdx = idx * 2 + 1;
            int rightChildIdx = idx * 2 + 2;
            int largerChildIdx = leftChildIdx;

            if (rightChildIdx < heap.size() && heap[rightChildIdx].priority > heap[leftChildIdx].priority) {
                largerChildIdx = rightChildIdx;
            }

            if (largerChildIdx < heap.size() && heap[largerChildIdx].priority > heap[idx].priority) {
                swap(heap[largerChildIdx], heap[idx]);
                idx = largerChildIdx;
            } else {
                break;
            }
        }
        return maxTask;
    }
};

int main() {
    PriorityQueue taskQueue;
    taskQueue.insert("Task 1", 1);
    taskQueue.insert("Task 2", 2);
    taskQueue.insert("Task 3", 3);
    taskQueue.insert("Task 4", 4);

    while (!taskQueue.heap.empty()) {
        PriorityQueue::Task maxTask = taskQueue.extractMax();
        cout << maxTask.description << endl;
    }

    return 0;
}
