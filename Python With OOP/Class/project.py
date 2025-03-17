class Task:
    def __init__(self, title, description, due_date, priority):
        self.title = title
        self.description = description
        self.due_date = due_date
        self.priority = priority
        self.status = "Pending"

    def update_status(self, new_status):
        self.status = new_status

    def display_details(self):
        print(f"Title: {self.title}")
        print(f"Description: {self.description}")
        print(f"Due Date: {self.due_date}")
        print(f"Priority: {self.priority}")
        print(f"Status: {self.status}")


class TodoTask(Task):
    pass


class DeadlineTask(Task):
    def __init__(self, title, description, due_date, priority, deadline):
        super().__init__(title, description, due_date, priority)
        self.deadline = deadline

    def display_details(self):
        super().display_details()  # Call the parent class method
        print(f"Deadline: {self.deadline}")


class EventTask(Task):
    def __init__(self, title, description, due_date, priority, start_time, end_time):
        super().__init__(title, description, due_date, priority)
        self.start_time = start_time
        self.end_time = end_time

    def display_details(self):
        super().display_details()  # Call the parent class method
        print(f"Start Time: {self.start_time}")
        print(f"End Time: {self.end_time}")


class TaskManager:
    def __init__(self):
        self.tasks = []

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
                print()  # Empty line for readability


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



if __name__ == "__main__":
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
            print("All tasks:")
            task_manager.list_tasks()
        elif choice == "4":
            print("Exiting program.")
            break
        else:
            print("Invalid choice. Please try again.")
