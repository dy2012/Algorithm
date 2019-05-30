#include <string.h>

#include <iostream>

using namespace std;

class StringDiy {
 public:
  StringDiy();
  StringDiy(char* str = nullptr);
  StringDiy(const StringDiy& str);
  ~StringDiy();
  StringDiy operator+(const StringDiy& str);
  StringDiy& operator=(const StringDiy& str);
  bool operator==(const StringDiy& str);
  int length();
  StringDiy substr(int start, int n);
  StringDiy(StringDiy&& rhs);
  friend ostream& operator<<(ostream& o, const StringDiy& str);
  void swap(StringDiy& str);
  const char* c_str() const;
 private:
  char* m_data;
  int m_size;
};

StringDiy::StringDiy() : m_data(new char[1]), m_size = 1 {
  *m_data = '\0';
}

StringDiy::StringDiy(char* str) {
  if (str == nullptr) {
    m_data = new char[1];
    m_data[0] = '\0';
    m_size = 0;
  } else {
    m_size = strlen(str);
    m_data = new char[m_size + 1];
    strcpy(m_data, str);
  }
}

StringDiy::StringDiy(const StringDiy& str) {
  m_size = str.m_size;
  m_data = new char[m_size + 1];
  strcpy(m_data, str.m_data);
}

StringDiy::~StringDiy() {
  delete [] m_data;
}

StringDiy StringDiy::operator+(const StringDiy& str) {
  StringDiy new_str;
  delete [] new_str.m_data;
  new_str.m_size = m_size + str.m_size;
  new_str.m_data = new char[new_str.m_size + 1];
  strcpy(new_str.m_data, m_data);
  strcpy(new_str.m_data + m_size, str.m_data);
  return new_str;
}

StringDiy& StringDiy::operator=(const StringDiy& str) {
  if (m_data == str.m_data) {
    return *this;
  }

  delete [] m_data;
  m_size = str.m_size;
  m_data = new char[m_size + 1];
  strcpy(m_data, str.m_data);
  return *this;
}

bool StringDiy::operator==(const StringDiy& str) {
  return strcmp(m_data, str.m_data) == 0;
}

int StringDiy::length() {
  return m_size;
}

StringDiy StringDiy::substr(int start, int n) {
  StringDiy new_str;
  delete [] new_str.m_data;
  new_str.m_data = new char[n + 1];
  for (int i = 0; i < n; ++i) {
    new_str.m_data[i] = m_data[start + i];
  }
  new_str.m_data[n] = '\0';
  new_str.m_size = n;
  return new_str;
}

StringDiy::StringDiy(StringDiy&& rhs) 
  : m_data(rhs.m_data) {
  rhs.m_data = nullptr;
}

ostream& operator<<(ostream& os, const StringDiy& str) {
  os << str.m_data;
  return os;
}

void StringDiy::swap(StringDiy& rhs) {
  std::swap(m_data, rhs.m_data);
}

const char* StringDiy::c_str() const {
  return m_data;
}

int main() {
  char tmp[] = "hello";
  StringDiy temp(tmp);
  cout << temp << endl;
  cout << temp.substr(0, 3) << endl;
  cout << (temp == temp.substr(0, 3)) << endl;
  return 0;
}
