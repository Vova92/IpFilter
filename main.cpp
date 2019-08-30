#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ipf.h>
// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]



void sorting(std::vector<std::vector<int>> *some_vector, bool *check)
{
    *check = true;
    std::sort(some_vector->begin(), some_vector->end(),
              [](const std::vector<int>& a, const std::vector<int>& b) {
        return a > b;
    });
}
std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}
void vector_out(std::vector<std::vector<int>> *outputArray)
{
    for(std::vector<std::vector<int> >::const_iterator ip = outputArray->cbegin(); ip != outputArray->cend(); ++ip)
    {
        for(std::vector<int>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";
            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::string fileName = "C:\\QtProjects\\IPFilter\\IPFilter\\someFile.tsv";
    std::ifstream someFile(fileName.c_str());
    std::string IP;
    std::vector<std::vector<std::string> > ip_pool;
    std::vector<std::vector<int>> ip_pool_int;
    std::vector<std::vector<int>> ip_pool_int_one;
    std::vector<std::vector<int>> ip_pool_int_four_sev;
    std::vector<std::vector<int>> ip_pool_int_foursix;
    if (!someFile.is_open())
        std::cout << "Could not open file: " << fileName << std::endl;
    if (someFile.is_open())
        std::cout << "File is open \n";
    while (std::getline(someFile, IP))
    {
        std::vector<std::string> buff = split(IP, '\t');
        ip_pool.push_back(split(buff.at(0), '.'));
    }

    for(std::vector<std::vector<std::string> >::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        std::vector<int> ip_int;
        for(std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            ip_int.push_back(std::stoi(*ip_part));
        }
        if (ip_int[0] == 1)
            ip_pool_int_one.push_back(ip_int);
        if (ip_int[0] == 46)
            if (ip_int[1] == 70)
                ip_pool_int_four_sev.push_back(ip_int);
        for (unsigned int i = 0; i <= ip_int.size(); i++)
            if (ip_int[i] == 46)
                ip_pool_int_foursix.push_back(ip_int);
        ip_pool_int.push_back(ip_int);
    }

    sorting(&ip_pool_int, &IPF_R);
    sorting(&ip_pool_int_one, &IPF_O);
    sorting(&ip_pool_int_four_sev, &IPF_F_S);
    sorting(&ip_pool_int_foursix, &IPF_F);

    vector_out(&ip_pool_int);
    vector_out(&ip_pool_int_one);
    vector_out(&ip_pool_int_four_sev);
    vector_out(&ip_pool_int_foursix);

        // TODO reverse lexicographically sort



        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output
        // ip = filter(1)

        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
        // ip = filter_any(46)

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46

//    catch(const std::exception &e)
//    {
//        std::cerr << e.what() << std::endl;
//    }

    return 0;
}
