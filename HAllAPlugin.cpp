#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "HAllAPlugin.h"

void HAllAPlugin::input(std::string file) {
   readParameterFile(file);
}

void HAllAPlugin::run() {}

//halla -x examples/nutrimouse/lipid.txt -y examples/nutrimouse/gene.txt -o nutrimouse_output
void HAllAPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
 myCommand += "halla -x "+PluginManager::addPrefix(myParameters["file1"])+" -y "+PluginManager::addPrefix(myParameters["file2"])+" -o "+file;
std::cout << myCommand << std::endl;
system(myCommand.c_str());
myCommand = "cp "+file+"/* ./plugins/HAllA/example/";
system(myCommand.c_str());
myCommand = "rm -r "+file;
system(myCommand.c_str());
}

PluginProxy<HAllAPlugin> HAllAPluginProxy = PluginProxy<HAllAPlugin>("HAllA", PluginManager::getInstance());
