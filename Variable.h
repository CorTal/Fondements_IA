#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

class Variable{
private:
  std::string name;
public:
  Variable();
  Variable(std::string _name);
  Variable(const Variable& _V);
  std::string get_name();
  void set_name(const std::string _name);
  void print(std::ostream& out) const;
  friend std::ostream& operator<<(std::ostream& _out, const Variable& _v){
    _v.print(_out);
    return _out;
  };
};

#endif