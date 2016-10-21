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
  std::string get_name() const;
  void set_name(const std::string _name);
  void print(std::ostream& out) const;
  friend std::ostream& operator<<(std::ostream& _out, const Variable& _v){
    _v.print(_out);
    return _out;
  };
  friend bool operator==(Variable const& _v1, Variable const& _v2)
  {
    if(((_v1.name).compare(_v2.name))==0)
      return true;
    return false;
  };
  friend bool operator!=(Variable const& _v1, Variable const& _v2)
  {
    return (!(_v1==_v2));
  };
};

#endif