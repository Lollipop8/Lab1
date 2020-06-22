#include <fstream>
#include <vector>
#include <string>
 
int main()
{
    std::vector<std::string> file;
 
    {
        std::ifstream ifs{ "out.txt" };
        for (std::string line; std::getline(ifs, line); file.emplace_back(std::move(line)));
    }
 
    std::ofstream ofs{ "out.txt", std::ios::trunc };
    for (auto line : file)
    {
        ofs << line << std::endl;
        if (line.empty()) ofs << std::endl;
    }
}
