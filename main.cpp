/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:17:56 by mflury            #+#    #+#             */
/*   Updated: 2024/05/12 20:42:04 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

// ARGV[1] <filename>, ARGV[2] the occurence we search, ARGV[3] destination file.

int main(int argc, char **argv) {
	if (argc != 4) {
    	std::cerr << "parameters must be \"<filename> , \"occurence we search\", destination file name\"." << std::endl;
        return 1;
    }
    // Open input file
    std::string inFileName = argv[1];
    std::ifstream inFile(inFileName.c_str());
    if (!inFile.is_open()) {
        std::cerr << "Failed to open the input file." << std::endl;
        return 1;
    }
    // Open output file
    std::string outFileName = argv[3];
    std::ofstream outFile(outFileName.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Failed to create the output file." << std::endl;
        inFile.close();
        return 1; // Return error
    }
    // Strings for target and replacement
    std::string target = argv[2];
    // Read input file line by line, replace target string, and write to output file
    std::string line;
    while (std::getline(inFile, line)) {
		if (line.find(argv[2]) != std::string::npos) {
        	outFile << line << std::endl;
			std::getline(inFile, line);
			outFile << line << std::endl;
		}
    }
    // Close files
    inFile.close();
    outFile.close();
    std::cout << "File copied with searched occurence." << std::endl;
    return 0;
}
