#include <iostream>
#include <cstdlib>
#include "json.hpp"
#include <fstream>
#include "cmd/cmd_input.h"

using namespace std;
using json = nlohmann::json;


int main(int argc, const char *argv[]) {
	// here we set up the entire workflow
	
	CmdInput cmd_input;
	
	ActionDispatchParams dispatch_params = cmd_input.parse_input(argc, argv);
	std::cout << dispatch_params.action_name << std::endl;
	
	return 0;
}

int write_to_json() {
	
	json j;
	j["pi"] = 3.14;
	string filePath = "modules.json";
	
	ofstream outputFile(filePath);
	if (!outputFile.is_open()) {
		cerr << "Failed to open" << filePath << endl;
		return 1;
	}
	
	// Print the JSON object
	outputFile << j.dump(4);
	// To print in a pretty format with indentation, you can do:
	outputFile.close();
	
	cout << "JSON data has been written to " << filePath << endl;
	
	return 0;
}
