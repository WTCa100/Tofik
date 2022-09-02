#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>

const std::string FileOutputPathXLSX = "xlsxRawFiles/";
const std::string FileOutputPathCSV = "csvOutFiles/";
const std::string strBannableChars = "\"/\\<>?:*|";
const std::string strSemiBannableChars = "-_., \'";

class Spam
{
    private:
        int nQuantity;
        std::string strFileName;
        std::string strFileExtention;
        std::string strLocation;
        std::string strFinalFileName;
        std::string CreateFinalName(std::string Name, std::string Ext);
        std::string strP;
    public:
        Spam(int nQty, std::string strName, std::string strExt, std::string strPath);
        void CreateExtendedFiles();
};

void Spam::CreateExtendedFiles()
{
    if(this->strP == "-x")
    {
        for(int i = 0; i < this->nQuantity; i++)
        {
            
            std::ofstream tmpFile;
            i == 0 ? tmpFile.open(FileOutputPathXLSX + this->strFinalFileName) : tmpFile.open(FileOutputPathXLSX + this->strFinalFileName + '(' + std::to_string(i+1) + ')');
            tmpFile.close();
        }
    }
    else
    {
         for(int i = 0; i < this->nQuantity; i++)
        {
            std::ofstream tmpFile;
            i == 0 ? tmpFile.open(FileOutputPathCSV + this->strFinalFileName) : tmpFile.open(FileOutputPathCSV + this->strFinalFileName + '(' + std::to_string(i+1) + ')');
            tmpFile.close();
        }       
    }
    
}

std::string Spam::CreateFinalName(std::string Name, std::string Ext)
{
    return Name + '.' + Ext;
}
Spam::Spam(int nQty, std::string strName, std::string strExt, std::string strPath)
{
    this->nQuantity = nQty;
    this->strFileName = strName;
    this->strFileExtention = strExt;
    this->strLocation = strPath;
    this->strP = strPath;
    this->strFinalFileName = this->CreateFinalName(this->strFileName, this->strFileExtention);
}
bool bCheckIfNumber(std::string strCheck);
bool bCheckExtNames(std::string strCheckMyExt);
bool bCheckName(std::string strCheckMyName);
bool bCheckpath(std::string strCheckMyPath);
void HelpMe();

int main(int argc, char** argv)
{
    if(argc == 2 && static_cast<std::string> (argv[1]) == "-h")
    {
        HelpMe();
        return 0;
    }
    if(argc != 5)
    {
        printf("Usage: FileSpammer.exe [Number of files] [Name of the files] [Files extention] -[path location]"); 
        printf("\nFor more information type FileSpammer.exe -h");
        return 0;
    }
    if(!bCheckIfNumber(static_cast<std::string> (argv[1])))
    {
        printf("Error: The first parametr must be an non-zero intiger!\n");
        return 0;
    }
    if(std::stoi(static_cast<std::string>(argv[1])) <= 0)
    {
        printf("Error: The first parametr must be an non-zero intiger!\n");
        return 0;        
    }
    if(!bCheckName(static_cast<std::string> (argv[2])))
    {
        printf("Error: The name cannot containt the following characters: << ");
        for(auto i: strBannableChars) std::cout<<i;
        printf(" >>\n");
        printf("Or end with the following characters: << ");
        for(auto i: strSemiBannableChars) std::cout << i;
        printf(" >>");
        return 0;
    }
    if(!bCheckExtNames(static_cast<std::string> (argv[3])))
    {
        printf("Error: The extention cannot containt the following characters: <<");
        for(auto i: strBannableChars) std::cout << i;
        for(auto i: strSemiBannableChars) std::cout << i;
        printf(" >>\n");
        return 0;
    }
    if(!bCheckpath(static_cast<std::string> (argv[4])))
    {
        std::cout << "Error: " << argv[4] << " is not recognized as any avilable path modes\n";
        return 0;
    }
    std::cout << "Creating "<< argv[1] << " files...\n";
    Spam* MakeItRain = new Spam(std::stoi(static_cast<std::string>(argv[1])), static_cast<std::string>(argv[2]), static_cast<std::string>(argv[3]), static_cast<std::string>(argv[4]));
    MakeItRain->CreateExtendedFiles();
    delete MakeItRain;
    std::cout << "Files have been created!\n";
    return 0;
}

bool bCheckIfNumber(std::string strCheck)
{
    if(strCheck.empty())
        return false;
    for(int i = 0; i < strCheck.size(); i++)
    {
        if(!isdigit(strCheck[i]))
            return false;
        continue;
    }
    return true;
}

bool bCheckName(std::string strCheckMyName)
{
    if(strCheckMyName.empty()) return false;
    // Check if the name have any bannable character in it
    for(int i = 0; i < strBannableChars.size(); i++)
    {
        size_t SearchFor = strCheckMyName.find(strBannableChars[i]);
        if (SearchFor != std::string::npos)
        {
            return false;
        }
    }
    // If not procede to check if the last character is not either semibannable character
    // We do not need to check the bannable char table since we found none in the string
    for(int i = 0; i < strSemiBannableChars.size(); i++)
    {
        if(strCheckMyName.back() == strSemiBannableChars[i])
        {
            return false;
        }
    }
    
    return true;
}

bool bCheckExtNames(std::string strCheckMyExt)
{
    if(strCheckMyExt.empty()) return false;
    // Check if the name have any bannable character in it
    for(int i = 1; i < strBannableChars.size(); i++)
    {
        size_t SearchFor = strCheckMyExt.find(strBannableChars[i]);
        if(SearchFor != std::string::npos)
            return false;
    }
    for(int i = 1; i < strSemiBannableChars.size(); i++)
    {
        size_t SearchFor = strCheckMyExt.find(strSemiBannableChars[i]);
        if(SearchFor != std::string::npos)
            return false;
    }
    return true;
}

bool bCheckpath(std::string strCheckMyPath)
{
    if(strCheckMyPath != "-x" && strCheckMyPath != "-c")
        return false;
    return true;
}

void HelpMe()
{
    printf("Welcome to FileSpammer!\n\n");
    printf("Filespammer was designed for usage of creating multiple files into either %s or %s dir really fast.\n", FileOutputPathXLSX.c_str(), FileOutputPathCSV.c_str());
    printf("The usage of this program is simple:\n");
    printf(".\\FileSpammer.exe [Ammount of files to create] [File Name] [File Extention] [Path]\n\n");
    printf("Avilalbe Paths are:\n");
    printf("-x \t -%s\n", FileOutputPathXLSX.c_str());
    printf("-c \t %s\n", FileOutputPathCSV.c_str());
    printf("Basically you can create N completly blank (and thus without it's meta-data) files.\n\n");
    printf("In order to correctly specify the extention and filename you are forbiden in providing the following\n");
    printf("characters as file name and extention:\n<< ");
    for(auto i: strBannableChars) std::cout << i;
    for(auto i: strSemiBannableChars) std::cout << i;
    printf(" >>\n\n");
    printf("Please also note that the program is a very simple spammer and does not support creating files with complex extentions.");
    printf("Have a great day!\n");
}