#include "Directory.h"

File Directory::getFile(int index) const
{   
    int a=files.size();
    if (index >= 0 && index < a) {
        return files[index];
    }
    
    return File();
}

size_t Directory::directorySize() const
{   
    size_t s=0;
    int a=files.size();
    for (int i=0;i<a;i++){
        s += files.at(i).fileSize();
    }
    return s;
}

bool Directory::isEmpty() const
{
    return files.empty();
}
size_t Directory::numFiles() const
{
    return files.size();
}
/**?7****/
void Directory::newFile(const File &file)
{
    files.push_back(file);
}

void Directory::removeFile(int index)
{   
    int a=files.size();
    if (index >= 0 && index < a) {
        files.erase(files.begin() + index);
    }
}

void Directory::removeFile(File &file)
{

    int a=files.size();
    for (int i=0;i<a;i++){
        if(files[i]==file){
            files.erase(files.begin() + i);
            break;
        }
    }

}

void Directory::removeBiggestFile()
{   
    size_t m=0;
    int j;
    if (!files.empty()) {
        for(int i=0;i<files.size();i++){
            if(files[i].fileSize()>m){
                m=files[i].fileSize();
                j=i;
            }
        }
        files.erase(files.begin() + j);
    }
}
