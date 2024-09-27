#include "File.h"

Block File::getBlock(int index) const
{
    Block a;
	if (index < blocks.getSize() && blocks.getNodeAtIndex(index)->data.getContent() != "") {
        return blocks.getNodeAtIndex(index)->data;
    }
    else{
        return a;
    }
}

size_t File::fileSize() const
{
	size_t size = 0;
	int s;
	s = blocks.getSize();
	
    for (int i = 0; i < s; i++) {
        size += blocks.getNodeAtIndex(i)->data.getSize();
    }
    return size;
}

int File::numBlocks() const
{
return blocks.getSize();
}

bool File::isEmpty() const
{

	return blocks.isEmpty();
}
bool File::operator==(const File &rhs) const
{
    int s;
    s=blocks.getSize();
    
    if(s!=rhs.blocks.getSize()){
        return false;
    }
    
    for(int i=0;i<s;i++){
        if (!(blocks.getNodeAtIndex(i)->data==rhs.blocks.getNodeAtIndex(i)->data)){
            return false;
        }
    }
    
    return true;
}

void File::newBlock(const Block &block)
{
	blocks.append(block);
}
/*BUNDAN SONRASI PROBLEMLİ,öncesi çalışıyor*/
/*Değişiklik*/
void File::removeBlock(int index)
{

    if (index >= 0 && index < blocks.getSize()) {
        blocks.removeNodeAtIndex(index);
    }
}

void File::mergeBlocks(int sourceIndex, int destIndex)
{
    if (sourceIndex > -1 && sourceIndex < blocks.getSize() && destIndex > -1 && destIndex < blocks.getSize()) {

        blocks.mergeNodes(sourceIndex,destIndex);

    }
}


void File::printContents() const{
	if(isEmpty()){
		std::cout << "File is empty" << std::endl;
	}
	else{
		for(int i = 0; i < blocks.getSize(); i++){
			Node<Block> *block = blocks.getNodeAtIndex(i);
			std::cout << block->data.getContent();
		}
		std::cout << std::endl << fileSize() << std::endl;
	}
}
