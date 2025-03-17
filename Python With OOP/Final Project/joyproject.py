import pandas as pd
from abc import ABC, abstractmethod

class Task(ABC):
    def __init__(self, title, description, due_date, priority):
        self.title = title
        self.description = description
        self.due_date = due_date
        self.priority = priority
        self.status = "Pending"

    def update_status(self, new_status):
        self.status = new_status

    @abstractmethod
    def display_details(self):
        pass

    @abstractmethod
    def to_dict(self):
        pass

class TodoTask(Task):
    def display_details(self):
        print(f"Title: {self.title}")
        print(f"Description: {self.description}")
        print(f"Due Date: {self.due_date}")
        print(f"Priority: {self.priority}")
        print(f"Status: {self.status}")

    def to_dict(self):
        return {
            "type": "Todo",
            "title": self.title,
            "description": self.description,
            "due_date": self.due_date,
            "priority": self.priority,
            "status": self.status
        }

class DeadlineTask(Task):
    def __init__(self, title, description, due_date, priority, deadline):
        super().__init__(title, description, due_date, priority)
        self.deadline = deadline

    def display_details(self):
        print(f"Title: {self.title}")
        print(f"Description: {self.description}")
        print(f"Due Date: {self.due_date}")
        print(f"Priority: {self.priority}")
        print(f"Status: {self.status}")
        print(f"Deadline: {self.deadline}")

    def to_dict(self):
        return {
            "type": "Deadline",
            "title": self.title,
            "description": self.description,
            "due_date": self.due_date,
            "priority": self.priority,
            "status": self.status,
            "deadline": self.deadline
        }

class EventTask(Task):
    def __init__(self, title, description, due_date, priority, start_time, end_time):
        super().__init__(title, description, due_date, priority)
        self.start_time = start_time
        self.end_time = end_time

    def display_details(self):
        print(f"Title: {self.title}")
        print(f"Description: {self.description}")
        print(f"Due Date: {self.due_date}")
        print(f"Priority: {self.priority}")
        print(f"Status: {self.status}")
        print(f"Start Time: {self.start_time}")
        print(f"End Time: {self.end_time}")

    def to_dict(self):
        return {
            "type": "Event",
            "title": self.title,
            "description": self.description,
            "due_date": self.due_date,
            "priority": self.priority,
            "status": self.status,
            "start_time": self.start_time,
            "end_time": self.end_time
        }

class TaskManager:
    def __init__(self):
        self.tasks = []
        self.load_tasks()

    def add_task(self, task):
        self.tasks.append(task)

    def remove_task(self, task):
        if task in self.tasks:
            self.tasks.remove(task)
            print("Task removed successfully.")
        else:
            print("Task not found.")

    def list_tasks(self):
        if not self.tasks:
            print("No tasks.")
        else:
            for task in self.tasks:
                task.display_details()
                print()

    def save_tasks(self):
        tasks_dict_list = [task.to_dict() for task in self.tasks]
        df = pd.DataFrame(tasks_dict_list)
        df.to_excel("tasks.xlsx", index=False)
        print("Tasks saved to tasks.xlsx")

    def load_tasks(self):
        try:
            df = pd.read_excel("tasks.xlsx")
            for i, row in df.iterrows():
                task_type = row["type"]
                if task_type == "Todo":
                    task = TodoTask(row["title"], row["description"], row["due_date"], row["priority"])
                elif task_type == "Deadline":
                    task = DeadlineTask(row["title"], row["description"], row["due_date"], row["priority"], row["deadline"])
                elif task_type == "Event":
                    task = EventTask(row["title"], row["description"], row["due_date"], row["priority"], row["start_time"], row["end_time"])
                else:
                    continue
                task.update_status(row["status"])
                self.tasks.append(task)
        except FileNotFoundError:
            print("tasks.xlsx not found")

def create_task():
    title = input("Enter task title: ")
    description = input("Enter task description: ")
    due_date = input("Enter due date (YYYY-MM-DD): ")
    priority = input("Enter priority: ")
    task_type = input("Enter task type (Todo/Deadline/Event): ").capitalize()

    if task_type == "Todo":
        return TodoTask(title, description, due_date, priority)
    elif task_type == "Deadline":
        deadline = input("Enter deadline (YYYY-MM-DD): ")
        return DeadlineTask(title, description, due_date, priority, deadline)
    elif task_type == "Event":
        start_time = input("Enter start time: ")
        end_time = input("Enter end time: ")
        return EventTask(title, description, due_date, priority, start_time, end_time)
    else:
        print("Invalid task type.")
        return None

task_manager = TaskManager()
while True:
    print("\n1. Add Task")
    print("2. Remove Task")
    print("3. List Tasks")
    print("4. Exit")
    choice = input("Enter your choice: ")

    if choice == "1":
        task = create_task()
        if task:
            task_manager.add_task(task)
            print("Task added successfully.")
    elif choice == "2":
        title = input("Enter task title to remove: ")
        task_to_remove = None
        for task in task_manager.tasks:
            if task.title == title:
                task_to_remove = task
                break
        if task_to_remove:
            task_manager.remove_task(task_to_remove)
        else:
            print("Task not found.")
    elif choice == "3":
        print("\nAll tasks:")
        task_manager.list_tasks()
    elif choice == "4":
        task_manager.save_tasks()
        print("Exiting program.")
        break
    else:
        print("Invalid choice. Please try again.")