
#ifndef SAXPARSER_H
#define SAXPARSER_H

#include "SAXHandler.h"
#include "StringStream.h"

namespace trackerml {

    using namespace std;

    class SAXParser {

      protected:
        StringStream buffer;

        bool error = false;

        string errorMsg;

        int errorLine = 0;

        int errorColumn = 0;

        void setError(string msg);

      public:
        SAXHandler *handler;

        void init(string str);

        bool parse(string fileName, SAXHandler &hand);

        bool readElement();

        pair<string, string> readAttribute();

        vector<pair<string, string>> readAttributes();

        bool readComment();

        bool readProcessingInstruction();
    };
}

#endif /* SAXPARSER_H */