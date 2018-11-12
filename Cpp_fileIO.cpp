#include <fstream> // filhåndtering

// http://www.cplusplus.com/doc/tutorial/files/

/**

# File classes
ofstream: Stream class to write on files
ifstream: Stream class to read from files
fstream: Stream class to both read and write from/to files.

# open() arguments
ios::in		Open for input operations.
ios::out	Open for output operations.
ios::binary	Open in binary mode.
ios::ate	Set the initial position at the end of the file. Default is at the beginning of file.
ios::app	All output is appended to end of the file.
ios::trunc	If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.

**/

int main ()
{
  ofstream myfile;
  myfile.open("example.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
}


