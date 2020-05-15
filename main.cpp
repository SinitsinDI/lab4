#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <curl/curl.h>
using namespace std;
Input
read_input(istream& in, bool prompt)
{
    Input data;
    if (prompt)
        cerr << "Enter number count: ";
    size_t number_count;
    cin >> number_count;
    if (prompt)
        cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);
    if (prompt)
        cerr << "Enter column count: ";
    size_t bin_count;
    cin>>bin_count;
    data.bin_count = bin_count;

    return data;
}
int main(int argc, char* argv[])
{
    if (argc>1)
    {
        CURL *curl = curl_easy_init();
        const char *curl_easy_strerror(CURLcode errornum);
        if(curl)
        {
            CURLcode res;
            curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
            res = curl_easy_perform(curl);
            if (res!=0)
            {
                curl_easy_strerror(res);
                exit(1);
            }
            curl_easy_cleanup(curl);
        }
        return(0);
    }
    else
    {
        curl_global_init(CURL_GLOBAL_ALL);
        const auto input = read_input(cin,true);
        const auto bins = make_histogram(input);
        //show_histogram_svg(bins);
        show_histogram_text(bins);

        return 0;
    }
}
