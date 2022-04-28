#include "todo_item.h"


TodoItem::TodoItem(string description, int priority, bool completed) {
  description_ = description;
  priority_ = priority;
  completed_ = completed;
}

  /*
  Returns a string containing the description, 
priority, and completed status, separated by the @ symbol (This is 
the description@3@1). Uses the scrub function to change @ 
symbols that may be contained in description_.
  */
string TodoItem::ToFile() {
  stringstream ss;

  ss << Scrub(description_) << '@' << priority_ << '@' << completed_;

  return ss.str();
}

string TodoItem::description() {
  return description_;
}

int TodoItem::priority() {
  return priority_;
}

bool TodoItem::completed() {
  return completed_;
}

void TodoItem::set_description(string description) {
    description_ = description;
}

void TodoItem::set_priority(int priority) {
  if (priority < 1 || priority > 5) {
    priority_ = 5;
  } else {
    priority_ = priority;
  }
}

void TodoItem::set_completed(bool completed) {
    completed_ = completed;
}

string TodoItem::Scrub(string to_scrub) {
  for (unsigned int i = 0; i < to_scrub.size(); i++) {
    if (to_scrub.at(i) == '@') {
      to_scrub.at(i) = '`';
    }
  }
  return to_scrub;
}
