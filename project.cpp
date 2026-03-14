#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// Class for a Study Goal
class Goal {
public:
    string title;
    int priority; // smaller value = higher priority
    bool completed;

    Goal(string t, int p) {
        title = t;
        priority = p;
        completed = false;
    }
};

// Comparator for Priority Queue (min-heap)
struct ComparePriority {
    bool operator()(Goal* g1, Goal* g2) {
        return g1->priority > g2->priority;
    }
};

// Study Goal Tracker Class
class StudyGoalTracker {
private:
    priority_queue<Goal*, vector<Goal*>, ComparePriority> goals;
    vector<Goal*> completedGoals;

public:
    // Add goal
    void addGoal(string title, int priority) {
        Goal* newGoal = new Goal(title, priority);
        goals.push(newGoal);
        cout << "✅ Goal Added: " << title << endl;
    }

    // Mark top priority goal as completed
    void completeGoal() {
        if (goals.empty()) {
            cout << "⚠️ No pending goals!" << endl;
            return;
        }
        Goal* topGoal = goals.top();
        goals.pop();
        topGoal->completed = true;
        completedGoals.push_back(topGoal);
        cout << "🎉 Goal Completed: " << topGoal->title << endl;
    }

    // View pending goals
    void viewPendingGoals() {
        if (goals.empty()) {
            cout << "👍 No pending goals!" << endl;
            return;
        }

        cout << "\n📌 Pending Goals (by priority):" << endl;
        priority_queue<Goal*, vector<Goal*>, ComparePriority> temp = goals;
        while (!temp.empty()) {
            Goal* g = temp.top();
            cout << "- " << g->title << " (Priority: " << g->priority << ")" << endl;
            temp.pop();
        }
    }

    // View completed goals
    void viewCompletedGoals() {
        if (completedGoals.empty()) {
            cout << "❌ No goals completed yet!" << endl;
            return;
        }

        cout << "\n✅ Completed Goals:" << endl;
        for (auto g : completedGoals) {
            cout << "- " << g->title << endl;
        }
    }

    // Search for a goal by title
    void searchGoal(string searchTitle) {
        bool found = false;
        priority_queue<Goal*, vector<Goal*>, ComparePriority> temp = goals;

        while (!temp.empty()) {
            Goal* g = temp.top();
            if (g->title == searchTitle) {
                cout << "🔍 Found Goal: " << g->title << " (Priority: " << g->priority << ")" << endl;
                found = true;
                break;
            }
            temp.pop();
        }

        if (!found) {
            cout << "❌ Goal not found!" << endl;
        }
    }

    // Delete a goal by title
    void deleteGoal(string deleteTitle) {
        priority_queue<Goal*, vector<Goal*>, ComparePriority> temp;
        bool deleted = false;

        while (!goals.empty()) {
            Goal* g = goals.top();
            goals.pop();

            if (g->title == deleteTitle) {
                cout << "🗑️ Goal Deleted: " << g->title << endl;
                deleted = true;
                delete g;
            } else {
                temp.push(g);
            }
        }
        goals = temp;

        if (!deleted) {
            cout << "❌ Goal not found to delete!" << endl;
        }
    }

    // Update goal priority
    void updatePriority(string goalTitle, int newPriority) {
        priority_queue<Goal*, vector<Goal*>, ComparePriority> temp;
        bool updated = false;

        while (!goals.empty()) {
            Goal* g = goals.top();
            goals.pop();

            if (g->title == goalTitle) {
                g->priority = newPriority;
                cout << "✏️ Updated Priority of: " << g->title << " to " << newPriority << endl;
                updated = true;
            }
            temp.push(g);
        }
        goals = temp;

        if (!updated) {
            cout << "❌ Goal not found to update!" << endl;
        }
    }

    // Show total goals
    void showTotalGoals() {
        cout << "📊 Total Pending Goals: " << goals.size() << endl;
        cout << "📊 Total Completed Goals: " << completedGoals.size() << endl;
    }

    // Clear completed goals
    void clearCompletedGoals() {
        if (completedGoals.empty()) {
            cout << "⚠️ No completed goals to clear!" << endl;
            return;
        }
        completedGoals.clear();
        cout << "🧹 Cleared all completed goals!" << endl;
    }
};

// Main Function (Menu-driven)
int main() {
    StudyGoalTracker tracker;
    int choice, priority;
    string title;

    while (true) {
        cout << "\n====== Study Goal Tracker ======" << endl;
        cout << "1. Add Goal" << endl;
        cout << "2. Complete Top Priority Goal" << endl;
        cout << "3. View Pending Goals" << endl;
        cout << "4. View Completed Goals" << endl;
        cout << "5. Search Goal" << endl;
        cout << "6. Delete Goal" << endl;
        cout << "7. Update Goal Priority" << endl;
        cout << "8. Show Total Goals" << endl;
        cout << "9. Clear Completed Goals" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter goal title: ";
            getline(cin, title);
            cout << "Enter priority (smaller = higher priority): ";
            cin >> priority;
            tracker.addGoal(title, priority);
            break;
        case 2:
            tracker.completeGoal();
            break;
        case 3:
            tracker.viewPendingGoals();
            break;
        case 4:
            tracker.viewCompletedGoals();
            break;
        case 5:
            cout << "Enter goal title to search: ";
            getline(cin, title);
            tracker.searchGoal(title);
            break;
        case 6:
            cout << "Enter goal title to delete: ";
            getline(cin, title);
            tracker.deleteGoal(title);
            break;
        case 7:
            cout << "Enter goal title to update: ";
            getline(cin, title);
            cout << "Enter new priority: ";
            cin >> priority;
            tracker.updatePriority(title, priority);
            break;
        case 8:
            tracker.showTotalGoals();
            break;
        case 9:
            tracker.clearCompletedGoals();
            break;
        case 10:
            cout << "👋 Exiting... Keep learning!" << endl;
            return 0;
        default:
            cout << "⚠️ Invalid choice! Try again." << endl;
        }
    }
}
