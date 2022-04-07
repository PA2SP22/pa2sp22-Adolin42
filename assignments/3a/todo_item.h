#include <iostream>
#include <string>
#include <sstream>
using std::stringstream;
using std::string;

class TodoItem {
 public:
  // Constructor
  TodoItem(string description = "", int priority = 1, bool completed = false);
  // Member Functions
  string ToFile();
  // Accessors/Getters
  string description();
  int priority();
  bool completed();

  // Mutators/Setters
  void set_description(string description);
  void set_priority(int priority);
  void set_completed(bool completed);

 private:
  string description_;
  int priority_;
  bool completed_;
  string Scrub(string to_scrub);
};
