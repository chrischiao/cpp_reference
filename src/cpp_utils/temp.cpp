#include "pch.h"

/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "io.h"
#include "direct.h"

#define MULTIPLE_ROUND(i, j) ((i+(j-1))&~(j-1))
#define MULTIPLE4_ROUND(i) MULTIPLE_ROUND(i, 4)

class Vertex
{
public:
    double x,y,z;
    Vertex()
    :x(0.1), y(0.2), z(0.3)
    {}
};

void test()
{
    Vertex* p1 = (Vertex*)malloc(sizeof(Vertex));
    memset((void*)p1, 0, sizeof(Vertex));
    (void) new(p1) Vertex;

    Vertex* p2 = (Vertex*)malloc(sizeof(Vertex));
    memset((void*)p2, 0, sizeof(Vertex));
    ::new(p2) Vertex;
    
    std::cout<<p1->x<<std::endl;
    std::cout<<p2->x<<std::endl;

    free(p1);
    free(p2);
}

void log(const char* sFileName, const char* sFuncName, int lineNum)
{
    
}

#ifndef LOG
#if defined(_DEBUG)
#define LOG() log(__FILE__, __FUNCTION__, __LINE__) 
#else
#define LOG()
#endif
#endif

void SetEnv(const char* sPath)
{
    std::string env = getenv("PATH");
    if(env.find(sPath) == std::string::npos)
    {
        std::string newEnv = "PATH="+env+";"+sPath;
        putenv(newEnv.c_str());
    }
}

bool CreateDir(const std::string& sPath)
{
    auto len = sPath.length();
    if(len < 1 || len > MAX_PATH)
        return false;
                
    if(access(sPath.c_str(), 0) == 0)
        return true;
                
    char tmp[MAX_PATH]={0};
    for(auto i=0;i<len;i++)
    {
        tmp[i]=sPath[i];
        if(tmp[i]=='\\' || tmp[i]=='/')
        {
            if(access(tmp, 0) != 0)
            {
                if(mkdir(tmp) != 0)
                    return false;
            }
        }
    }

    return true;
}

void GetFiles(std::string sPath, std::vector<std::string> files)
{
    if(access(sPath.c_str(), 0) != 0)
        return;
    
    struct _finddata_t fileinfo;
    std::string tmp;
    auto hFile = _findfirst(tmp.assign(sPath).append("\\*").c_str(), &fileinfo);
    if(hFile != -1)
    {
        do
        {
            if(fileinfo.attrib & _A_SUBDIR)
            {
                if(strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    GetFiles(tmp.assign(sPath).append("\\").append(fileinfo.name), files);
            }
            else
            {
                files.push_back(sPath+"\\"+fileinfo.name);
            }
        }while(_findnext(hFile, &fileinfo) == 0)
        _findclose(hFile);
    }
}

bool FileExist(const char* sFilePath)
{
    struct stat buffer;
    return (stat(sFilePath, &buffer)==0);
}

char* LoadFile(const char* sFilePath)
{
    if(!FileExist(sFilePath))
        return NULL;
            
    std::ifstream infile;
    infile.open(sFilePath);
    infile.seekg(0, std::ios::end);    
    auto length = infile.tellg();
    infile.seek(0, std::ios::beg);
    char* buffer = new char[length[;
    infile.read(buffer, length);
    infile.close();
    //remove(sFilePath);
}

void StartEXE(const char* sFilePath, const char* sCommandLine)
{
    if(!FileExist(sFilePath))
        return NULL;

    PROCESS_INFORMATION pi;
    STARTUPINFO si = {sizeof(si)};
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = FALSE;
    auto sCmdLine = _tcsdup(sCommandLine);

    if(CreateProcess(sFilePath, sCmdLine,
    NULL, NULL, FALSE, 0, NULL, NULL,
    &si, &pi))
    {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
    }
}

int CallFunc(const char* sDLLPath, const char* sFuncName, const char* param)
{
     if(!FileExist(sDLLPath))
        return NULL;

    HINSTANCE hIns = LoadLibrary(sDLLPath);
    if(hIns)
    {
        typedef int(*TestFunc)(const char* sText);
        TestFunc func = (TestFunc)GetProcAddress(hIns, sFuncName);
        if(func)
        {
            return func(param);
        }
    }

    return -1;
}
*/