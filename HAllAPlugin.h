#ifndef HAllAPLUGIN_H
#define HAllAPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include "Tool.h"
#include <string>

class HAllAPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "HAllA";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
