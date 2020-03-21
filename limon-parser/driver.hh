#ifndef DRIVER_HH
# define DRIVER_HH
# include <string>
# include <map>
# include "json.hpp"
# include "parser.hh"

using json = nlohmann::json;

// Give Flex the prototype of yylex we want ...
# define YY_DECL \
  yy::parser::symbol_type yylex (driver& drv)
// ... and declare it for the parser's sake.
YY_DECL;

// Conducting the whole scanning and parsing of Calc++.
class driver
{
public:
  driver ();
  // Run the parser on file F.  Return 0 on success.
  int parse (const std::string& f);
  
  json result;

  // Whether to generate scanner debug traces.
  bool trace_scanning;  // Whether to generate parser debug traces.
  bool trace_parsing;

  // The token's location used by the scanner.
  yy::location location;

  // The name of the file being parsed.
  std::string file;

private:
  // Handling the scanner.
  void scan_begin ();
  void scan_end ();
};
#endif // ! DRIVER_HH
