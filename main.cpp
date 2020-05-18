#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <windows.h>
using namespace std;


int main()
{

  //  printf("WinVersion  %x\n", GetVersion());
  //  printf("WinVersion  %u\n", GetVersion());
    DWORD mask = 0x0000ffff;
    DWORD mask_major = 0b00000000'00000000'00000000'11111111;
    DWORD info = GetVersion();
    DWORD platform = info >> 16;
    DWORD version = info & mask;
    DWORD version_major = version & mask_major;
    DWORD version_minor = version >> 8;
    printf("Windows v%u.%u (build %u)",version_major,version_minor,platform );
    //printf(" Build %u", platform);
    //printf("Your platform is %u.", platform);
    //printf("Windows major version is %u.", version_major);
    //printf("Windows minor version is %u.", version_minor);

  /*  if ((info & 0x40000000) == 0) {
        DWORD build = platform;
        printf(" build %u", build);
    }*/

   /* size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    const auto numbers=input_numbers(number_count);

    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;

    double min,max;
    find_minmax(numbers,min,max);

    const auto bins = make_histogram(numbers, bin_count,min,max);
    show_histogram_svg(bins);*/
    return 0;
}
