#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

void test_replace(string &s, char repl, const string &with);

int
main()
{
  string s1 = "This is a * test with some chars to * be replaced";

  test_replace (s1, '*', "###");
  test_replace (s1, '#', "##@");
  test_replace (s1, '#', "\"");

  return 0;
}

void
test_replace(string &s, char repl, const string &with)
{
  cout << "Before replacing: " << s << endl;

  string::size_type it;

  it = s.find (repl);

  while (it != string::npos)
    {
      s.replace (it, 1, with);
      it = s.find (repl, it + with.size ());
    }

  cout << "After replacing: " << s << "\n" << endl;
}
