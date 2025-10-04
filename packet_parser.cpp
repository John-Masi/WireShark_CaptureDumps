#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

void dump_hex(std::string& pnap){
	std::string cmd = "hexdump -C " + pnap + " > dump.txt";
	if(system(cmd.c_str()) < 0){
		//Throw error 
	}
	else {
		std::cout << "File has been dumped!" << '\n';
	}

}

void handle_input() {
	std::string packet_info;
	while(true){
		std::cin >> packet_info;
		if(packet_info.ends_with(".pcapng")) {
			dump_hex(packet_info);
			break;
		}
	}

}

int main() {

	std::ofstream file("dump.txt");

	if(!file.is_open()){
		std::cout << "Could not find file";
	}

	handle_input();	


	file.close();
}