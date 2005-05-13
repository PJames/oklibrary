// Oliver Kullmann, 8.5.2005 (Swansea)

#ifndef TESTEXCEPTIONS_QwAq190

#define TESTEXCEPTIONS_QwAq190

#include <stdexcept>
#include <vector>
#include <string>
#include <ostream>
#include <algorithm>
#include <iterator>

namespace OKlib {

  namespace TestSystem {

    typedef unsigned int LineNumber;

    class ErrorDescription {
      const char* file;
      const char* line;
      const char* type_test_class;
    public :
      ErrorDescription() : file(0), line(0), type_test_class(0) {}
      ErrorDescription(const char* const file, const char* const line, const char* const type_test_class) : file(file), line(line), type_test_class(type_test_class) {}
      friend std::ostream& operator <<(std::ostream& out, const ErrorDescription& D) {
        return out << D.file << ": " << D.line << "\n" << D.type_test_class << "\n";
        // ToDo: Adding messages (using module Messages)
      }
    };

    typedef std::vector<ErrorDescription> ErrorContainer;
    // Assumes, that the destructor of std::vector does not throw exceptions.

    class TestException : public std::runtime_error {
      
      ErrorContainer errors;

    public :

      explicit TestException(const std::string& special_circumstances) :  std::runtime_error(special_circumstances) {}
      ~TestException() throw() {}

      TestException& add(const ErrorDescription e) {
        errors.push_back(e);
	return *this;
      }

      friend std::ostream& operator <<(std::ostream& out, const TestException& E) {
        out << __DATE__ ", " __TIME__ "\n";
        out << E.what() << "\n";
        std::copy(E.errors.begin(), E.errors.end(), std::ostream_iterator<ErrorDescription>(out, "\n"));
        return out;
      }
    };

# define OKLIB_LINENUMBER(L) # L
# define OKLIB_INTERMEDIATE(X) OKLIB_LINENUMBER(X)
#define OKLIB_TESTDESCRIPTION (::OKlib::TestSystem::ErrorDescription(__FILE__, OKLIB_INTERMEDIATE(__LINE__), typeid(test_type).name()))

  }

}

#endif
