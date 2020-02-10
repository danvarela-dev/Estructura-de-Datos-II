#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(push, 1)

struct IMAGE_DOS_HEADER {
    char e_magic[2];         // Magic number
    uint16_t e_cblp;          // Bytes on last page of file
    uint16_t e_cp;            // Pages in file
    uint16_t e_crlc;          // Relocations
    uint16_t e_cparhdr;       // Size of header in paragraphs
    uint16_t e_minalloc;      // Minimum extra paragraphs needed
    uint16_t e_maxalloc;      // Maximum extra paragraphs needed
    uint16_t e_ss;            // Initial (relative) SS value
    uint16_t e_sp;            // Initial SP value
    uint16_t e_csum;          // Checksum 
    uint16_t e_ip;            // Initial IP value
    uint16_t e_cs;            // Initial (relative) CS value
    uint16_t e_lfarlc;        // File address of relocation table
    uint16_t e_ovno;          // Overlay number
    char e_res[4];            //Reserved words
    uint16_t e_oemid;         // OEM identifier (for e_oeminfo)
    uint16_t e_oeminfo;       // OEM information; e_oemid specific
    char e_res2[10];      // Reserved words
    uint64_t   e_lfanew;        // File address of new exe header
};
#pragma pack(pop)

int main() {



    ifstream file_PE;
    IMAGE_DOS_HEADER dos_header;
    file_PE.open("C://Windows//System32//cmd.exe", ifstream::in, ifstream::binary);
    file_PE.read((char*)&dos_header, sizeof(dos_header));


    char e_res[5];
    char e_res2[11];
    char magic[3];
    magic[0] = dos_header.e_magic[0];
    magic[1] = dos_header.e_magic[1];
    magic[2] = '\0';

    e_res[4] = '\0';
    e_res[0] = dos_header.e_res[0];
    e_res[1] = dos_header.e_res[1];
    e_res[2] = dos_header.e_res[2];
    e_res[3] = dos_header.e_res[3];


    e_res2[10] = '\0';
    e_res2[0] = dos_header.e_res2[0];
    e_res2[1] = dos_header.e_res2[1];
    e_res2[2] = dos_header.e_res2[2];
    e_res2[3] = dos_header.e_res2[3];
    e_res2[4] = dos_header.e_res2[4];
    e_res2[5] = dos_header.e_res2[5];
    e_res2[6] = dos_header.e_res2[6];
    e_res2[7] = dos_header.e_res2[7];
    e_res2[8] = dos_header.e_res2[8];
    e_res2[9] = dos_header.e_res2[9];
    
  
    cout << "e_magic: " << magic  << endl;
        cout << "e_cblp: " << dos_header.e_cblp << endl;
        cout << "e_cp: " << dos_header.e_cp << endl;
    cout << "e_crlc: " << dos_header.e_crlc  << endl;
    cout << "e_cparhdr: " << dos_header.e_cparhdr  << endl;
    cout << "e_minalloc: " << dos_header.e_minalloc << endl;
    cout << "e_maxalloc: " << dos_header.e_maxalloc << endl;
    cout << "e_ss: " << dos_header.e_ss<< endl;
    cout << "e_sp: " << dos_header.e_sp  << endl;
    cout << "e_csum: " << dos_header.e_csum << endl;
    cout << "e_ip: " << dos_header.e_ip  << endl;
    cout << "e_cs: " << dos_header.e_cs  << endl;
    cout << "e_lfarlc: " << dos_header.e_lfarlc << endl;
    cout << "e_ovno: " << dos_header.e_ovno << endl;
    cout << "e_res: " << e_res << endl;
    cout << "e_oemid: " << dos_header.e_oemid  << endl;
    cout << "e_oeminfo: " << dos_header.e_oeminfo  << endl;
    cout << "e_res2: " << e_res2  << endl;
    cout << "e_lfanew: " << dos_header.e_lfanew  << endl;


    }	