/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:40:46 by esteiner          #+#    #+#             */
/*   Updated: 2024/02/12 13:40:46 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <fstream>

std::string replace_line(std::string line, std::string search, std::string replace) {
    std::string result;
    size_t startPos = 0;
    size_t foundPos = line.find(search);

    while (foundPos != std::string::npos)
    {
        result += line.substr(startPos, foundPos - startPos) + replace;
        startPos = foundPos + search.length();
        foundPos = line.find(search, startPos);
    }
    result += line.substr(startPos);
    return (result);
}

int main(int argc, char** argv) {
    if (argc < 4) {
        std::cout << "wrong number of arguments." << std::endl;
        return (0);
    }
    std::string searchString1(argv[2]);
    std::string replaceString2(argv[3]);
    std::ifstream readFile;

    readFile.open(argv[1], std::ios::in);
    if (!readFile.is_open()) {
        std::cerr << "file could not be opened." << std::endl;
        return (1);
    }
    std::string filename(argv[1]);
    filename += ".replace";
    std::ofstream writeFile;
    writeFile.open(filename.c_str(), std::ios::out); //| std::ios::app
    if (!writeFile.is_open()) {
        std::cerr << "error while opening .replace file." << std::endl;
        return (1);
    }
    std::string tempLine;
    std::string replacedLine;
    while (std::getline(readFile, tempLine)) {
        replacedLine = replace_line(tempLine, searchString1, replaceString2);
        writeFile << replacedLine << "\n";
    }
    readFile.close();
    writeFile.close();
    return (0);
}
