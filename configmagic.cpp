#include <fstream>
#include <iostream>
#include <regex>
using namespace std;



int main(int argc, char **argv, char** envp)
{
    if (argc != 3)
    {
        cerr << "Use ./configmagic <inputfile> <outputfile>" << "\n";
        return 1;
    }
    
    ifstream in(argv[1]);
    ofstream out(argv[2]);

    char** env;
    for (env= envp; *env != 0; env++)
    {
        std::regex rgx("CM_(\\w+)=(.*)");
        std::smatch match;
        std::string thisEnv(*env);

        if (std::regex_search(thisEnv, match, rgx))
        {
            string wordToReplace(match[1]);
            string wordToReplaceWith(match[2]);

            if (!in)
            {
                cerr << "Could not open " << argv[1] << "\n";
                return 1;
            }

            if (!out)
            {
                cerr << "Could not open " << argv[2] << "\n";
                return 1;
            }

            string line;
            wordToReplace = "%" + wordToReplace + "%";
            size_t len = wordToReplace.length();
            while (getline(in, line))
            {
                while (true)
                {
                    size_t pos = line.find(wordToReplace);
                    if (pos != string::npos)
                        line.replace(pos, len, wordToReplaceWith);
                    else
                        break;
                }

                out << line << '\n';
            }
        }
    }
}
