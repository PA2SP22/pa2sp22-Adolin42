#include "todo_ui.h"

// Constructor
TodoUI::TodoUI() {
  list_ = new TodoList;
}

// Destructor
TodoUI::~TodoUI() {
    delete list_;
}

// ALlows user to create an item and add it to the list
void TodoUI::CreateItem() {
  cout << "\nInput Description:\n";
  string description = reader_.readString(false);

  cout << "Input Priority:\n";
  int priority = reader_.readInt(1, 5);

  cout << "Input Completed Status\n"
       << "t/f, true/false\n";
  bool completed = reader_.readBool();


  list_->AddItem(new TodoItem(description, priority, completed));
}

// Allows user to edit an item
// Checks for valid item selection
void TodoUI::EditItem() {
  cout << "\nSelect an item to edit via its number:\n";

  int location = reader_.readInt(1, list_->GetSize());

  TodoItem* item = list_->GetItem(location);

  int choice = 0;

  while (choice != 4) {
    cout << "1) Edit Description\n"
         << "2) Edit Priority\n"
         << "3) Edit Completed Status\n"
         << "4) Return to Menu\n";
    choice = reader_.readInt(1, 4);

    string description;
    int priority;
    bool completed;

    switch (choice) {
      case 1:
        description = reader_.readString(false);
        item->set_description(description);
        break;
      case 2:
        priority = reader_.readInt(1, 5);
        item->set_priority(priority);
        break;
      case 3:
        completed = reader_.readBool();
        item->set_completed(completed);
        break;
      default:
        cout << "\nReturning to Main Menu\n";
    }
  }
}

// Deletes a single item in the list
void TodoUI::DeleteItem() {
  int location;

  cout << "\nSelect an item to delete via its number\n";
  location = reader_.readInt(1, list_->GetSize());
  list_->DeleteItem(location);
}

// Views all of the items in the list
void TodoUI::ViewAllItems() {
  if (list_->GetSize() == 0) {
    cout << "No items found\n";
  }
  cout << *list_;
}

// Views specific item in list
void TodoUI::ViewSpecificItem() {
  cout << "Select the item you wish to view via its number\n";

  int location = reader_.readInt(1, list_->GetSize());
  TodoItem* item = list_->GetItem(location);

  cout << "Item #" << location << endl;
  cout << "Description: " << item->description() << endl;
  cout << "Priority: " << item->priority() << endl;
  cout << "Completed: " << item->completed() << endl;
}

// Deletes all items in the list by deleteing list_ and creating a new one
void TodoUI::DeleteAllItems() {
  delete list_;
  list_ = new TodoList;
}

// Menu of options user can select
void TodoUI::Menu() {
  int choice = 0;

  while (choice != 7) {
    cout << "\n\nSelect an option from the menu below\n\n"
         << "(1) Create New Item\n"
         << "(2) Edit an Item\n"
         << "(3) Delete an Item\n"
         << "(4) View All Items\n"
         << "(5) View Specific Item\n"
         << "(6) Delete All Items\n"
         << "(7) Quit Program\n";

    choice = reader_.readInt(1, 7);

    switch (choice) {
      case 1:
        CreateItem();
        break;
      case 2:
        EditItem();
        break;
      case 3:
        DeleteItem();
        break;
      case 4:
        ViewAllItems();
        break;
      case 5:
        ViewSpecificItem();
        break;
      case 6:
        DeleteAllItems();
        break;
      case 7:
        cout << "\nExiting Program\n";
    }
  }
}
