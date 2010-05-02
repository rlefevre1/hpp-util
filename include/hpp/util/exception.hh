// Copyright (C) 2010 by Thomas Moulard, CNRS.
//
// This file is part of the hpp-util.
//
// This software is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the
// implied warranties of fitness for a particular purpose.
//
// See the COPYING file for more information.

#ifndef HPP_UTIL_EXCEPTION_HH
# define HPP_UTIL_EXCEPTION_HH
# include <iosfwd>
# include <stdexcept>
# include <string>

# include <hpp/util/config.hh>

namespace hpp
{
  /// \brief Main exception class for HPP.
  ///
  /// All exceptions thrown in HPP must inherit this class.
  class HPP_UTIL_DLLAPI Exception : public std::exception
  {
  public:
    Exception (const std::string& message,
	       const std::string& file,
	       unsigned line) throw ();
    ~Exception () throw ();
    Exception (const Exception& exception) throw ();
    Exception& operator= (const Exception& exception) throw ();

    virtual const char* what () const throw ();
  private:
    std::string message_;
    std::string file_;
    unsigned line_;
  };

  /// \brief Override operator<< to handle exception display.
  ///
  /// \param o output stream used for display
  /// \param exception exception to be displayed
  /// \return output stream
  HPP_UTIL_DLLAPI std::ostream&
  operator<< (std::ostream& o, const Exception& exception);

} // end of namespace hpp.

#endif //! HPP_UTIL_EXCEPTION_HH
