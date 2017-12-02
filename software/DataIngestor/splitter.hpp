#ifndef SPLITTER_HPP
#define SPLITTER_HPP

#include <string>
#include <vector>

class splitter {
    public:
        splitter();
        ~splitter();

        void initialize(std::string configFile);

        void parseString(std::string toParse);

        void printLatest();

        typedef std::vector<std::pair<std::string, long int> > resultVector;
        resultVector latestParsed;



    protected:
    	// Checks a line of the config file to see if it is a comment
			// Returns true if it is
		bool isComment(std::string configLine);

		int checkPair(std::string key, std::string value);

		// How many fields the splitter is set up to read
		int m_numFields = 0;    	
};

#endif //SPLITTER_HPP
